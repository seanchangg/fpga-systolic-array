// Host side of the UART register bridge.
//
// Open /dev/cu.usbserial-*, not /dev/tty.usbserial-*. The tty device
// blocks until it sees carrier detect, and the board never asserts it.
#pragma once

#include <fcntl.h>
#include <glob.h>
#include <termios.h>
#include <unistd.h>

#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>

class Fpga {
public:
    // Pass a device path, or leave it empty to take the first match of
    // /dev/cu.usbserial-*.
    explicit Fpga(const std::string& device = "") {
        const std::string path = device.empty() ? find_device() : device;
        fd_ = ::open(path.c_str(), O_RDWR | O_NOCTTY);
        if (fd_ < 0)
            throw std::runtime_error("cannot open " + path + ": " + std::strerror(errno));
        path_ = path;

        termios t{};
        if (::tcgetattr(fd_, &t) != 0)
            throw std::runtime_error("tcgetattr failed");
        ::cfmakeraw(&t);
        ::cfsetispeed(&t, B115200);
        ::cfsetospeed(&t, B115200);
        t.c_cflag |= CLOCAL | CREAD;
        t.c_cflag &= ~CRTSCTS;          // the board has no flow control
        t.c_cc[VMIN]  = 0;
        t.c_cc[VTIME] = 10;             // 1 second read timeout
        if (::tcsetattr(fd_, TCSANOW, &t) != 0)
            throw std::runtime_error("tcsetattr failed");
        ::tcflush(fd_, TCIOFLUSH);
    }

    ~Fpga() { if (fd_ >= 0) ::close(fd_); }

    Fpga(const Fpga&)            = delete;
    Fpga& operator=(const Fpga&) = delete;

    const std::string& path() const { return path_; }

    void write_reg(uint16_t addr, uint32_t value) {
        const uint8_t cmd[7] = {
            'W',
            uint8_t(addr >> 8), uint8_t(addr),
            uint8_t(value >> 24), uint8_t(value >> 16),
            uint8_t(value >> 8),  uint8_t(value)
        };
        write_all(cmd, sizeof cmd);
    }

    uint32_t read_reg(uint16_t addr) {
        const uint8_t cmd[3] = {'R', uint8_t(addr >> 8), uint8_t(addr)};
        write_all(cmd, sizeof cmd);
        uint8_t r[4];
        read_all(r, sizeof r);
        return (uint32_t(r[0]) << 24) | (uint32_t(r[1]) << 16)
             | (uint32_t(r[2]) << 8)  |  uint32_t(r[3]);
    }

private:
    static std::string find_device() {
        glob_t g{};
        const int rc = ::glob("/dev/cu.usbserial-*", 0, nullptr, &g);
        if (rc != 0 || g.gl_pathc == 0) {
            ::globfree(&g);
            throw std::runtime_error(
                "no /dev/cu.usbserial-* device. Connect the mini-USB cable to "
                "J11, the port marked USB to UART, not the USB-Blaster port.");
        }
        std::string first = g.gl_pathv[0];
        ::globfree(&g);
        return first;
    }

    void write_all(const uint8_t* p, size_t n) {
        while (n > 0) {
            const ssize_t k = ::write(fd_, p, n);
            if (k <= 0) throw std::runtime_error("write failed");
            p += k;
            n -= size_t(k);
        }
    }

    void read_all(uint8_t* p, size_t n) {
        while (n > 0) {
            const ssize_t k = ::read(fd_, p, n);
            if (k <= 0)
                throw std::runtime_error("read timed out: the board sent nothing");
            p += k;
            n -= size_t(k);
        }
    }

    int         fd_ = -1;
    std::string path_;
};
