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
	wire c_sign = c[15];
	
	wire[4:0] a_exp = a[14:10];
	wire[4:0] b_exp = b[14:10];
	wire[4:0] c_exp = c[14:10];
	
	wire[10:0] a_sig = {1'b1, a[9:0]};
	wire[10:0] b_sig = {1'b1, b[9:0]};
	reg[10:0] c_sig;

		
	reg[21:0] prod ; //now it's 22 bits
	reg[5:0] temp_exp;
	
	reg[15:0] mult_out;
	wire mult_out_sign = a_sign ^ b_sign;
	reg[10:0] mult_sig;
	
	reg[11:0] temp_sum; //12 bits, one extra for the carry
	reg[4:0] sum_exp;
	reg sum_sign;
	reg[15:0] sum_out;
	
	always @(*) begin
		if (!a_exp || !b_exp) begin //check if either is 0, if so, output is 0.
			mult_out = 16'b0;
		end else begin
			prod = a_sig * b_sig;
			temp_exp = a_exp + b_exp - 6'd15; //offset of 15
		end
		
		//begin the adding block (a*b) + c
		c_sig = {1'b1, c[9:0]};
		mult_sig = {1'b1, mult_out[9:0]};
		
		if (!mult_out[14:10]) begin //product is 0
			sum_out = c;
		end else if (!c_exp) begin //c is 0
			sum_out = mult_out;
		end else begin
			//normalize exponents: shift the smaller one right
			if (mult_out[14:10] > c_exp) begin
				sum_exp = mult_out[14:10];
				c_sig = c_sig >> (mult_out[14:10] - c_exp);
			end else begin
				sum_exp = c_exp;
				mult_sig = mult_sig >> (c_exp - mult_out[14:10]);
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
			
			if (~temp_sum[11]) begin //if sum overflows (>=2)
				reg[3:0] shift_amount;
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
		end
	end 
	always @(posedge clk) begin
		if (prod[21]) begin //if product overflows (>=2) 
			mult_out <= {a_sign ^ b_sign, temp_exp[4:0]+6'd1, prod[20:11]};
		end else begin 
			mult_out <= {a_sign ^ b_sign, temp_exp[4:0], prod[19:10]};
		end
		if (temp_sum[11]) begin //if sum overflows (>=2)
			sum_out <= {sum_sign, sum_exp + 5'd1, temp_sum[10:1]};
		end else begin
			sum_out <= temp_sum ? {sum_sign, sum_exp, temp_sum[9:0]} : 16'b0;
		end
			
		
		out <= sum_out;
	end
endmodule

	
