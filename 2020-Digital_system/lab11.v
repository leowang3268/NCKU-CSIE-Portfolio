module lab11(clk,rst,keypad_row,keypad_col,dot_row,dot_col,seven_seg);
	input clk,rst;
	output reg [3:0] keypad_row;
	input [3:0] keypad_col;
	output reg [7:0] dot_row,dot_col;
	output reg [6:0] seven_seg;

	reg [31:0] cnt_div,cnt_dot;
	reg [7:0] dot_col_buf[0:7];
	reg [3:0] keypad_buf;
	reg [2:0] row_count;
	reg clk_div,clk_dot;
	
	always@(posedge clk)
	begin
		if (~rst)
		begin
			cnt_div <= 32'b0;
			cnt_dot <= 32'b0;
			clk_div <= 1'b0;
			clk_dot <= 1'b0;
		end
		else
		begin
				// modified your code
			if(cnt_div == 32'd250000)
			begin
				cnt_div <=32'b0;
				clk_div <= ~clk_div;
			end
			else if(cnt_div != 32'd250000)
			begin
				cnt_div <= cnt_div +32'b1;
			end

			if(cnt_dot == 32'd5000)
			begin
				cnt_dot <=32'b0;
				clk_dot <= ~clk_dot;
			end
			else if(cnt_dot != 32'd5000)
			begin
				cnt_dot <= cnt_dot +32'b1;
			end

		end
	end
	
	always@ (posedge clk_dot or negedge rst)
	begin
		if (~rst)
		begin
			dot_row <= 8'd0;
			dot_col <= 8'd0;
			row_count <= 3'd0;
		end
		else
		begin
		    row_count <= row_count + 1;
		    dot_col <= dot_col_buf[row_count];
		    case (row_count)
				3'd0: dot_row <= 8'b01111111;
				3'd1: dot_row <= 8'b10111111;
				3'd2: dot_row <= 8'b11011111;
				3'd3: dot_row <= 8'b11101111;
				3'd4: dot_row <= 8'b11110111;
				3'd5: dot_row <= 8'b11111011;
				3'd6: dot_row <= 8'b11111101;
				3'd7: dot_row <= 8'b11111110;
			endcase
		end
	end
	
	always@(posedge clk_div or negedge rst)
	begin
		if (~rst)
		begin
			keypad_row <= 4'b0111;
			keypad_buf <= 4'd0;
			//keypadDelay <= 31'd0;
			dot_col_buf[0] <= 8'd0;
			dot_col_buf[1] <= 8'd0;
			dot_col_buf[2] <= 8'd0;
			dot_col_buf[3] <= 8'd0;
			dot_col_buf[4] <= 8'd0;
			dot_col_buf[5] <= 8'd0;
			dot_col_buf[6] <= 8'd0;
			dot_col_buf[7] <= 8'd0;
		end
		else
		begin
			//if(keypadDelay == `TimeExpire_KEY)
			//begin
				//keypadDelay = 31'd0;
				case({keypad_row,keypad_col})			
					8'b1110_1110 : 
						begin
							keypad_buf <= 4'h7;
							dot_col_buf[6] <= 8'b00000011 | dot_col_buf[6];
							dot_col_buf[7] <= 8'b00000011 | dot_col_buf[7];
						end
					8'b1110_1101 : 
						begin
							keypad_buf <= 4'h4;
							dot_col_buf[6] <= 8'b00001100 | dot_col_buf[6];
							dot_col_buf[7] <= 8'b00001100 | dot_col_buf[7];
						end
					8'b1110_1011 : 
						begin
							keypad_buf <= 4'h1;
							dot_col_buf[6] <= 8'b00110000 | dot_col_buf[6];
							dot_col_buf[7] <= 8'b00110000 | dot_col_buf[7];
						end
					8'b1110_0111 : 
						begin
							keypad_buf <= 4'h0;
							dot_col_buf[6] <= 8'b11000000 | dot_col_buf[6];
							dot_col_buf[7] <= 8'b11000000 | dot_col_buf[7];
						end
					8'b1101_1110 : 
						begin
							keypad_buf <= 4'h8;
							dot_col_buf[4] <= 8'b00000011 | dot_col_buf[4];
							dot_col_buf[5] <= 8'b00000011 | dot_col_buf[5];
						end
					8'b1101_1101 : 
						begin
							keypad_buf <= 4'h5;
							dot_col_buf[4] <= 8'b00001100 | dot_col_buf[4];
							dot_col_buf[5] <= 8'b00001100 | dot_col_buf[5];
						end
					8'b1101_1011 :
						begin
							keypad_buf <= 4'h2;
							dot_col_buf[4] <= 8'b00110000 | dot_col_buf[4];
							dot_col_buf[5] <= 8'b00110000 | dot_col_buf[5];
						end
					8'b1101_0111 : 
						begin
							keypad_buf <= 4'ha;
							dot_col_buf[4] <= 8'b11000000 | dot_col_buf[4];
							dot_col_buf[5] <= 8'b11000000 | dot_col_buf[5];
						end
					8'b1011_1110 : 
						begin
							keypad_buf <= 4'h9;
							dot_col_buf[2] <= 8'b00000011 | dot_col_buf[2];
							dot_col_buf[3] <= 8'b00000011 | dot_col_buf[3];
						end
					8'b1011_1101 : 
						begin
							keypad_buf <= 4'h6;
							dot_col_buf[2] <= 8'b00001100 | dot_col_buf[2];
							dot_col_buf[3] <= 8'b00001100 | dot_col_buf[3];
						end
					8'b1011_1011 : 
						begin
							keypad_buf <= 4'h3;
							dot_col_buf[2] <= 8'b00110000 | dot_col_buf[2];
							dot_col_buf[3] <= 8'b00110000 | dot_col_buf[3];
						end
					8'b1011_0111 : 
						begin
							keypad_buf <= 4'hb;
							dot_col_buf[2] <= 8'b11000000 | dot_col_buf[2];
							dot_col_buf[3] <= 8'b11000000 | dot_col_buf[3];
						end
					8'b0111_1110 :  
						begin
							keypad_buf <= 4'hc;
							dot_col_buf[0] <= 8'b00000011 | dot_col_buf[0];
							dot_col_buf[1] <= 8'b00000011 | dot_col_buf[1];
						end
					8'b0111_1101 : 
						begin
							keypad_buf <= 4'hd;
							dot_col_buf[0] <= 8'b00001100 | dot_col_buf[0];
							dot_col_buf[1] <= 8'b00001100 | dot_col_buf[1];
						end
					8'b0111_1011 :
						begin
							keypad_buf <= 4'he;
							dot_col_buf[0] <= 8'b00110000 | dot_col_buf[0];
							dot_col_buf[1] <= 8'b00110000 | dot_col_buf[1];
						end
					8'b0111_0111 : 
						begin
							keypad_buf <= 4'hf;
							dot_col_buf[0] <= 8'b11000000 | dot_col_buf[0];
							dot_col_buf[1] <= 8'b11000000 | dot_col_buf[1];
						end
					default : keypad_buf <= keypad_buf;
				endcase
				case(keypad_row)
					4'b1110 : keypad_row <= 4'b1101;
					4'b1101 : keypad_row <= 4'b1011;
					4'b1011 : keypad_row <= 4'b0111;
					4'b0111 : keypad_row <= 4'b1110;
					default : keypad_row <= 4'b1110;
				endcase
			//end
			
				//keypadDelay <= keypadDelay + 1'b1;
		end
	end
	
	always@(*)
	begin
		case(keypad_buf)
		4'h0:seven_seg = 7'b1000000;
		4'h1:seven_seg = 7'b1111001;
		4'h2:seven_seg = 7'b0100100;
		4'h3:seven_seg = 7'b0110000;
		4'h4:seven_seg = 7'b0011001;
		4'h5:seven_seg = 7'b0010010;
		4'h6:seven_seg = 7'b0000010;
		4'h7:seven_seg = 7'b1111000;
		4'h8:seven_seg = 7'b0000000;
		4'h9:seven_seg = 7'b0010000;
		4'ha:seven_seg = 7'b0100000;
		4'hb:seven_seg = 7'b0000011;
		4'hc:seven_seg = 7'b1000110;
		4'hd:seven_seg = 7'b0100001;
		4'he:seven_seg = 7'b0000100;
		4'hf:seven_seg = 7'b0001110;
		endcase
	end

endmodule	
