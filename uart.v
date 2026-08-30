// UART register bridge on the MAX 10 FPGA Development Kit (DK-DEV-10M50-A).
//
// This is the bring-up project for the serial link. It holds no compute.
// It proves the link works, so that later designs sit behind a bridge
// you already trust.
//
// Connect the second mini-USB port (J11, marked USB to UART). The Mac
// then shows a /dev/cu.usbserial-* device at 115200 baud, 8N1.
//
// Register map, all 32 bits wide:
//   0x0000  ID       RO  0x55415254, the ASCII for "UART"
//   0x0004  SCRATCH  RW  free, use it to prove a write lands
//   0x0008  LEDS     RW  bits [3:0] drive LED3..LED0
//   0x000C  STATUS   RO  bit0 = 1 while USER_PB0 is pushed
//   0x0010  UPTIME   RO  free-run count of 50 MHz clocks
//   0x0014  WRCOUNT  RO  number of writes the bridge accepted
//   other            RO  0xDEADBEEF
//
// LED4 blinks by itself, about three times per second. It says the
// design is loaded and the clock runs, with no host involved.
module uart #(
    parameter CLKS_PER_BIT = 434     // 50 MHz / 115200 baud
)(
    input  wire       clk,           // CLK_50_MAX10, PIN_M9, 50 MHz
    input  wire       button,        // USER_PB0, low when you push it
    input  wire       rxd,           // board net UART_TX, PIN_W18, FT232R drives it
    output wire       txd,           // board net UART_RX, PIN_Y19, the FPGA drives it
    output wire [4:0] led            // USER_LED, on when low
);
    wire [15:0] addr;
    wire [31:0] wdata;
    wire        we;
    reg  [31:0] rdata;

    uart_regs #(.CLKS_PER_BIT(CLKS_PER_BIT)) u_bridge (
        .clk(clk), .rx(rxd), .tx(txd),
        .addr(addr), .wdata(wdata), .we(we), .rdata(rdata));

    reg [31:0] scratch = 32'h0000_0000;
    reg [3:0]  leds    = 4'h0;
    reg [31:0] uptime  = 32'h0000_0000;
    reg [31:0] wrcount = 32'h0000_0000;
    reg [1:0]  btn_s   = 2'b11;

    // Write side.
    always @(posedge clk) begin
        uptime <= uptime + 32'd1;
        btn_s  <= {btn_s[0], button};

        if (we) begin
            wrcount <= wrcount + 32'd1;
            case (addr)
                16'h0004: scratch <= wdata;
                16'h0008: leds    <= wdata[3:0];
                default:  ;                       // a write elsewhere is ignored
            endcase
        end
    end

    // Read side. This must stay combinational.
    always @* begin
        case (addr)
            16'h0000: rdata = 32'h5541_5254;
            16'h0004: rdata = scratch;
            16'h0008: rdata = {28'h000_0000, leds};
            16'h000c: rdata = {31'h0000_0000, ~btn_s[1]};
            16'h0010: rdata = uptime;
            16'h0014: rdata = wrcount;
            default:  rdata = 32'hdead_beef;
        endcase
    end

    // 2^24 clocks at 50 MHz is about 0.34 s.
    assign led = ~{uptime[24], leds};
endmodule
