module traffic_light(pass, rst, clk, R, G, Y);

input pass, rst, clk;
//wire div_clk;
reg [2:0]current_state; // G1->X->G2->X->G3->Y->R
output reg R, G, Y;
reg[10:0] count;

//clk_div u_clk(.clk(clk), .rst(rst), .div_clk(div_clk));

always@(posedge clk)
begin 
    if(rst || (pass && current_state != 0))
    begin 
        current_state <= 0;
        count <= 1;
        R <= 0;
        G <= 1;
        Y <= 0;
    end
    
    else begin
    case(current_state)
        0: // G1
    	    if(count == 1024)
            begin
                count <= 1;
                current_state <= 1;
                R <= 0;
                G <= 0;
                Y <= 0;            
            end
            else
            begin 
                count <= count + 1;
            end

        1: // X1
            if(count == 128)
            begin
                count <= 1;
                current_state <= 2;
                R <= 0;
                G <= 1;
                Y <= 0;            
            end
            else
            begin 
                count <= count + 1;
            end

        2: // G2
            if(count == 128)
            begin
                count <= 1;
                current_state <= 3;
                R <= 0;
                G <= 0;
                Y <= 0;            
            end
            else
            begin 
                count <= count + 1;
            end

        3: // X2
            if(count == 128)
            begin
                count <= 1;
                current_state <= 4;
                R <= 0;
                G <= 1;
                Y <= 0;            
            end
            else
            begin 
                count <= count + 1;
            end

        4: // G3
            if(count == 128)
            begin
                count <= 1; 
                current_state <= 5;
                R <= 0;
                G <= 0;
                Y <= 1;            
            end
            else
            begin 
                count <= count + 1;
            end

        5: // Y
            if(count == 512)
            begin
                count <= 1;
                current_state <= 6;
                R <= 1;
                G <= 0;
                Y <= 0;            
            end
            else
            begin 
                count <= count + 1;
            end

        6: // R
            if(count == 1024)
            begin
                count <= 1;
                current_state <= 0;
                R <= 0;
                G <= 1;
                Y <= 0;            
            end
            else
            begin 
                count <= count + 1;
            end
        default:
		  begin
            current_state <= 0;
            count <= 1;
            R <= 0;
            G <= 1;
            Y <= 0;
		  end
	 endcase
    end
end

endmodule
//
//module clk_div(clk, rst, div_clk);
//input clk, rst;
//output reg div_clk;
//		
//	reg [31:0]count;
//		
//	always@(posedge clk)
//	begin
//		if(~rst)
//		begin
//			count <= 32'd0;
//			div_clk <= 1'b0;
//		end
//		else
//		begin
//			if(count == 32'd25000000)
//			begin
//				count <=32'd0;
//				div_clk <= ~div_clk;
//			end
//			else
//			begin
//				count <= count +32'd1;
//			end
//		end
//	end
//
//
//endmodule
