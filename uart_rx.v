// Asynchronous serial receiver, 8N1, no parity, no flow control.
// CLKS_PER_BIT = clock frequency / baud rate. 50 MHz / 115200 = 434.
module uart_rx #(
    parameter CLKS_PER_BIT = 434
)(
    input  wire       clk,
    input  wire       rx,      // raw pin, asynchronous to clk
    output reg  [7:0] data,
    output reg        valid    // one clock pulse when data is new
);
    localparam IDLE = 2'd0, START = 2'd1, DATA = 2'd2, STOP = 2'd3;

    reg [1:0]  state = IDLE;
    reg [15:0] count = 0;
    reg [2:0]  bitn  = 0;
    reg [1:0]  sync  = 2'b11;   // two flip-flops against metastability

    wire rx_s = sync[1];

    initial begin
        data  = 8'h00;
        valid = 1'b0;
    end

    always @(posedge clk) begin
        sync  <= {sync[0], rx};
        valid <= 1'b0;

        case (state)
        IDLE: begin
            count <= 0;
            bitn  <= 0;
            if (!rx_s) state <= START;
        end

        // Wait half a bit. This moves every later sample to the
        // middle of its bit cell.
        START:
            if (count == (CLKS_PER_BIT-1)/2) begin
                count <= 0;
                state <= rx_s ? IDLE : DATA;   // still low: a real start bit
            end else
                count <= count + 16'd1;

        DATA:
            if (count == CLKS_PER_BIT-1) begin
                count      <= 0;
                data[bitn] <= rx_s;            // 8N1 sends the LSB first
                if (bitn == 3'd7) state <= STOP;
                else              bitn  <= bitn + 3'd1;
            end else
                count <= count + 16'd1;

        STOP:
            if (count == CLKS_PER_BIT-1) begin
                valid <= 1'b1;
                state <= IDLE;
            end else
                count <= count + 16'd1;
        endcase
    end
endmodule
