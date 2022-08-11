module trafficLight(clk1, rst1, out, dot_row, dot_col);
	input clk1, rst1;
	wire div_clk1, div_clk2;
	reg [1:0]current_state; //green, yellow, red

	output reg [7:0]dot_row;
	output reg [7:0]dot_col;
	reg [2:0]row_cnt;

	//reg [2:0]next_state;	
	reg [3:0]tmp;
	output [6:0]out;
	
	clk_div1 u_clk1(.clk1(clk1),.rst1(rst1),.div_clk1(div_clk1));
	clk_div2 u_clk2(.clk2(clk1),.rst2(rst1),.div_clk2(div_clk2));	
	
	
	always@(posedge div_clk1 or negedge rst1)
	begin
		if(~rst1)
		begin
			current_state <= 0;
			tmp <= 4'b0001;
		end
		
		else begin
			case(current_state)
				0:
					if(tmp < 4'b1111) begin
						tmp <= tmp + 1;
					end
					else begin
						current_state <= current_state + 1;
						tmp <= 4'b0001;
					end
					
				1:
					if(tmp < 4'b0101) begin
						tmp <= tmp + 1;
					end
					else begin
						current_state <= current_state + 1;
						tmp <= 4'b0001;
					end
					
				2:
					if(tmp < 4'b1010) begin
						tmp <= tmp + 1;
					end
					else begin
						current_state <= 0;
						tmp <= 4'b0001;
					end				
			endcase
		end
		
	end		
	
	Seven_Display u_display(.tmp(tmp),.out(out));
	
	
	always@(posedge div_clk2 or negedge rst1)
	begin 
		if(~rst1) 
		begin
		dot_row <= 8'b0;
		dot_col <= 8'b0;
		row_cnt <= 0;
		end
		else begin
		
			case(row_cnt)
				3'd0: dot_row <= 8'b01111111;
				3'd1: dot_row <= 8'b10111111;
				3'd2: dot_row <= 8'b11011111;
				3'd3: dot_row <= 8'b11101111;
				3'd4: dot_row <= 8'b11110111;
				3'd5: dot_row <= 8'b11111011;
				3'd6: dot_row <= 8'b11111101;
				3'd7: dot_row <= 8'b11111110;
			endcase
			case(current_state)
			
				0: 			
				case(row_cnt)
					3'd0: dot_col <= 8'b00001100;
					3'd1: dot_col <= 8'b00001100;
					3'd2: dot_col <= 8'b00011001;
					3'd3: dot_col <= 8'b01111110;
					3'd4: dot_col <= 8'b10011000;
					3'd5: dot_col <= 8'b00011000;
					3'd6: dot_col <= 8'b00101000;
					3'd7: dot_col <= 8'b01001000;
				endcase
				
				1:
				case(row_cnt)
					3'd0: dot_col <= 8'b00000000;
					3'd1: dot_col <= 8'b00100100;
					3'd2: dot_col <= 8'b00111100;
					3'd3: dot_col <= 8'b10111101;
					3'd4: dot_col <= 8'b11111111;
					3'd5: dot_col <= 8'b00111100;
					3'd6: dot_col <= 8'b00111100;
					3'd7: dot_col <= 8'b00000000;
				endcase
				
				2:
				case(row_cnt)
					3'd0: dot_col <= 8'b00011000;
					3'd1: dot_col <= 8'b00011000;
					3'd2: dot_col <= 8'b00111100;
					3'd3: dot_col <= 8'b00111100;
					3'd4: dot_col <= 8'b01011010;
					3'd5: dot_col <= 8'b00011000;
					3'd6: dot_col <= 8'b00011000;
					3'd7: dot_col <= 8'b00100100;
				endcase
				
			endcase
						
				row_cnt <= row_cnt + 1;
		end
	end
endmodule


module clk_div1(clk1, rst1 ,div_clk1);
	input clk1,rst1;
	output reg div_clk1;
		
	reg [31:0]count;
		
	always@(posedge clk1)
	begin
		if(~rst1)
		begin
			count <= 32'd0;
			div_clk1 <= 1'b0;
		end
		else
		begin
			if(count == 32'd25000000)
			begin
				count <=32'd0;
				div_clk1 <= ~div_clk1;
			end
			else
			begin
				count <= count +32'd1;
			end
		end
	end		
endmodule

module clk_div2(clk2, rst2, div_clk2);
	input clk2,rst2;
	output reg div_clk2;
		
	reg [31:0]count;
		
	always@(posedge clk2)
	begin
		if(~rst2)
		begin
			count <= 32'd0;
			div_clk2 <= 1'b0;
		end
		else
		begin
			if(count == 32'd5000)
			begin
				count <=32'd0;
				div_clk2 <= ~div_clk2;
			end
			else
			begin
				count <= count +32'd1;
			end
		end
	end	
endmodule

module Seven_Display(tmp, out);
	input [3:0] tmp;
	output reg [6:0] out;
	always@(tmp)
	begin
		case(tmp)
			//4'b0000 : out = 7'b1000000;
			4'b0001 : out = 7'b1111001;
			4'b0010 : out = 7'b0100100;
			4'b0011 : out = 7'b0110000;
			4'b0100 : out = 7'b0011001;
			4'b0101 : out = 7'b0010010;
			4'b0110 : out = 7'b0000010;
			4'b0111 : out = 7'b1111000;
			4'b1000 : out = 7'b0000000;
			4'b1001 : out = 7'b0010000;
			4'b1010 : out = 7'b0001000;
			4'b1011 : out = 7'b0000011;
			4'b1100 : out = 7'b1000110;
			4'b1101 : out = 7'b0100001;
			4'b1110 : out = 7'b0000110;
			4'b1111 : out = 7'b0001110;
		endcase
	end
endmodule




