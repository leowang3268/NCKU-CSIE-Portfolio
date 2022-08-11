`define TimeExpired 50000000
`define dotTimeExpired 32'd5000
module dot_matrix_controller(clk,rst,btn_up,btn_down,dot_row_final,dot_col_final,up,down);
	input clk,rst,btn_up,btn_down;
	output reg [7:0] dot_row_final;
	output reg [15:0] dot_col_final;
	reg[7:0] dot_row;
	reg[15:0]dot_col;
	reg[7:0]dot_row_player;
	reg[15:0]dot_col_player;
	output up,down;

	reg [31:0] cnt_div,cnt_dot;
	reg [15:0] dot_col_buff[0:7];
	reg [7:0] dot_row_buff[0:15];
	reg [2:0] row_count;
	reg[3:0]col_count;
	reg clk_div,clk_dot;
	reg clk_div_player,clk_dot_player;
	btn_control up_btn_control(clk,rst,btn_up,up);
	btn_control down_btn_control(clk,rst,btn_down,down);
	
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
			if(cnt_div==`TimeExpired)
			begin
				cnt_div<=32'd0;
				clk_div<=~clk_div;
			end
			else
			begin
				cnt_div<=cnt_div+32'd1;
			end
			if(cnt_dot==`dotTimeExpired)
			begin
				cnt_dot<=32'd0;
				clk_dot<=~clk_dot;
			end
			else 
			begin
				cnt_dot<=cnt_dot+32'd1;
			end
		end
	end
	
	always@ (posedge clk_dot or negedge rst)
	begin
		if (~rst)
		begin
			dot_row <= 8'd0;
			dot_col <= 16'd0;
			row_count <= 3'd0;
		end
		else
		begin
		    row_count <= row_count + 1;
			 dot_col <= dot_col_buff[row_count];
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
	
	
	always@ (posedge clk_div or negedge rst)
	begin
		// controll col to display
		if(~rst)
		begin
			dot_col_buff[0] <= 16'b0001100000000011;
			dot_col_buff[1] <= 16'b0001100000000011;
			dot_col_buff[2] <= 16'b0001100000000011;
			dot_col_buff[3] <= 16'b0001100000000011;
			dot_col_buff[4] <= 16'b0000000011000000;
			dot_col_buff[5] <= 16'b0000000011000000;
			dot_col_buff[6] <= 16'b0000000011000000;
			dot_col_buff[7] <= 16'b0000000011000000;
		end
		else
		begin
			dot_col_buff[0] <= {dot_col_buff[0][14:0],dot_col_buff[0][15]};
			dot_col_buff[1] <= {dot_col_buff[1][14:0],dot_col_buff[1][15]};
			dot_col_buff[2] <= {dot_col_buff[2][14:0],dot_col_buff[2][15]};
			dot_col_buff[3] <= {dot_col_buff[3][14:0],dot_col_buff[3][15]};
			dot_col_buff[4] <= {dot_col_buff[4][14:0],dot_col_buff[4][15]};
			dot_col_buff[5] <= {dot_col_buff[5][14:0],dot_col_buff[5][15]};
			dot_col_buff[6] <= {dot_col_buff[6][14:0],dot_col_buff[6][15]};
			dot_col_buff[7] <= {dot_col_buff[7][14:0],dot_col_buff[7][15]};
		end
	end
	
	always@ (posedge clk_dot or negedge rst)
	begin
		if (~rst)
		begin
			dot_row_player <= 8'd0;
			dot_col_player <= 16'd0;
			col_count <= 4'd0;
		end
		else
		begin
		    col_count <= col_count + 1;
			 dot_row_player <= dot_row_buff[col_count];
		    case (col_count)
				4'd0: dot_col_player <= 16'b1000000000000000;
				4'd1: dot_col_player <= 16'b0100000000000000;
				4'd2: dot_col_player <= 16'b0010000000000000;
				4'd3: dot_col_player <= 16'b0001000000000000;
				4'd4: dot_col_player <= 16'b0000100000000000;
				4'd5: dot_col_player <= 16'b0000010000000000;
				4'd6: dot_col_player <= 16'b0000001000000000;
				4'd7: dot_col_player <= 16'b0000000100000000;
				4'd8: dot_col_player <= 16'b0000000010000000;
				4'd9: dot_col_player <= 16'b0000000001000000;
				4'd10: dot_col_player <= 16'b0000000000100000;
				4'd11: dot_col_player <= 16'b0000000000010000;
				4'd12: dot_col_player <= 16'b0000000000001000;
				4'd13: dot_col_player <= 16'b0000000000000100;
				4'd14: dot_col_player <= 16'b0000000000000010;
				4'd15: dot_col_player <= 16'b0000000000000001;
			endcase
		end
	end
	
	always@ (posedge clk_div or negedge rst)
	begin
		// controll col to display
		if(~rst)
		begin
			dot_row_buff[0] <= 8'b11111111;
			dot_row_buff[1] <= 8'b11111111;
			dot_row_buff[2] <= 8'b11111111;
			dot_row_buff[3] <= 8'b11111111;
			dot_row_buff[4] <= 8'b11111111;
			dot_row_buff[5] <= 8'b11111111;
			dot_row_buff[6] <= 8'b11111111;
			dot_row_buff[7] <= 8'b11111111;
			dot_row_buff[8] <= 8'b11111111;
			dot_row_buff[9] <= 8'b11111111;
			dot_row_buff[10] <= 8'b11111111;
			dot_row_buff[11] <= 8'b11111111;
			dot_row_buff[12] <= 8'b11111111;
			dot_row_buff[13] <= 8'b11111111;
			dot_row_buff[14] <= 8'b00111111;
			dot_row_buff[15] <= 8'b00111111;
		end
		else
		begin
		if(up && ~down && ~(dot_row_buff[14][0]==0 && dot_row_buff[15][0]==0 && dot_row_buff[14][1]==0 && dot_row_buff[15][1]==0 ))
		begin
			dot_row_buff[0] <= {dot_row_buff[0][6:0],dot_row_buff[0][7]};
			dot_row_buff[1] <= {dot_row_buff[1][6:0],dot_row_buff[1][7]};
			dot_row_buff[2] <= {dot_row_buff[2][6:0],dot_row_buff[2][7]};
			dot_row_buff[3] <= {dot_row_buff[3][6:0],dot_row_buff[3][7]};
			dot_row_buff[4] <= {dot_row_buff[4][6:0],dot_row_buff[4][7]};
			dot_row_buff[5] <= {dot_row_buff[5][6:0],dot_row_buff[5][7]};
			dot_row_buff[6] <= {dot_row_buff[6][6:0],dot_row_buff[6][7]};
			dot_row_buff[7] <= {dot_row_buff[7][6:0],dot_row_buff[7][7]};
			dot_row_buff[8] <= {dot_row_buff[8][6:0],dot_row_buff[8][7]};
			dot_row_buff[9] <= {dot_row_buff[9][6:0],dot_row_buff[9][7]};
			dot_row_buff[10] <= {dot_row_buff[10][6:0],dot_row_buff[10][7]};
			dot_row_buff[11] <= {dot_row_buff[11][6:0],dot_row_buff[11][7]};
			dot_row_buff[12] <= {dot_row_buff[1][6:0],dot_row_buff[12][7]};
			dot_row_buff[13] <= {dot_row_buff[13][6:0],dot_row_buff[13][7]};
			dot_row_buff[14] <= {dot_row_buff[14][6:0],dot_row_buff[14][7]};
			dot_row_buff[15] <= {dot_row_buff[15][6:0],dot_row_buff[15][7]};
		end
		else if(~up && down && ~(dot_row_buff[14][6]==0 && dot_row_buff[15][6]==0 && dot_row_buff[14][7]==0 && dot_row_buff[15][7]==0 ))
		begin
			dot_row_buff[0] <= {dot_row_buff[0][0],dot_row_buff[0][7:1]};
			dot_row_buff[1] <= {dot_row_buff[1][0],dot_row_buff[1][7:1]};
			dot_row_buff[2] <= {dot_row_buff[2][0],dot_row_buff[2][7:1]};
			dot_row_buff[3] <= {dot_row_buff[3][0],dot_row_buff[3][7:1]};
			dot_row_buff[4] <= {dot_row_buff[4][0],dot_row_buff[4][7:1]};
			dot_row_buff[5] <= {dot_row_buff[5][0],dot_row_buff[5][7:1]};
			dot_row_buff[6] <= {dot_row_buff[6][0],dot_row_buff[6][7:1]};
			dot_row_buff[7] <= {dot_row_buff[7][0],dot_row_buff[7][7:1]};
			dot_row_buff[8] <= {dot_row_buff[8][0],dot_row_buff[8][7:1]};
			dot_row_buff[9] <= {dot_row_buff[9][0],dot_row_buff[9][7:1]};
			dot_row_buff[10] <= {dot_row_buff[10][0],dot_row_buff[10][7:1]};
			dot_row_buff[11] <= {dot_row_buff[11][0],dot_row_buff[11][7:1]};
			dot_row_buff[12] <= {dot_row_buff[12][0],dot_row_buff[12][7:1]};
			dot_row_buff[13] <= {dot_row_buff[13][0],dot_row_buff[13][7:1]};
			dot_row_buff[14] <= {dot_row_buff[14][0],dot_row_buff[14][7:1]};
			dot_row_buff[15] <= {dot_row_buff[15][0],dot_row_buff[15][7:1]};
		end
		end
	end
	
	always@ (*)
	begin
		dot_row_final[0]<=dot_row[0] && dot_row_player[0];
		dot_row_final[1]<=dot_row[1] && dot_row_player[1];
		dot_row_final[2]<=dot_row[2] && dot_row_player[2];
		dot_row_final[3]<=dot_row[3] && dot_row_player[3];
		dot_row_final[4]<=dot_row[4] && dot_row_player[4];
		dot_row_final[5]<=dot_row[5] && dot_row_player[5];
		dot_row_final[6]<=dot_row[6] && dot_row_player[6];
		dot_row_final[7]<=dot_row[7] && dot_row_player[7];
		dot_col_final[0]<=dot_col[0] || dot_col_player[0];
		dot_col_final[1]<=dot_col[1] || dot_col_player[1];
		dot_col_final[2]<=dot_col[2] || dot_col_player[2];
		dot_col_final[3]<=dot_col[3] || dot_col_player[3];
		dot_col_final[4]<=dot_col[4] || dot_col_player[4];
		dot_col_final[5]<=dot_col[5] || dot_col_player[5];
		dot_col_final[6]<=dot_col[6] || dot_col_player[6];
		dot_col_final[7]<=dot_col[7] || dot_col_player[7];
		dot_col_final[8]<=dot_col[8] || dot_col_player[8];
		dot_col_final[9]<=dot_col[9] || dot_col_player[9];
		dot_col_final[10]<=dot_col[10] || dot_col_player[10];
		dot_col_final[11]<=dot_col[11] || dot_col_player[11];
		dot_col_final[12]<=dot_col[12] || dot_col_player[12];
		dot_col_final[13]<=dot_col[13] || dot_col_player[13];
		dot_col_final[14]<=dot_col[14] || dot_col_player[14];
		dot_col_final[15]<=dot_col[15] || dot_col_player[15];
	end
	integer i,j;
	initial begin
	for(i=0;i<7;i=i+1)
	begin
		for(j=0;j<15;j=j+1)
		begin
			if(dot_col_buff[i][j]==1 && dot_row_buff[15-j][i]==0)
			begin
				cnt_div <= 32'b0;
				cnt_dot <= 32'b0;
				clk_div <= 1'b0;
				clk_dot <= 1'b0;
				dot_row <= 8'd0;
				dot_col <= 16'd0;
				row_count <= 3'd0;
				dot_col_buff[0] <= 16'b0001100000000011;
			dot_col_buff[1] <= 16'b0001100000000011;
			dot_col_buff[2] <= 16'b0001100000000011;
			dot_col_buff[3] <= 16'b0001100000000011;
			dot_col_buff[4] <= 16'b0000000011000000;
			dot_col_buff[5] <= 16'b0000000011000000;
			dot_col_buff[6] <= 16'b0000000011000000;
			dot_col_buff[7] <= 16'b0000000011000000;
			dot_row_player <= 8'd0;
			dot_col_player <= 16'd0;
			col_count <= 4'd0;
			dot_row_buff[0] <= 8'b11111111;
			dot_row_buff[1] <= 8'b11111111;
			dot_row_buff[2] <= 8'b11111111;
			dot_row_buff[3] <= 8'b11111111;
			dot_row_buff[4] <= 8'b11111111;
			dot_row_buff[5] <= 8'b11111111;
			dot_row_buff[6] <= 8'b11111111;
			dot_row_buff[7] <= 8'b11111111;
			dot_row_buff[8] <= 8'b11111111;
			dot_row_buff[9] <= 8'b11111111;
			dot_row_buff[10] <= 8'b11111111;
			dot_row_buff[11] <= 8'b11111111;
			dot_row_buff[12] <= 8'b11111111;
			dot_row_buff[13] <= 8'b11111111;
			dot_row_buff[14] <= 8'b00111111;
			dot_row_buff[15] <= 8'b00111111;
			end
		end
	end
	end
endmodule

module btn_control(clk,rst,btn_signal,move);
	input clk,rst,btn_signal;
	output reg move;

	reg [31:0] cnt;

	always@(posedge clk or negedge rst)
	begin
		if (~rst)
		begin
			move <= 1'b0;
			cnt <= 32'd0;
		end
		else
		begin

			if (cnt == 12500000)
			begin
				move <= 1'b0;
				cnt <= 32'd0;
			end
			else if(cnt[7:0] == 8'd0)
			begin
				move <= (!btn_signal)? 1'b1 : move;
				cnt <= cnt + 32'b1;
			end
			else
			begin
				cnt <= cnt + 32'b1;
			end
		end
	end

endmodule
