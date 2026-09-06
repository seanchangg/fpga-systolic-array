//16 bit floating point: 
// [15] - sign bit
// [14:10] - exponent bits
// [9:0] - mantissa
// actual val = (-1)^S * 2^(E-bias) x (1.mantissa)
//bias = 1/2 max E, to prevent signed overflow

module processing_unit (
	input clk,
	input[15:0] a,
	input[15:0] b,
	input [15:0] c,
	output reg[15:0] out
);
	wire a_sign = a[15];
	wire b_sign = b[15];

	wire[4:0] a_exp = a[14:10];
	wire[4:0] b_exp = b[14:10];
	
	wire[10:0] a_sig = {1'b1, a[9:0]};
	wire[10:0] b_sig = {1'b1, b[9:0]};
	
	//I: A*B
	reg[21:0] prod; //now it's 22 bits
	reg[15:0] mult_next;
	reg[5:0] prod_exp;
	always @(*) begin
		prod = a_sig * b_sig;
		prod_exp = a_exp + b_exp - 6'd15; //offset of 15		
		if (!a_exp || !b_exp) begin //check if either is 0, if so, output is 0.
			mult_next = 16'b0;
		end else if(prod[21]) begin
			mult_next = {a_sign ^ b_sign, prod_exp[4:0]+6'd1, prod[20:11]};
		end else begin
			mult_next = {a_sign ^ b_sign, prod_exp[4:0], prod[19:10]};
		end
		
	end
	
	//UPDATE REGISTER
	reg[15:0] mult_out;
	reg[15:0] c_d;
	always @(posedge clk) begin
		mult_out <= mult_next;
		c_d <= c;
	end
	
	//(A*B) + C
	wire c_sign = c_d[15];
	wire mult_out_sign = mult_out[15];
	wire[4:0] mult_exp = mult_out[14:10];
	wire[4:0] c_exp = c_d[14:10];
	
	reg[15:0] sum_next;	
	reg[11:0] temp_sum; //12 bits, one extra for the carry
	reg[4:0] sum_exp;
	reg[3:0] shift_amount;
	reg sum_sign;
	
	reg[10:0] mult_sig;
	reg[10:0] c_sig;
	
	always @(*) begin
		sum_next = 16'b0;
		temp_sum = 12'b0;
		sum_exp = 5'b0;
		shift_amount = 4'b0;
		sum_sign = 1'b0;
		c_sig = {1'b1, c_d[9:0]};
		mult_sig = {1'b1, mult_out[9:0]};
		
		if (!mult_exp) begin //product is 0
			sum_next = c_d;
		end else if (!c_exp) begin //c is 0
			sum_next = mult_out;
		end else begin
			//normalize exponents: shift the smaller one right
			if (mult_exp > c_exp) begin
				sum_exp = mult_exp;
				c_sig = c_sig >> (mult_exp - c_exp);
			end else begin
				sum_exp = c_exp;
				mult_sig = mult_sig >> (c_exp - mult_exp);
			end
			
			if (mult_out_sign == c_sign) begin //if same sign
				temp_sum = mult_sig + c_sig;
				sum_sign = c_sign;
			end else if (mult_sig >= c_sig) begin //sign stays on the greater magnitude side
				temp_sum = mult_sig - c_sig;
				sum_sign = mult_out_sign;
			end else begin
				temp_sum = c_sig - mult_sig;
				sum_sign = c_sign;
			end
			
			if (temp_sum[11]) begin //if sum overflows (>=2)
				sum_next = {sum_sign, sum_exp + 5'd1, temp_sum[10:1]};
			end else begin
				if (temp_sum[10])       shift_amount = 4'd0;
			    else if (temp_sum[9])   shift_amount = 4'd1;
			    else if (temp_sum[8])   shift_amount = 4'd2;
			    else if (temp_sum[7])   shift_amount = 4'd3;
			    else if (temp_sum[6])   shift_amount = 4'd4;
			    else if (temp_sum[5])   shift_amount = 4'd5;
			    else if (temp_sum[4])   shift_amount = 4'd6;
			    else if (temp_sum[3])   shift_amount = 4'd7;
			    else if (temp_sum[2])   shift_amount = 4'd8;
			    else if (temp_sum[1])   shift_amount = 4'd9;
			    else if (temp_sum[0])   shift_amount = 4'd10;
			    else                    shift_amount = 4'd0; 
				temp_sum = temp_sum << shift_amount;
				sum_exp = sum_exp - shift_amount;		
			end
			sum_next = temp_sum ? {sum_sign, sum_exp, temp_sum[9:0]} : 16'b0;		
		end
	end 
	
	always @(posedge clk) begin
		out <= sum_next;
	end
endmodule

	
