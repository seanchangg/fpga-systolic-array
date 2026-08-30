// Testbench for the UART register bridge. Not for synthesis; the
// Makefile keeps tb_*.v files out of the source list.
//
//   make simulate TB=tb_uart.v
//   surfer sim/tb_uart.fst
`timescale 1ns/1ps
module tb_uart;

    localparam integer CPB    = 434;          // clocks per bit at 115200 baud
    localparam integer BIT_NS = CPB * 20;     // one bit cell, 20 ns per clock

    reg  clk    = 1'b0;
    reg  button = 1'b1;                       // not pushed
    reg  rxd    = 1'b1;                       // idle high
    wire txd;
    wire [4:0] led;

    integer errors = 0;

    uart #(.CLKS_PER_BIT(CPB)) dut (
        .clk(clk), .button(button), .rxd(rxd), .txd(txd), .led(led));

    always #10 clk = ~clk;                    // 50 MHz

    // ---- line level ----------------------------------------------------

    task send_byte(input [7:0] b);
        integer i;
        begin
            rxd = 1'b0;                       // start
            #(BIT_NS);
            for (i = 0; i < 8; i = i + 1) begin
                rxd = b[i];                   // LSB first
                #(BIT_NS);
            end
            rxd = 1'b1;                       // stop
            #(BIT_NS);
        end
    endtask

    task recv_byte(output [7:0] b);
        integer i;
        begin
            @(negedge txd);                   // start bit
            #(BIT_NS + BIT_NS/2);             // middle of bit 0
            for (i = 0; i < 8; i = i + 1) begin
                b[i] = txd;
                #(BIT_NS);
            end
        end
    endtask

    // ---- command level -------------------------------------------------

    reg [7:0] rb0, rb1, rb2, rb3;

    task write_reg(input [15:0] a, input [31:0] d);
        begin
            send_byte("W");
            send_byte(a[15:8]);  send_byte(a[7:0]);
            send_byte(d[31:24]); send_byte(d[23:16]);
            send_byte(d[15:8]);  send_byte(d[7:0]);
        end
    endtask

    // The reply can start before the last address byte finishes on the
    // wire, so the receiver must already be waiting. Hence the fork.
    task read_reg(input [15:0] a, output [31:0] d);
        begin
            send_byte("R");
            send_byte(a[15:8]);
            fork
                send_byte(a[7:0]);
                begin
                    recv_byte(rb0); recv_byte(rb1);
                    recv_byte(rb2); recv_byte(rb3);
                end
            join
            d = {rb0, rb1, rb2, rb3};
        end
    endtask

    task check(input [255:0] name, input [31:0] got, input [31:0] want);
        begin
            if (got === want)
                $display("  PASS  %0s = 0x%08x", name, got);
            else begin
                $display("  FAIL  %0s = 0x%08x, expected 0x%08x", name, got, want);
                errors = errors + 1;
            end
        end
    endtask

    // ---- the test ------------------------------------------------------

    reg [31:0] v;

    initial begin
        $dumpfile("tb_uart.fst");
        $dumpvars(0, tb_uart);

        #(10 * BIT_NS);                       // let the line idle

        $display("uart register bridge");

        read_reg(16'h0000, v);
        check("ID", v, 32'h5541_5254);

        write_reg(16'h0004, 32'hdead_beef);
        read_reg(16'h0004, v);
        check("SCRATCH after write", v, 32'hdead_beef);

        write_reg(16'h0004, 32'h0123_4567);
        read_reg(16'h0004, v);
        check("SCRATCH after rewrite", v, 32'h0123_4567);

        write_reg(16'h0008, 32'h0000_000a);
        read_reg(16'h0008, v);
        check("LEDS", v, 32'h0000_000a);
        // The LEDs are active low, and led[4] is the free blink.
        if (led[3:0] !== 4'b0101) begin
            $display("  FAIL  led[3:0] = %b, expected 0101", led[3:0]);
            errors = errors + 1;
        end else
            $display("  PASS  led[3:0] = %b", led[3:0]);

        button = 1'b0;                        // push it
        #(2 * BIT_NS);
        read_reg(16'h000c, v);
        check("STATUS, button pushed", v, 32'h0000_0001);
        button = 1'b1;
        #(2 * BIT_NS);
        read_reg(16'h000c, v);
        check("STATUS, button released", v, 32'h0000_0000);

        read_reg(16'h0014, v);
        check("WRCOUNT", v, 32'h0000_0003);

        read_reg(16'h00f0, v);
        check("unmapped address", v, 32'hdead_beef);

        // A stray byte must not desynchronise the link.
        send_byte(8'h5a);
        read_reg(16'h0000, v);
        check("ID after a stray byte", v, 32'h5541_5254);

        if (errors == 0) $display("ALL TESTS PASSED");
        else             $display("%0d TEST(S) FAILED", errors);
        $finish;
    end

    initial begin
        #200_000_000;
        $display("TIMEOUT");
        $finish;
    end
endmodule
