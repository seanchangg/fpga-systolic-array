`timescale 1ns/1ps
// Self-checking testbench for `processing_unit` in systolic.sv.
//
// Each case applies a, b, c at the negative edge, waits for the two-cycle
// pipeline, and compares out with a*b+c in reals. The directed cases
// cover: signs, products above and below 2.0, exact cancellation,
// exponent alignment, small values that shift out, and zeros. The random
// cases use exponents 8..22, so every product and sum stays in range.
module tb_pe_hard;
    import fp16_tb_pkg::*;

    logic clk = 0;
    logic [15:0] a, b, c;
    logic [15:0] out;
    processing_unit dut (.clk(clk), .a(a), .b(b), .c(c), .out(out));
    always #10 clk = ~clk;

    integer n_pass = 0, n_fail = 0;

    task automatic run_case(input string name, input real ra, input real rb, input real rc);
        real want, got;
        bit ok;
        @(negedge clk);
        a = r2h(ra); b = r2h(rb); c = r2h(rc);
        repeat (2) @(posedge clk);
        @(negedge clk);
        want = ra * rb + rc;
        got = h2r(out);
        ok  = (^out !== 1'bx) && fp_close(got, want);
        if (ok) n_pass = n_pass + 1; else n_fail = n_fail + 1;
        $display("%s  %-34s  a=%h b=%h c=%h  out=%h  got=%0.5f  want=%0.5f",
                 ok ? "PASS" : "FAIL", name, a, b, c, out, got, want);
    endtask

    // One random fp16 value: sign random, exponent lo..hi, mantissa random.
    function automatic real rand_val(input integer lo, input integer hi);
        logic [15:0] h;
        h[15]    = $urandom % 2;
        h[14:10] = lo + ($urandom % (hi - lo + 1));
        h[9:0]   = $urandom;
        return h2r(h);
    endfunction

    integer i;
    real ra, rb, rc;
    initial begin
        $dumpfile("tb_pe_hard.fst");
        $dumpvars(0, tb_pe_hard);

        run_case("1.5*1.5+1",            1.5,     1.5,    1.0);
        run_case("3*1.5+10",             3.0,     1.5,    10.0);
        run_case("neg a, product >= 2", -1.5,     1.5,    0.0);
        run_case("neg b, product >= 2",  2.0,    -3.0,    0.0);
        run_case("neg a, product < 2",  -1.25,    1.25,   0.0);
        run_case("both neg",            -2.5,    -2.5,    0.0);
        run_case("neg c",                2.0,     2.0,   -1.0);
        run_case("exact cancel to 0",    2.0,     3.0,   -6.0);
        run_case("cancel, c larger",     2.0,     3.0,   -8.0);
        run_case("cancel, c smaller",    2.0,     3.0,   -5.5);
        run_case("align: big c",         1.0,     1.0,    1000.0);
        run_case("align: big product",   40.0,    25.0,   -999.0);
        run_case("c shifts out",         1.0,     1.0,    0.0001);
        run_case("product shifts out",   0.001,   0.1,    100.0);
        run_case("a zero",               0.0,     7.0,   -2.5);
        run_case("b zero",              -3.0,     0.0,    5.0);
        run_case("all zero",             0.0,     0.0,    0.0);
        run_case("product exactly 1",    4.0,     0.25,   0.0);
        run_case("fractions",            0.375,   0.75,   0.0625);
        run_case("small values",         0.03125, 0.0625, 0.001953125);
        run_case("large values",         200.0,   200.0,  1000.0);
        run_case("sum crosses power of 2", 1.5,   1.0,    0.5);
        run_case("sub crosses power of 2", 1.0,   1.0,   -0.5);
        run_case("borrow many bits",     1.0,     1.0,   -0.9990234375);

        for (i = 0; i < 300; i = i + 1) begin
            ra = rand_val(8, 22);
            rb = rand_val(8, 22);
            rc = rand_val(8, 29);
            if (i % 7 == 0) rc = 0.0;
            if (i % 11 == 0) ra = 0.0;
            run_case($sformatf("random %0d", i), ra, rb, rc);
        end

        $display("---- PE summary: %0d pass, %0d fail ----", n_pass, n_fail);
        $finish;
    end
endmodule
