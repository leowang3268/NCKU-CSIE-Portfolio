// Please include verilog file if you write module in other file
module CPU(
    input             clk,
    input             rst,
	 input      [31:0] instr_out,
    input      [31:0] data_out,
    output reg        instr_read,
	 output reg [31:0] instr_addr,
	 output reg        data_read,
    output reg [3:0]  data_write,
	 output reg [31:0] data_addr,
    output reg [31:0] data_in   
);

	parameter reg[2:0] INSTR_READ = 3'b000, INSTR_DECODE = 3'b001, MIDDLE = 3'b010, LOAD = 3'b011, NEXT_INSTR = 3'b100;
	reg [2:0] state = NEXT_INSTR;

	reg [31:0] imm;
	reg [6:0] funct7, opcode;
	reg [4:0] rs1, rs2, rd;
	reg [2:0] funct3;
	reg [31:0] x[0:31]; // 32 regiters, each with 32 bits
	reg [63:0] result;
	integer i = 0;
	initial instr_read = 1;

    function [31:0] get_upper_bits(input [63:0] product);
        get_upper_bits = product[63:32];
    endfunction


/* Add your design */
always@(posedge clk) 
begin
	if(rst == 1'b1)
	begin
		instr_read <= 1'b1;
		instr_addr <= 32'd0;
		data_read <= 1'b0;
		data_write <= 4'b0;
		data_addr <= 32'd0;
		imm <= 32'd0;
		for(i = 0; i < 32; i = i + 1)
			x[i] <= 32'b0;
		state <= INSTR_READ;
	end
	else
    begin 
        case(state)
            INSTR_READ:
            begin
                {funct7, rs2, rs1, funct3, rd, opcode} <= instr_out;
                instr_read <= 1'b0;
                state <= INSTR_DECODE;
            end
            INSTR_DECODE:
            begin
                case(opcode)
                    7'b0110011: // R type
                    begin


							case({funct7, funct3})
								10'b0000000000: x[rd] <= x[rs1] + x[rs2];
                                10'b0100000000: x[rd] <= x[rs1] - x[rs2];
								10'b0000000001: x[rd] <= x[rs1] << x[rs2][4:0];
								10'b0000000010: x[rd] <= ($signed(x[rs1]) < $signed(x[rs2])) ? 32'd1 : 32'd0;  //signed
								10'b0000000011: x[rd] <= ($unsigned(x[rs1]) < $unsigned(x[rs2])) ? 32'd1 : 32'd0;  //unsigned
								10'b0000000100: x[rd] <= x[rs1] ^ x[rs2];
								10'b0000000101: x[rd] <= ($unsigned(x[rs1]) >> x[rs2][4:0]);
                                10'b0100000101: x[rd] <= ($signed(x[rs1]) >>> x[rs2][4:0]);  
								10'b0000000110: x[rd] <= x[rs1] | x[rs2]; 
								10'b0000000111: x[rd] <= x[rs1] & x[rs2];

                                10'b0000001000: 
                                begin
                                    x[rd] <= ($signed(x[rs1]) * $signed(x[rs2]));
                                end
                                10'b0000001001: 
                                begin
                                    x[rd] <= get_upper_bits($signed(x[rs1]) * $signed(x[rs2]));
                                end
                                10'b0000001011: 
                                begin
                                    x[rd] <= get_upper_bits($unsigned(x[rs1]) * $unsigned(x[rs2]));
                                end
                                // default: x[rd] <= x[rd];  // should not happen
                            endcase
                            instr_addr <= instr_addr + 32'd4;
                            state <= NEXT_INSTR;

                    end
                    7'b0000011: // I type (load)
                    begin
						imm <= {{20{instr_out[31]}}, instr_out[31:20]};
						data_addr <= x[rs1] + imm;
						data_read <= 1'b1;
						state <= MIDDLE;
                    end
                    7'b0010011: // I type (arithmetic)
                    begin
                        case(funct3[1:0])
                            2'b01:
                            begin
                                case({funct7, funct3[2]})
									8'b00000000: x[rd] <= $unsigned(x[rs1]) << rs2;
                                    8'b00000001: x[rd] <= ($unsigned(x[rs1]) >> rs2);
                                    8'b01000001: x[rd] <= ($signed(x[rs1]) >>> rs2);
								endcase
                                state <= NEXT_INSTR;
                            end
                            default:
                            begin
								imm <= {{20{instr_out[31]}}, instr_out[31:20]};
                                state <= MIDDLE;
                            end
                        endcase
                        instr_addr <= instr_addr + 32'd4;
                    end
                    7'b1100111: // I type (JALR)
                    begin
						imm <= {{20{instr_out[31]}}, instr_out[31:20]};	
						x[rd] <= instr_addr + 32'd4;
						instr_addr <= imm + x[rs1] & 32'b11111111111111111111111111111110;			
						state <= NEXT_INSTR;
                    end
                    7'b0100011: // S type (store)
                    begin
						imm <= {{20{instr_out[31]}}, instr_out[31:25], instr_out[11:7]}; 	
						data_addr <= x[rs1] + imm;
						instr_addr <= instr_addr + 32'd4;
						state <= MIDDLE;
                    end
                    7'b1100011: // B type (branch)
                    begin
						imm <= {{19{instr_out[31]}}, instr_out[31], instr_out[7], instr_out[30:25], instr_out[11:8], 1'b0}; 
						state <= MIDDLE;
                    end
                    7'b0010111: // U type (AUIPC)
                    begin
						imm <= {instr_out[31:12], 12'b0};
						state <= MIDDLE;
                    end
                    7'b0110111: // U type (LUI)
                    begin
						imm <= {instr_out[31:12], 12'b0};
						state <= MIDDLE;		
                    end
                    7'b1101111: // J type (JAL)
                    begin
						imm <= {{11{instr_out[31]}}, instr_out[31], instr_out[19:12], instr_out[20], instr_out[30:21], 1'b0};
						instr_addr <= instr_addr + 32'd4;
						state <= MIDDLE;
                    end
					default:
					begin
						state <= NEXT_INSTR; // should not happen
					end
                endcase
                instr_read <= 1'b1;
            end
            MIDDLE:
            begin
                case(opcode)
                    7'b0000011: // I type (load)
                    begin
                        data_read <= 1'b1;
                        state <= LOAD;
                    end
                    7'b0010011: // I type (arithmetic)
                    begin
                        case(funct3)
							3'b000: x[rd] <= x[rs1] + imm; 
	//							3'b001: x[rd] <= x[rs1] << shamt;
							3'b010: x[rd] <= ($signed(x[rs1]) < $signed(imm)) ? 32'b1 : 32'b0; 
							3'b011: x[rd] <= ($unsigned(x[rs1]) < $unsigned(imm)) ? 32'b1 : 32'b0; 
							3'b100: x[rd] <= x[rs1] ^ imm; 
	//							3'b101: x[rd] <= (funct7[5] == 0) ? (x[rs1] >> shamt) : ($signed(x[rs1]) >>> shamt) ;
							3'b110: x[rd] <= x[rs1] | imm; 
							3'b111: x[rd] <= x[rs1] & imm; 		 	
						endcase
                        state <= NEXT_INSTR;
                        end
                    7'b0100011: // S type (store)
                    begin
                        data_in <= x[rs2] << data_addr[1:0]*  8;
                        case(funct3)
                            3'b010: data_write <= 4'b1111 << data_addr[1:0];    
                            3'b000: data_write <= 4'b0001 << data_addr[1:0];    
                            3'b001: data_write <= 4'b0011 << data_addr[1:0]; 	
                            // default: data_write <= data_write;
                        endcase
                        state <= NEXT_INSTR;
                    end
                    7'b1100011: // B type (branch)
                    begin
                        case(funct3)
                            3'b000: instr_addr <= (x[rs1] == x[rs2]) ? (instr_addr + imm) : (instr_addr + 32'd4);
							3'b001: instr_addr <= (x[rs1] != x[rs2]) ? (instr_addr + imm) : (instr_addr + 32'd4);
							3'b100: instr_addr <= ($signed(x[rs1]) < $signed(x[rs2])) ? (instr_addr + imm) : (instr_addr + 32'd4);
							3'b101: instr_addr <= ($signed(x[rs1]) >= $signed(x[rs2])) ? (instr_addr + imm) : (instr_addr + 32'd4);
							3'b110: instr_addr <= ($unsigned(x[rs1]) < $unsigned(x[rs2])) ? (instr_addr + imm) : (instr_addr + 32'd4);
							3'b111: instr_addr <= ($unsigned(x[rs1]) >= $unsigned(x[rs2])) ? (instr_addr + imm) : (instr_addr + 32'd4);
							// default: instr_addr <= instr_addr; // should not happen
                        endcase
                        state <= NEXT_INSTR;
                    end
                    7'b0010111: // U type (AUIPC)
                    begin
						x[rd] <= instr_addr + imm;
						instr_addr <= instr_addr + 32'd4;
						state <= NEXT_INSTR;
                    end
                    7'b0110111: // U type (LUI)
                    begin
                        x[rd] <= imm;
                        instr_addr <= instr_addr + 32'd4;
                        state <= NEXT_INSTR;
                    end
                    7'b1101111: // J type (JAL)
                    begin
                        instr_addr <= instr_addr + imm;
                        state <= NEXT_INSTR;
                    end               
                endcase
            end      
            LOAD:
			begin
                case(opcode)
                    7'b0000011: //I-type (memory related)
                    begin
                        data_read <= 1'b0;
                        case(funct3)
                            3'b010: x[rd] <= data_out;
                            3'b000: x[rd] <= {{24{data_out[7]}}, data_out[7:0]};
                            3'b001: x[rd] <= {{16{data_out[15]}}, data_out[15:0]};
                            3'b100: x[rd] <= {24'b0, data_out[7:0]};
                            3'b101: x[rd] <= {16'b0, data_out[15:0]};
                            // default: x[rd] <= x[rd];  // should not happen
                        endcase
                        instr_addr <= instr_addr + 32'd4;
                        state <= NEXT_INSTR;
                    end
                endcase
			end
            NEXT_INSTR:
			begin
				instr_read <= 1'b1;
				data_read <= 1'b0;
				data_write <= 4'b0;
				data_addr <= 32'b0;
				imm <= 32'd0;
				x[5'b0] <= 32'd0;
				state <= INSTR_READ;
			end
        endcase
        end
    end

    initial begin
        $dumpfile("run.vcd");
        $dumpvars;
    end
endmodule