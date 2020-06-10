`include "defines.v"

module ex(
	input wire rst,
	
	input wire[`AluOpBus] 	aluop_i,
	input wire[`AluSelBus]  alusel_i,
	input wire[`RegBus] 	reg1_i,
	input wire[`RegBus] 	reg2_i,
	input wire[`RegAddrBus] wd_i,
	input wire				wreg_i,
	
	input wire[`RegBus] 	link_address_i,
	input wire				is_in_delayslot_i,
	
	output reg[`RegAddrBus] wd_o,
	output reg 				wreg_o,
	output reg[`RegBus]		wdata_o
);

	reg[`RegBus] logic_out;
	reg[`RegBus] shift_res;
	reg[`RegBus] arith_res;
	
	always @ (*) begin
		if (rst == `RstEnable) begin
			logic_out <= `ZeroWord;
		end else begin
			case(aluop_i)
				`EXE_OR_OP: 	begin
					logic_out <= reg1_i | reg2_i;
				end
				`EXE_AND_OP: 	begin
					logic_out <= reg1_i & reg2_i;
				end
				`EXE_XOR_OP: 	begin
					logic_out <= reg1_i ^ reg2_i;
				end
				default:		begin
					logic_out <= `ZeroWord;
				end
			endcase
		end
	end
	
	always @ (*) begin
		if (rst == `RstEnable) begin
			shift_res <= `ZeroWord;
		end else begin
			case(aluop_i)
				`EXE_SLL_OP: 	begin
					shift_res <= reg2_i << reg1_i[4:0];
				end
				`EXE_SRL_OP: 	begin
					shift_res <= reg2_i >> reg1_i[4:0];
				end
				default:		begin
					shift_res <= `ZeroWord;
				end
			endcase
		end
	end
	
	always @ (*) begin
		if (rst == `RstEnable) begin
			arith_res <= `ZeroWord;
		end else begin
			case(aluop_i)
				`EXE_ADDU_OP, `EXE_ADDIU_OP: 	begin
					arith_res <= reg1_i + reg2_i;
				end
				default: 	begin
				end
			endcase
		end
	end
	
	always @ (*) begin
		wd_o 	<= wd_i;
		wreg_o  <= wreg_i;
		case(alusel_i)
			`EXE_RES_LOGIC: 	begin
				wdata_o <= logic_out;
			end
			`EXE_RES_SHIFT: 	begin
				wdata_o <= shift_res;
			end
			`EXE_RES_ARITH:		begin
				wdata_o <= arith_res;
			end
			`EXE_RES_JUMPB:		begin
				wdata_o <= link_address_i;
			end
			default:			begin
				wdata_o <= `ZeroWord;
			end
		endcase
	end
	
endmodule
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
	
	