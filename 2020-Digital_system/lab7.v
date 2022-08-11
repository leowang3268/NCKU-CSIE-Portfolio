module lab1(clk, rst, sel,result);
	input clk, rst, sel;
	reg [3:0]tmp;  
	output wire [6:0] result;
	wire div_clk;
	
	clk_div u_clk(.clk(clk),.rst(rst),.div_clk(div_clk));
	
	always@(posedge div_clk)
	begin
		if(rst == 0)
		begin
			tmp <= 4'b0000;
		end
		else if(rst == 1) 
		begin
			if(sel==1)
			begin
				tmp <= tmp + 4'b0001;
			end
			else if(sel==0)
			begin	
				tmp <= tmp - 4'b0001;
			end
		end
	end
	
	Seven_Display u_display(.tmp(tmp),.out(result));

endmodule	

module clk_div(clk,rst,div_clk);

	input clk,rst;
	output reg div_clk;
		
	reg [31:0]count;
		
	always@(posedge clk)
	begin
		if(!rst)
		begin
			count <= 32'd0;
			div_clk <= 1'b0;
		end
		else
		begin
			if(count == 32'd25000000)
			begin
				count <=32'd0;
				div_clk <= ~div_clk;
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
			4'b0000 : out = 7'b1000000;
			4'b0001 : out = 7'b0000110;
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