`timescale 1ns/1ps
// Testbench for `array` in systolic.sv.
//
// Drives one 2x2 problem, then follows the 10-tick schedule that `count`
// runs, and prints every PE output and every `out` word per tick, decoded
// from fp16 to a real. The expected A*B + C is printed first, so a bad tick
// stands out in the log.
//
// Element order is row-major, the same as the design: index = row*2 + col.
module tb_array;
    logic clk = 0;
    logic [15:0] a[3:0];
    logic [15:0] b[3:0];
    logic [15:0] c[3:0];
    logic [15:0] out[3:0];

    array dut (.clk(clk), .a(a), .b(b), .c(c), .out(out));
    always #10 clk = ~clk;   // 50 MHz

    // fp16 constants
    localparam [15:0] F0 = 16'h0000;   // 0.0
    localparam [15:0] F1 = 16'h3C00;   // 1.0
    localparam [15:0] F2 = 16'h4000;   // 2.0
    localparam [15:0] F3 = 16'h4200;   // 3.0
    localparam [15:0] F4 = 16'h4400;   // 4.0

    // fp16 bits -> real, for the log only. A zero exponent reads as 0.0.
    function real h2r(input [15:0] h);
        integer e;
        real m;
        begin
            e = h[14:10];
            if (e == 0) h2r = 0.0;
            else begin
                m = 1.0 + h[9:0] / 1024.0;
                h2r = (h[15] ? -1.0 : 1.0) * m * (2.0 ** (e - 15));
            end
        end
    endfunction

    // The reference: C = A*B + Cin, in reals.
    real expect_out[3:0];
    task compute_expected;
        integer r, k, i;
        begin
            for (r = 0; r < 2; r = r + 1)
                for (k = 0; k < 2; k = k + 1) begin
                    expect_out[r*2+k] = h2r(c[r*2+k]);
                    for (i = 0; i < 2; i = i + 1)
                        expect_out[r*2+k] = expect_out[r*2+k]
                            + h2r(a[r*2+i]) * h2r(b[i*2+k]);
                end
            $display("expected: [%0.3f %0.3f ; %0.3f %0.3f]",
                expect_out[0], expect_out[1], expect_out[2], expect_out[3]);
        end
    endtask

    // One line per tick: the counter, the four PE outputs, the four outs.
    task show_tick;
        $display("count=%0d  pe=[%0.3f %0.3f %0.3f %0.3f]  out=[%0.3f %0.3f %0.3f %0.3f]",
            dut.count,
            h2r(dut.out_next[0]), h2r(dut.out_next[1]),
            h2r(dut.out_next[2]), h2r(dut.out_next[3]),
            h2r(out[0]), h2r(out[1]), h2r(out[2]), h2r(out[3]));
    endtask

    integer t;
    initial begin
        $dumpfile("tb_array.fst");
        $dumpvars(0, tb_array);
        // Icarus does not dump array words unless they are named.
        for (t = 0; t < 4; t = t + 1) begin
            $dumpvars(0, a[t], b[t], c[t], out[t]);
            $dumpvars(0, dut.a_next[t], dut.out_next[t]);
        end
        for (t = 0; t< 2; t = t+1) begin
            $dumpvars(0, dut.c_in[t]);
        end

        // A = [1 2 ; 3 4], B = I, C = 0  ->  A*B + C = A
        a[0] = F1; a[1] = F2; a[2] = F3; a[3] = F4;
        b[0] = F1; b[1] = F0; b[2] = F0; b[3] = F1;
        c[0] = F0; c[1] = F0; c[2] = F0; c[3] = F0;
        compute_expected();

        // Line up with the start of a schedule, then watch two full passes.
        @(posedge clk);
        while (dut.count != 0) @(posedge clk);
        for (t = 0; t < 20; t = t + 1) begin
            @(negedge clk);   // sample after the edge settles
            show_tick();
        end

        $display("final out: [%0.3f %0.3f ; %0.3f %0.3f]",
            h2r(out[0]), h2r(out[1]), h2r(out[2]), h2r(out[3]));
        $finish;
    end
endmodule
