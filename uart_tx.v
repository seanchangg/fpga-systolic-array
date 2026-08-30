// Asynchronous serial transmitter, 8N1, no parity, no flow control.
// Assert send for one clock while busy is low. busy stays high until
// the stop bit has been on the line for a full bit period.
module uart_tx #(
    parameter CLKS_PER_BIT = 434
)(
    input  wire       clk,
    input  wire [7:0] data,
    input  wire       send,
    output reg        tx   = 1'b1,
    output reg        busy = 1'b0
);
    reg [8:0]  shift = 9'h1FF;
    reg [3:0]  bitn  = 0;
    reg [15:0] count = 0;

    always @(posedge clk) begin
        if (!busy) begin
            tx <= 1'b1;
            if (send) begin
                shift <= {1'b1, data};   // the stop bit sits above the data
                tx    <= 1'b0;           // the start bit goes out now
                bitn  <= 0;
                count <= 0;
                busy  <= 1'b1;
            end
        end else if (count == CLKS_PER_BIT-1) begin
            count <= 0;
            tx    <= shift[0];
            shift <= {1'b1, shift[8:1]};
            // 9, not 8. The stop bit needs a full bit period of its own.
            if (bitn == 4'd9) busy <= 1'b0;
            else              bitn <= bitn + 4'd1;
        end else
            count <= count + 16'd1;
    end
endmodule
