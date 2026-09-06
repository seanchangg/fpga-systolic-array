 `timescale 1ns/1ps
  module tb_systolic;
      reg clk = 0;
      reg [15:0] a, b, c;
      wire [15:0] out;
      processing_unit dut (.clk(clk), .a(a), .b(b), .c(c), .out(out));
      always #10 clk = ~clk;                       // 50 MHz
      initial begin
          $dumpfile("tb_systolic.fst"); $dumpvars(0, tb_systolic);
          a = 16'h3E00; b = 16'h3E00; c = 16'b0011110000000000; #80;    // 1.5 * 1.5 + 1 = 3.25
          $display("1.5*1.5+1 -> out=%h", out);
          a = 16'h4200; b = 16'h3E00; c=16'b0100100100000000; #80;    // 3.0 * 1.5 +10 = 14.5
          $display("3.0*1.5+10 -> out=%h", out);
          $finish;
      end
  endmodule
