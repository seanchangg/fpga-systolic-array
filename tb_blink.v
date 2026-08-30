// Testbench for blink.v. Not for synthesis; the Makefile keeps
// tb_*.v files out of the source list.
`timescale 1ns/1ps
module tb_blink;
    reg  clk = 0;
    reg  button = 1;          // not pushed
    wire [4:0] led;

    blink dut (.clk(clk), .button(button), .led(led));

    always #10 clk = ~clk;    // 50 MHz

    initial begin
        $dumpfile("tb_blink.fst");
        $dumpvars(0, tb_blink);
        // 2^23 cycles show led[4:1] in motion. A full led[0]
        // period needs 2^26 cycles; that run takes minutes.
        #(20 * 8_388_608);
        $display("led = %b at t=%0t", led, $time);
        $finish;
    end
endmodule
