/* verilator lint_off UNUSED  */
import "DPI-C" function void ebreak();

module IDU(
	input [31:0]inst,
  output [4:0] rs1,
  output [4:0] rs2,
  output [4:0] rd,
  output [31:0] imm,
  output [4:0] alu_op,
  output [3:0] mem_op,
  output [3:0] ex_op,
  output [3:0] pc_op
);

wire [4:0] _rs1 = inst[19:15];
wire [4:0] _rs2 = inst[24:20];
wire [4:0] _rd  = inst[11:7];
wire [6:0] opcode = inst[6:0];
wire [2:0] funct3 = inst[14:12];
wire [6:0] funct7 = inst[31:25];
wire [11:0]funct12 = inst[31:20];

//ebreak操作
always @(*) begin
  if(opcode == 7'b1110011 && funct12 == 12'h1)begin
    ebreak();
  end
end

//指令类型的声明
wire R_type;
wire I_type;
wire S_type;
wire B_type;
wire U_type;
wire J_type;
wire NONE_type;

//各种指令的声明
wire Inst_auipc;
wire Inst_add;   
wire Inst_addi;   
wire Inst_and;    
wire Inst_andi;  
wire Inst_beq;   
wire Inst_bne;   
wire Inst_bge;    
wire Inst_bgeu;  
wire Inst_blt;    
wire Inst_bltu;   
wire Inst_divu;   
wire Inst_div;    
wire Inst_lw;     
wire Inst_lui;	  
wire Inst_lbu;   
wire Inst_lh;     
wire Inst_lb;   
wire Inst_lhu;    
wire Inst_mul;   
wire Inst_mulh;   
wire Inst_mulhu;  
wire Inst_or;     
wire Inst_ori;   
wire Inst_rem;   
wire Inst_remu;   
wire Inst_sw;   
wire Inst_sub;   
wire Inst_sltiu;  
wire Inst_slti;   
wire Inst_sltu;   
wire Inst_sh;     
wire Inst_srai;  
wire Inst_sll;    
wire Inst_srli;  
wire Inst_slli;  
wire Inst_slt;   
wire Inst_sb;     
wire Inst_sra;  
wire Inst_srl;   
wire Inst_xor;   
wire Inst_xori; 
wire Inst_jal; 
wire Inst_jalr;
wire Inst_ebreak;
wire load_type;
wire store_type;
wire branch_type;
wire op_type;
wire op_imm_type;

