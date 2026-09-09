// Shared helpers for the fp16 testbenches.
//
// h2r: fp16 bits -> real. A zero exponent reads as 0.0.
// r2h: real -> fp16 bits, round to nearest. The value must fit in the
//      normal fp16 range (2^-14 .. 65504). Inputs outside the range give
//      a wrong code, so keep the test values inside it.
// fp_close: compare a result with a reference. The design truncates, so
//      each step can lose one ulp. The tolerance is 4 ulp of the
//      reference, plus one small absolute term for results near zero.
package fp16_tb_pkg;
    function automatic real h2r(input logic [15:0] h);
        integer e;
        real m;
        e = h[14:10];
        if (e == 0) return 0.0;
        m = 1.0 + h[9:0] / 1024.0;
        return (h[15] ? -1.0 : 1.0) * m * (2.0 ** (e - 15));
    endfunction

    function automatic logic [15:0] r2h(input real r);
        real m;
        integer e, frac;
        logic s;
        if (r == 0.0) return 16'h0000;
        s = (r < 0.0);
        m = s ? -r : r;
        e = 15;
        while (m >= 2.0) begin m = m / 2.0; e = e + 1; end
        while (m < 1.0)  begin m = m * 2.0; e = e - 1; end
        frac = $rtoi((m - 1.0) * 1024.0 + 0.5);
        if (frac == 1024) begin frac = 0; e = e + 1; end
        return {s, e[4:0], frac[9:0]};
    endfunction

    function automatic real ulp(input real x);
        real m;
        integer e;
        m = (x < 0.0) ? -x : x;
        if (m < 2.0 ** -14) return 2.0 ** -24;
        e = 0;
        while (m >= 2.0) begin m = m / 2.0; e = e + 1; end
        while (m < 1.0)  begin m = m * 2.0; e = e - 1; end
        return 2.0 ** (e - 10);
    endfunction

    function automatic bit fp_close(input real got, input real want);
        real d, tol;
        d = got - want;
        if (d < 0.0) d = -d;
        tol = 4.0 * ulp(want) + 2.0 ** -12;
        return d <= tol;
    endfunction
endpackage
