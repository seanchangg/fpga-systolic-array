`timescale 1ns/1ps
// Self-checking testbench for `array` in systolic.sv.
//
// Each case holds A, B, C for one full 10-tick schedule of `count`, then
// compares every out word with A*B + C computed in reals. Element order is
// row-major, the same as the design: index = row*2 + col.
//
// The inputs change at the negative edge when count == 0, so the sample
// points at count 0, 3 and 6 all see the same problem. The four outputs
// are all valid when count returns to 0.
module tb_array_hard;
    import fp16_tb_pkg::*;

    logic clk = 0;
    logic [15:0] a[3:0];
    logic [15:0] b[3:0];
    logic [15:0] c[3:0];
    logic [15:0] out[3:0];
    array dut (.clk(clk), .a(a), .b(b), .c(c), .out(out));
    always #10 clk = ~clk;

    real ra[3:0], rb[3:0], rc[3:0];
    integer n_pass = 0, n_fail = 0;

    task automatic set_a(input real x0, x1, x2, x3);
        ra[0] = x0; ra[1] = x1; ra[2] = x2; ra[3] = x3;
    endtask
    task automatic set_b(input real x0, x1, x2, x3);
        rb[0] = x0; rb[1] = x1; rb[2] = x2; rb[3] = x3;
    endtask
    task automatic set_c(input real x0, x1, x2, x3);
        rc[0] = x0; rc[1] = x1; rc[2] = x2; rc[3] = x3;
    endtask

    task automatic run_case(input string name);
        real want[3:0], got[3:0];
        bit ok, all_ok;
        integer r, k, i;

        // Line up with the start of a schedule, then apply the problem.
        @(negedge clk);
        while (dut.count != 0) @(negedge clk);
        for (i = 0; i < 4; i = i + 1) begin
            a[i] = r2h(ra[i]); b[i] = r2h(rb[i]); c[i] = r2h(rc[i]);
        end

        // One full pass: count 0 .. 9, then back to 0.
        repeat (10) @(negedge clk);

        for (r = 0; r < 2; r = r + 1)
            for (k = 0; k < 2; k = k + 1) begin
                want[r*2+k] = rc[r*2+k];
                for (i = 0; i < 2; i = i + 1)
                    want[r*2+k] = want[r*2+k] + ra[r*2+i] * rb[i*2+k];
            end

        all_ok = 1;
        for (i = 0; i < 4; i = i + 1) begin
            got[i] = h2r(out[i]);
            ok = (^out[i] !== 1'bx) && fp_close(got[i], want[i]);
            if (!ok) all_ok = 0;
        end
        if (all_ok) n_pass = n_pass + 1; else n_fail = n_fail + 1;

        $display("%s  %s", all_ok ? "PASS" : "FAIL", name);
        $display("      A=[%0.4f %0.4f; %0.4f %0.4f]  B=[%0.4f %0.4f; %0.4f %0.4f]  C=[%0.4f %0.4f; %0.4f %0.4f]",
                 ra[0], ra[1], ra[2], ra[3], rb[0], rb[1], rb[2], rb[3], rc[0], rc[1], rc[2], rc[3]);
        $display("      want=[%0.4f %0.4f; %0.4f %0.4f]", want[0], want[1], want[2], want[3]);
        $display("      got=[%0.4f %0.4f; %0.4f %0.4f]  raw=[%h %h %h %h]",
                 got[0], got[1], got[2], got[3], out[0], out[1], out[2], out[3]);
        if (!all_ok)
            for (i = 0; i < 4; i = i + 1)
                if (!((^out[i] !== 1'bx) && fp_close(got[i], want[i])))
                    $display("      out[%0d] wrong: got %0.4f, want %0.4f", i, got[i], want[i]);
    endtask

    function automatic real rand_val(input integer lo, input integer hi);
        logic [15:0] h;
        h[15]    = $urandom % 2;
        h[14:10] = lo + ($urandom % (hi - lo + 1));
        h[9:0]   = $urandom;
        return h2r(h);
    endfunction

    integer i, j;
    initial begin
        $dumpfile("tb_array_hard.fst");
        $dumpvars(0, tb_array_hard);
        for (i = 0; i < 4; i = i + 1) begin
            $dumpvars(0, a[i], b[i], c[i], out[i]);
            $dumpvars(0, dut.a_next[i], dut.c_next[i], dut.out_next[i]);
        end

        // 1. The original sanity case: A*I + 0 = A.
        set_a(1, 2, 3, 4);  set_b(1, 0, 0, 1);  set_c(0, 0, 0, 0);
        run_case("A * I, C = 0");

        // 2. Full B, so both PEs of a column give a nonzero term.
        set_a(1, 2, 3, 4);  set_b(5, 6, 7, 8);  set_c(0, 0, 0, 0);
        run_case("full B, C = 0  (want [19 22; 43 50])");

        // 3. Only C: A = 0, so out must equal C.
        set_a(0, 0, 0, 0);  set_b(5, 6, 7, 8);  set_c(1, 2, 3, 4);
        run_case("A = 0, out = C");

        // 4. Diagonal B and nonzero C: one product per output, plus C once.
        set_a(1, 2, 3, 4);  set_b(1, 0, 0, 1);  set_c(10, 20, 30, 40);
        run_case("A * I + C");

        // 5. Fractions.
        set_a(0.5, 0.25, 1.5, 0.75);  set_b(2, 0.125, 4, 1.5);  set_c(0.5, 0.5, 0.5, 0.5);
        run_case("fractions");

        // 6. Negative values in every operand.
        set_a(-1, 2, 3, -4);  set_b(5, -6, -7, 8);  set_c(1, -1, -1, 1);
        run_case("mixed signs");

        // 7. Cancellation to exactly zero.
        set_a(1, -1, 2, -2);  set_b(3, 3, 3, 3);  set_c(0, 0, 0, 0);
        run_case("cancel to zero");

        // 8. Large and small values, so the adders must align exponents.
        set_a(1024, 0.001, 0.5, 2000);  set_b(1, 0.5, 0.25, 1);  set_c(0.5, -0.5, 1000, -1000);
        run_case("exponent alignment");

        // 9. Products that cross 2.0 with negative signs.
        set_a(-1.5, -1.5, 1.5, 1.5);  set_b(1.5, -1.5, 1.5, -1.5);  set_c(0, 0, 0, 0);
        run_case("neg products >= 2");

        // 10. Random problems.
        for (j = 0; j < 40; j = j + 1) begin
            for (i = 0; i < 4; i = i + 1) begin
                ra[i] = rand_val(10, 20);
                rb[i] = rand_val(10, 20);
                rc[i] = rand_val(10, 24);
            end
            if (j % 5 == 0) set_c(0, 0, 0, 0);
            run_case($sformatf("random %0d", j));
        end

        $display("---- array summary: %0d pass, %0d fail ----", n_pass, n_fail);
        $finish;
    end
endmodule
