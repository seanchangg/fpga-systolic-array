// Blink on the MAX 10 FPGA Development Kit (DK-DEV-10M50-A).
// clk = CLK_50_MAX10 on PIN_M9, 50 MHz.
// led[4:0] = USER_LED, on when low.
module blink (
    input  wire       clk,
    input  wire       button,   // USER_PB[0], low when you push it
    output wire [4:0] led
);
    reg [25:0] count = 0;
    always @(posedge clk) count <= count + 1;

    // One LED blinks. The others show the top counter bits.
    assign led = ~{count[25:22], count[25]};
endmodule
