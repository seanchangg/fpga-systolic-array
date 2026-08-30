// Acceptance test for the UART register bridge, against the real board.
// It runs the same checks as tb_uart.v.
//
//   make && ./probe                    (finds the device by itself)
//   make && ./probe /dev/cu.usbserial-XXXXXXXX
#include "fpga.hpp"

#include <cstdio>
#include <string>

namespace {

constexpr uint16_t REG_ID      = 0x0000;
constexpr uint16_t REG_SCRATCH = 0x0004;
constexpr uint16_t REG_LEDS    = 0x0008;
constexpr uint16_t REG_STATUS  = 0x000c;
constexpr uint16_t REG_UPTIME  = 0x0010;
constexpr uint16_t REG_WRCOUNT = 0x0014;

int errors = 0;

void check(const char* name, uint32_t got, uint32_t want) {
    if (got == want) {
        std::printf("  PASS  %-24s 0x%08x\n", name, got);
    } else {
        std::printf("  FAIL  %-24s 0x%08x, expected 0x%08x\n", name, got, want);
        ++errors;
    }
}

}  // namespace

int main(int argc, char** argv) {
    try {
        Fpga fpga(argc > 1 ? std::string(argv[1]) : std::string());
        std::printf("uart register bridge on %s\n", fpga.path().c_str());

        check("ID", fpga.read_reg(REG_ID), 0x55415254u);

        fpga.write_reg(REG_SCRATCH, 0xdeadbeefu);
        check("SCRATCH", fpga.read_reg(REG_SCRATCH), 0xdeadbeefu);

        fpga.write_reg(REG_SCRATCH, 0x01234567u);
        check("SCRATCH rewritten", fpga.read_reg(REG_SCRATCH), 0x01234567u);

        fpga.write_reg(REG_LEDS, 0x0000000au);
        check("LEDS", fpga.read_reg(REG_LEDS), 0x0000000au);
        std::printf("        LED3 and LED1 are now on. LED4 keeps blinking.\n");

        check("unmapped address", fpga.read_reg(0x00f0), 0xdeadbeefu);

        const uint32_t t0 = fpga.read_reg(REG_UPTIME);
        const uint32_t t1 = fpga.read_reg(REG_UPTIME);
        if (t1 != t0) {
            std::printf("  PASS  %-24s advanced by %u clocks\n", "UPTIME", t1 - t0);
        } else {
            std::printf("  FAIL  %-24s did not advance\n", "UPTIME");
            ++errors;
        }

        std::printf("        WRCOUNT = %u, STATUS = 0x%08x (bit0 = button)\n",
                    fpga.read_reg(REG_WRCOUNT), fpga.read_reg(REG_STATUS));

        std::printf(errors == 0 ? "ALL TESTS PASSED\n" : "%d TEST(S) FAILED\n", errors);
        return errors == 0 ? 0 : 1;
    } catch (const std::exception& e) {
        std::fprintf(stderr, "error: %s\n", e.what());
        return 2;
    }
}
