module Moore_machine(clk, pause, rst, in, out);
input clk, pause, rst, in;
reg [3:0]tmp;
output [6:0]out;
wire div_clk;
reg [2:0]current_state;
reg [2:0]next_state;

clk_div u_clk(.clk(clk),.rst(rst),.div_clk(div_clk));	

always@(posedge div_clk or negedge rst)
begin
	
	if(!rst)
		current_state <= 0;
	else begin
	if(pause==1)
	begin
		current_state <= current_state;
	end
	else if(pause==0)
	begin
		if(in==1)
		begin
		case(current_state)
			0: current_state <= 1; 
			1: current_state <= 2; 
			2: current_state <= 4; 
			3: current_state <= 3;
			4: current_state <= 5; 
			5: current_state <= 5;
			endcase
		end
	
		else if(in==0)
		begin
		case(current_state)
			0: current_state <= 0; 
			1: current_state <= 0; 
			2: current_state <= 3; 
			3: current_state <= 4;
			4: current_state <= 1; 
			5: current_state <= 2;
			endcase
		end
		
	end
	end

end
	always @ (*) begin
			case(current_state)
			0: tmp = 4'b0000;
			1: tmp = 4'b0001;
			2: tmp = 4'b0010;
			3: tmp = 4'b0011;
			4: tmp = 4'b0100;
			5: tmp = 4'b0101;
		endcase
		end

Seven_Display u_display(.tmp(tmp),.out(out));

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




