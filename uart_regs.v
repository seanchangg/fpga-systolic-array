// Register bridge. It turns bytes on the serial line into reads and
// writes of a 16-bit address space.
//
// Wire protocol, all multi-byte fields big-endian:
//   write:  'W' addr[15:8] addr[7:0] data[31:24] .. data[7:0]   7 bytes, no reply
//   read:   'R' addr[15:8] addr[7:0]                            3 bytes, 4 byte reply
//
// A first byte that is neither 'W' nor 'R' is dropped. That lets the
// link resynchronise after noise without a reset.
module uart_regs #(
    parameter CLKS_PER_BIT = 434
)(
    input  wire        clk,
    input  wire        rx,
    output wire        tx,

    // Register file side. rdata must be a combinational function of addr.
    output reg  [15:0] addr  = 16'h0000,
    output reg  [31:0] wdata = 32'h0000_0000,
    output reg         we    = 1'b0,
    input  wire [31:0] rdata
);
    wire [7:0] rx_data;
    wire       rx_valid;
    reg  [7:0] tx_data = 8'h00;
    reg        tx_send = 1'b0;
    wire       tx_busy;

    uart_rx #(.CLKS_PER_BIT(CLKS_PER_BIT)) u_rx (
        .clk(clk), .rx(rx), .data(rx_data), .valid(rx_valid));

    uart_tx #(.CLKS_PER_BIT(CLKS_PER_BIT)) u_tx (
        .clk(clk), .data(tx_data), .send(tx_send), .tx(tx), .busy(tx_busy));

    reg [7:0] b [0:7];
    reg [2:0] n       = 3'd0;   // bytes of the current command already held
    reg       pending = 1'b0;   // a read is decoded, the reply is not started
    reg       sending = 1'b0;
    reg [1:0] txn     = 2'd0;
    reg [31:0] out    = 32'h0000_0000;

    integer i;
    initial for (i = 0; i < 8; i = i + 1) b[i] = 8'h00;

    always @(posedge clk) begin
        we      <= 1'b0;
        tx_send <= 1'b0;

        if (rx_valid) begin
            if (n == 3'd0) begin
                // Only a command byte starts a frame.
                if (rx_data == "W" || rx_data == "R") begin
                    b[0] <= rx_data;
                    n    <= 3'd1;
                end
            end else if (b[0] == "R" && n == 3'd2) begin
                addr    <= {b[1], rx_data};
                pending <= 1'b1;
                n       <= 3'd0;
            end else if (b[0] == "W" && n == 3'd6) begin
                addr  <= {b[1], b[2]};
                wdata <= {b[3], b[4], b[5], rx_data};
                we    <= 1'b1;
                n     <= 3'd0;
            end else begin
                b[n] <= rx_data;
                n    <= n + 3'd1;
            end
        end

        // One clock after addr changes, the read mux has settled.
        if (pending && !sending) begin
            out     <= rdata;
            pending <= 1'b0;
            sending <= 1'b1;
            txn     <= 2'd0;
        end else if (sending && !tx_busy && !tx_send) begin
            tx_data <= out[31:24];       // most significant byte first
            out     <= {out[23:0], 8'h00};
            tx_send <= 1'b1;
            txn     <= txn + 2'd1;
            if (txn == 2'd3) sending <= 1'b0;
        end
    end
endmodule