//指令类型的识别
assign load_type  = (opcode == 7'b0000011);
assign store_type = (opcode == 7'b0100011);
assign branch_type= (opcode == 7'b1100011);
assign op_imm_type= (opcode == 7'b0010011);
assign op_type    = (opcode == 7'b0110011);


assign R_type  = (opcode == 7'b0110011);
assign I_type  = (opcode == 7'b0010011) || (opcode == 7'b0011011) || load_type || Inst_jalr;
assign S_type  = store_type;
assign B_type  = branch_type;
assign U_type  = Inst_auipc | Inst_lui;
assign J_type  = Inst_jal;
assign NONE_type = ~(R_type|I_type|S_type|B_type|U_type|J_type);


//立即数的识别
wire [31:0] I_imm = {{20{inst[31]}}, inst[31:20]}; 
wire [31:0] S_imm = {{20{inst[31]}},	inst[31:25], inst[11:7]};
wire [31:0] B_imm = {{20{inst[31]}}, inst[7], inst[30:25], inst[11:8],1'b0};
wire [31:0] U_imm = {inst[31:12], 12'b0};  
wire [31:0] J_imm = {{12{inst[31]}}, inst[19:12], inst[20], inst[30:21], 1'b0};
assign imm   = I_type? I_imm : S_type? S_imm : B_type? B_imm : U_type? U_imm : J_type? J_imm : 32'b0;

//各种指令的识别
assign Inst_auipc  = (opcode == 7'b0010111);
assign Inst_lui    = (opcode == 7'b0110111);  

assign Inst_add	   = (opcode == 7'b0110011) && (funct3 == 3'b000) && (funct7 == 7'b0000000); 
assign Inst_and    = (opcode == 7'b0110011) && (funct3 == 3'b111) && (funct7 == 7'b0000000);
assign Inst_divu   = (opcode == 7'b0110011) && (funct3 == 3'b101) && (funct7 == 7'b0000001); 
assign Inst_div    = (opcode == 7'b0110011) && (funct3 == 3'b100) && (funct7 == 7'b0000001);
assign Inst_mul    = (opcode == 7'b0110011) && (funct3 == 3'b000) && (funct7 == 7'b0000001);  
assign Inst_mulh   = (opcode == 7'b0110011) && (funct3 == 3'b001) && (funct7 == 7'b0000001);   
assign Inst_mulhu  = (opcode == 7'b0110011) && (funct3 == 3'b011) && (funct7 == 7'b0000001);  
assign Inst_or     = (opcode == 7'b0110011) && (funct3 == 3'b110) && (funct7 == 7'b0000000);
assign Inst_rem    = (opcode == 7'b0110011) && (funct3 == 3'b110) && (funct7 == 7'b0000001);
assign Inst_remu   = (opcode == 7'b0110011) && (funct3 == 3'b111) && (funct7 == 7'b0000001); 
assign Inst_sub    = (opcode == 7'b0110011) && (funct3 == 3'b000) && (funct7 == 7'b0100000); 
assign Inst_sltu   = (opcode == 7'b0110011) && (funct3 == 3'b011) && (funct7 == 7'b0000000); 
assign Inst_sll    = (opcode == 7'b0110011) && (funct3 == 3'b001) && (funct7 == 7'b0000000);
assign Inst_slt    = (opcode == 7'b0110011) && (funct3 == 3'b010) && (funct7 == 7'b0000000);  
assign Inst_sra    = (opcode == 7'b0110011) && (funct3 == 3'b101) && (funct7 == 7'b0100000);
assign Inst_srl    = (opcode == 7'b0110011) && (funct3 == 3'b101) && (funct7 == 7'b0000000);
assign Inst_xor    = (opcode == 7'b0110011) && (funct3 == 3'b100) && (funct7 == 7'b0000000);  

assign Inst_beq    = (opcode == 7'b1100011) && (funct3 == 3'b000); 
assign Inst_bne    = (opcode == 7'b1100011) && (funct3 == 3'b001);
assign Inst_bge    = (opcode == 7'b1100011) && (funct3 == 3'b101); 
assign Inst_bgeu   = (opcode == 7'b1100011) && (funct3 == 3'b111);
assign Inst_blt    = (opcode == 7'b1100011) && (funct3 == 3'b100); 
assign Inst_bltu   = (opcode == 7'b1100011) && (funct3 == 3'b110);

assign Inst_sw     = (opcode == 7'b0100011) && (funct3 == 3'b010); 
assign Inst_sh     = (opcode == 7'b0100011) && (funct3 == 3'b001);
assign Inst_sb     = (opcode == 7'b0100011) && (funct3 == 3'b000);

assign Inst_addi   = (opcode == 7'b0010011) && (funct3 == 3'b000);
assign Inst_andi   = (opcode == 7'b0010011) && (funct3 == 3'b111);
assign Inst_jalr   = (opcode == 7'b1100111) && (funct3 == 3'b000);
assign Inst_lw     = (opcode == 7'b0000011) && (funct3 == 3'b010); 
assign Inst_lbu    = (opcode == 7'b0000011) && (funct3 == 3'b100);  
assign Inst_lh     = (opcode == 7'b0000011) && (funct3 == 3'b001); 
assign Inst_lb     = (opcode == 7'b0000011) && (funct3 == 3'b000); 
assign Inst_lhu    = (opcode == 7'b0000011) && (funct3 == 3'b101);    
assign Inst_ori    = (opcode == 7'b0010011) && (funct3 == 3'b110);
assign Inst_sltiu  = (opcode == 7'b0010011) && (funct3 == 3'b011);
assign Inst_slti   = (opcode == 7'b0010011) && (funct3 == 3'b010); 
assign Inst_srai   = (opcode == 7'b0010011) && (funct3 == 3'b101) && (funct7[6:1] == 6'b010000);
assign Inst_srli   = (opcode == 7'b0010011) && (funct3 == 3'b101) && (funct7[6:1] == 6'b000000);
assign Inst_slli   = (opcode == 7'b0010011) && (funct3 == 3'b001) && (funct7[6:1] == 6'b000000); 
assign Inst_xori   = (opcode == 7'b0010011) && (funct3 == 3'b100);
assign Inst_jal    = (opcode == 7'b1101111);
assign Inst_ebreak = (inst == 32'b00000000000100000000000001110011);


wire isNeed_imm = (I_type|S_type|B_type|U_type|J_type);
wire isNeed_rs1 = (R_type|I_type|S_type|B_type);
wire isNeed_rs2 = (R_type|S_type|B_type);
wire isNeed_rd  = (R_type|I_type|U_type|J_type);

assign rs1 = (isNeed_rs1) ? _rs1 : 5'b0;
assign rs2 = (isNeed_rs2) ? _rs2 : 5'b0;
assign rd  = (isNeed_rd)  ? _rd  : 5'b0;

//ALU_OP码分配
/*加减，逻辑*/
wire alu_add = Inst_add | Inst_addi | load_type
            | store_type | Inst_jal | Inst_jalr | Inst_auipc | Inst_lui;
wire alu_sub = Inst_sub;
wire alu_xor = Inst_xor | Inst_xori;
wire alu_and = Inst_and | Inst_andi;
wire alu_or  = Inst_or  | Inst_ori;
/*移位*/
wire alu_sll = Inst_sll | Inst_slli;
wire alu_srl = Inst_srl | Inst_srli;
wire alu_sra = Inst_sra | Inst_srai;
/*比较*/
wire alu_slt = Inst_slt | Inst_slti;
wire alu_sltu = Inst_sltu | Inst_sltiu;
wire alu_beq = Inst_beq;
wire alu_bne = Inst_bne;
wire alu_blt = Inst_blt;
wire alu_bge = Inst_bge;
wire alu_bltu = Inst_bltu;
wire alu_bgeu = Inst_bgeu;
/*乘法*/
wire alu_mul = Inst_mul;
wire alu_mulh = Inst_mulh;
wire alu_mulhu =Inst_mulhu;
/*除法*/
wire alu_div = Inst_div;
wire alu_divu = Inst_divu;
wire alu_rem = Inst_rem;
wire alu_remu = Inst_remu;

assign alu_op = alu_add ? 5'd1 :
                alu_sub ? 5'd2 :
                alu_xor ? 5'd3 :
                alu_or  ? 5'd4 :
                alu_and ? 5'd5 :
                alu_sll ? 5'd6 :
                alu_srl ? 5'd7 :
                alu_sra ? 5'd8 :
                alu_slt ? 5'd9 :
                alu_sltu? 5'd10:
                alu_beq ? 5'd11:
                alu_bne ? 5'd12:
                alu_blt ? 5'd13:
                alu_bge ? 5'd14:
                alu_bltu? 5'd15:
                alu_bgeu? 5'd16:
                alu_mul ? 5'd17:
                alu_mulh? 5'd18:
               alu_mulhu? 5'd19:
                alu_div ? 5'd20:
                alu_divu? 5'd21:
                alu_rem ? 5'd22:
                alu_remu? 5'd23:
                          5'd0;

assign ex_op = Inst_auipc ? 4'd1 :
               Inst_lui   ? 4'd2 :
               Inst_jal   ? 4'd3 :
               Inst_jalr  ? 4'd4 :
               load_type  ? 4'd5 :
               store_type ? 4'd6 :
               branch_type? 4'd7 :
               op_imm_type? 4'd8 :
               op_type    ? 4'd9 :
                            4'd0;

assign mem_op = Inst_lb  ? 4'd1 :
                Inst_lbu ? 4'd2 :
                Inst_lh  ? 4'd3 :
                Inst_lw  ? 4'd4 :
                Inst_lhu ? 4'd5 :
                Inst_sb  ? 4'd6 :
                Inst_sh  ? 4'd7 :
                Inst_sw  ? 4'd8 :
                           4'd0;

assign pc_op = B_type ? 4'd1 :
              Inst_jal? 4'd2 :
             Inst_jalr? 4'd3 :
             (inst == 32'b0) ? 4'd0 :
             4'd4;

endmodule
/* verilator lint_on UNUSED  */
