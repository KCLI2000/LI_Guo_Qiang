//*******GLOBAL MACRO DEFINE*******//

`define RstEnable 		1'b1 			// reset signal enabled
`define RstDisable 		1'b0 			// reset signal disabled
`define ZeroWord		32'h00000000	// 32-bit zero
`define WriteEnable 	1'b1			// write signal enabled
`define WriteDisable	1'b0			// write signal disabled
`define ReadEnable		1'b1 			// read signal enabled
`define ReadDisable		1'b0			// read signal disabled
`define AluOpBus		7:0				// width of aluop_o when decode
`define AluSelBus		2:0				// width of alusel_o when decode
`define InstValid  		1'b1 			// Instruction valid
`define InstInvalid 	1'b0 			// Instruction invalid
`define True_v			1'b1			// Logic True
`define False_v			1'b0			// Logic False
`define ChipEnable 		1'b1			// Chip Enable Signal
`define ChipDisable 	1'b0			// Chip Disable Signal
`define Branch			1'b1 			// JUMP
`define NotBranch		1'b0			// DO NOT JUMP
`define InDelaySlot		1'b1
`define NotInDelaySlot	1'b0

//*******MACRO DEFINE RELATED TO SPECIFIC INST.*******//

`define EXE_ORI 		6'b001101		// ORI INST. CODE
`define EXE_NOP			6'b000000		// NOP INST. CODE
`define EXE_AND			6'b100100		// AND INST. CODE
`define EXE_OR			6'b100101		// OR INST. CODE
`define EXE_XOR			6'b100110		// XOR INST. CODE
`define EXE_ANDI		6'b001100		// ANDI INST. CODE
`define EXE_XORI		6'b001110		// XORI INST. CODE
`define EXE_LUI			6'b001111		// LUI INST. CODE

`define EXE_SLL			6'b000000		// SLL INST. CODE
`define EXE_SRL			6'b000010		// SRL INST. CODE

`define EXE_ADDIU		6'b001001		// ADDIU INST. CODE
`define EXE_ADDU		6'b100001		// ADDU INST. CODE
`define EXE_MUL			6'b000010		// MUL INST. CODE

`define EXE_BEQ			6'b000100
`define EXE_BGTZ		6'b000111
`define EXE_BNE			6'b000101

`define EXE_J			6'b000010
`define EXE_JAL			6'b000011
`define EXE_JR			6'b001000

// `define EXE_LB		6'b100000
// `define EXE_LW		6'b100011
// `define EXE_SB		6'b101000		
// `define EXE_SW		6'b101011	

`define EXE_SYNC		6'b001111		// SYNC INST. CODE
`define EXE_PREF		6'b110011		// PREF INST. CODE
`define EXE_SPECIAL_INST  6'b000000		// SPECIAL TYPE INST. CODE
`define EXE_SPECIAL2_INST 6'b011100		// SPECIAL2 TYPE INST. CODE
`define EXE_COP1_INST	6'b010001		// COP1 TYPE INST. CODE

`define EXE_OR_OP 		8'b00100101		// OR  SubOPER. CODE(DECODED)
`define EXE_NOP_OP		8'b00000000		// NOP SubOPER. CODE(DECODED)
`define EXE_AND_OP		8'b00100100		// AND SubOPER. CODE(DECODED)
`define EXE_XOR_OP		8'b00100110		// XOR SubOPER. CODE(DECODED)
`define EXE_SLL_OP		8'b00000000		// SLL SubOPER. CODE(DECODED)
`define EXE_SRL_OP		8'b00000010		// SRL SubOPER. CODE(DECODED)
`define EXE_ADDIU_OP	8'b00001001		// ADDIU SubOPER. CODE(DECODED)
`define EXE_ADDU_OP		8'b00100001		// ANDU SubOPER. CODE(DECODED)
`define EXE_MUL_OP		8'b00000010		// MUL SubOPER. CODE(DECODED)	
`define EXE_BEQ_OP		8'b00000100		// MUL SubOPER. CODE(DECODED)
`define EXE_BGTZ_OP		8'b00000111		// MUL SubOPER. CODE(DECODED)
`define EXE_BNE_OP		8'b00000101		// MUL SubOPER. CODE(DECODED)
`define EXE_J_OP		8'b00000010		// MUL SubOPER. CODE(DECODED)
`define EXE_JAL_OP		8'b00000011		// MUL SubOPER. CODE(DECODED)
`define EXE_JR_OP		8'b00001000		// MUL SubOPER. CODE(DECODED)

`define EXE_RES_LOGIC 	3'b001			// LOGIC OPER. CODE(DECODED)
`define EXE_RES_SHIFT	3'b010			// SHIFT OPER. CODE(DECODED)
`define EXE_RES_ARITH	3'b011			// ARITHMETIC OPER. CODE(DECODED)
`define EXE_RES_MULTI	3'b100			// MULTIPLY OPER. CODE(DECODED)
`define EXE_RES_JUMPB	3'b101			// JUMP BRANCH OPER. CODE(DECODED)
`define EXE_RES_NOP 	3'b000 			// NOP OPER. CODE(DECODED)

//*******MACRO DEFINE RELATED TO INST.MEM.ROM*******//

`define InstAddrBus 	31:0			// ROM ADDR. BUS WIDTH
`define InstBus			31:0			// ROM DATA BUS WIDTH
`define InstMemNum		131071			// Size of ROM
`define InstMemNumLog2  17				// Width of ADDR.LINE ROM USED

//*******MACRO DEFINE RELATED TO GEN.REG.Regfile*******//

`define RegAddrBus		4:0				// Width of ADDR.LINE of Regfile
`define RegBus			31:0			// Width of DATA.LINE of Regfile
`define RegWidth		32 				// Width of GENERAL REG.
`define DoubleRegWidth  64				// Doubled Width of GENERAL REG.
`define DoubleRegBus	31:0			// Doubled Width of DATA.LINE of Regfile
`define RegNum			32 				// Number of GENERAL REG.
`define RegNumLog2		5				// Addr.bit ADDR.GEN.REG USED
`define NOPRegAddr 		5'b00000


















