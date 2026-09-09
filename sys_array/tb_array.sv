`timescale 1ns/1ps
// Testbench for `array` in systolic.sv.
//
// Drives one 2x2 problem, then follows the 10-tick schedule that `count`
// runs, and prints every PE output and every `out` word per tick, decoded
// from fp16 to a real. The expected result is printed first, so a bad tick
// stands out in the log.
//
// Indices are [row][col]. The bias `c` is a full 2x2 matrix. The design
// loads c[r][k] into c_in[k] on the tick that row r enters column k, so
// the reference is out[r][k] = c[r][k] + a[r][0]*b[0][k] + a[r][1]*b[1][k].
module tb_array;
    logic clk = 0;
    logic [15:0] a[2][2];
    logic [15:0] b[2][2];
    logic [15:0] c[2][2];
    logic [15:0] out[2][2];

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

    // The reference: out = A*B + C, element for element.
    real expect_out[2][2];
    task compute_expected;
        integer r, k, i;
        begin
            for (r = 0; r < 2; r = r + 1)
                for (k = 0; k < 2; k = k + 1) begin
                    expect_out[r][k] = h2r(c[r][k]);
                    for (i = 0; i < 2; i = i + 1)
                        expect_out[r][k] = expect_out[r][k]
                            + h2r(a[r][i]) * h2r(b[i][k]);
                end
            $display("expected: [%0.3f %0.3f ; %0.3f %0.3f]",
                expect_out[0][0], expect_out[0][1],
                expect_out[1][0], expect_out[1][1]);
        end
    endtask

    // One line per tick: the counter, the four PE outputs, the four outs.
    task show_tick;
        $display("count=%0d  pe=[%0.3f %0.3f ; %0.3f %0.3f]  out=[%0.3f %0.3f ; %0.3f %0.3f]",
            dut.count,
            h2r(dut.out_next[0][0]), h2r(dut.out_next[0][1]),
            h2r(dut.out_next[1][0]), h2r(dut.out_next[1][1]),
            h2r(out[0][0]), h2r(out[0][1]),
            h2r(out[1][0]), h2r(out[1][1]));
    endtask

    integer t;
    initial begin
        $dumpfile("tb_array.fst");
        $dumpvars(0, tb_array);
        // Icarus does not dump array words unless each one is named with
        // a constant index. A loop index or a whole array is rejected.
        $dumpvars(0, a[0][0], a[0][1], a[1][0], a[1][1]);
        $dumpvars(0, b[0][0], b[0][1], b[1][0], b[1][1]);
        $dumpvars(0, c[0][0], c[0][1], c[1][0], c[1][1]);
        $dumpvars(0, out[0][0], out[0][1], out[1][0], out[1][1]);
        $dumpvars(0, dut.c_in[0], dut.c_in[1]);
        $dumpvars(0, dut.a_next[0][0], dut.a_next[0][1],
                     dut.a_next[1][0], dut.a_next[1][1]);
        $dumpvars(0, dut.out_next[0][0], dut.out_next[0][1],
                     dut.out_next[1][0], dut.out_next[1][1]);

        // A = [1 2 ; 3 4], B = I, C = 0  ->  A*B + C = A
        a[0][0] = F1; a[0][1] = F2;
        a[1][0] = F3; a[1][1] = F4;
        b[0][0] = F1; b[0][1] = F0;
        b[1][0] = F0; b[1][1] = F1;
        c[0][0] = F0; c[0][1] = F0;
        c[1][0] = F0; c[1][1] = F0;
        compute_expected();

        // Line up with the start of a schedule, then watch two full passes.
        @(posedge clk);
        while (dut.count != 0) @(posedge clk);
        for (t = 0; t < 20; t = t + 1) begin
            @(negedge clk);   // sample after the edge settles
            show_tick();
        end

        $display("final out: [%0.3f %0.3f ; %0.3f %0.3f]",
            h2r(out[0][0]), h2r(out[0][1]),
            h2r(out[1][0]), h2r(out[1][1]));
        $finish;
    end
endmodule
