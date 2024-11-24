
module EXU(
    input [31:0] pc,
    input [4:0] rd,
    input [31:0] rs1_data,
    input [31:0] rs2_data,
    input [31:0] imm,
    input [4:0] alu_op,
    input [3:0] ex_op,
    output [31:0] ex_alu_data,
    output compare_result
);

wire op_auipc = (ex_op == 4'd1);
wire op_lui   = (ex_op == 4'd2);
wire op_jal   = (ex_op == 4'd3);
wire op_jalr  = (ex_op == 4'd4);
wire op_branch   = (ex_op == 4'd7);
wire op_imm_type = (ex_op == 4'd8);
wire op_op_type  = (ex_op == 4'd9);
wire op_load_type  = (ex_op == 4'd5);
wire op_store_type = (ex_op == 4'd6);

wire rs1_rs2 = op_op_type | op_branch;
wire rs1_imm = op_imm_type | op_load_type | op_store_type;
wire pc_4    = op_jal | op_jalr;
wire pc_imm12 = op_auipc;
wire none_imm12 = op_lui;
   

wire [31:0] imm12 = {imm[31:12],12'b0};
wire [31:0] alu_src1  = (rs1_rs2 || rs1_imm) ? rs1_data :
                        (pc_4 || pc_imm12) ? pc :
                        (none_imm12) ? 32'b0 :
                        32'b0;

wire [31:0] alu_src2  = (rs1_rs2) ? rs2_data :
                        (rs1_imm) ? imm :
                        (pc_4) ? 32'd4 :
                        (pc_imm12 || none_imm12) ? imm12 :
                        32'b0;


wire [31:0] alu_result;

alu ALU(
    .alu_op(alu_op),
    .ex_op(ex_op),
    .alu_src1(alu_src1),
    .alu_src2(alu_src2),
    .alu_result(alu_result),
    .compare_result(compare_result)
);

assign ex_alu_data = alu_result | {31'b0, compare_result};




endmodule