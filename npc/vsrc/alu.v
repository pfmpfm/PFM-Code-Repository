/* verilator lint_off UNUSED  */
module alu(
	input  [4:0] alu_op,
    input  [3:0] ex_op,
	input  [31:0] alu_src1,
	input  [31:0] alu_src2,
	output [31:0] alu_result,
	output compare_result
);

//ALU_OP码分配
/*加减，逻辑*/
wire op_add = (alu_op == 5'd1);
wire op_sub = (alu_op == 5'd2);
wire op_xor = (alu_op == 5'd3);
wire op_or  = (alu_op == 5'd4);
wire op_and = (alu_op == 5'd5);
/*移位*/
wire op_sll = (alu_op == 5'd6);
wire op_srl = (alu_op == 5'd7);
wire op_sra = (alu_op == 5'd8);
/*比较*/
wire op_slt = (alu_op == 5'd9);
wire op_sltu= (alu_op == 5'd10);
wire op_beq = (alu_op == 5'd11);
wire op_bne = (alu_op == 5'd12);
wire op_blt = (alu_op == 5'd13);
wire op_bge = (alu_op == 5'd14);
wire op_bltu= (alu_op == 5'd15);
wire op_bgeu= (alu_op == 5'd16);
/*乘法*/
wire op_mul   = (alu_op == 5'd17);
wire op_mulh  = (alu_op == 5'd18);
wire op_mulhu = (alu_op == 5'd19);
/*除法*/
wire op_div = (alu_op == 5'd20);
wire op_divu= (alu_op == 5'd21);
wire op_rem = (alu_op == 5'd22);
wire op_remu= (alu_op == 5'd23);

wire adder_cout; 
wire [31:0] adder_result;
wire [31:0] adder_a;
wire [31:0] adder_b;
wire [32:0] adder_cin;

wire isSUB = op_sub | op_slt | op_sltu
			 | op_bge | op_bgeu 
			 | op_blt | op_bltu ; 

assign adder_a   = alu_src1;
assign adder_b   = (isSUB) ? ~alu_src2 : alu_src2; 
assign adder_cin = (isSUB) ? 33'b1 : 33'b0;
assign {adder_cout, adder_result} = adder_a + adder_b + adder_cin;

wire slt_result = (alu_src1[31] & ~alu_src2[31])   
			  | ((alu_src1[31] ^ ~alu_src2[31]) & adder_result[31]); //为1则是有效
wire sltu_result = ~adder_cout; //为1则是有效

wire [63:0] mulh_64_result = {{32{alu_src1[31]}},alu_src1[31:0]} * {{32{alu_src2[31]}},alu_src2[31:0]};
wire [63:0] mulhu_64_result = {{32'b0},alu_src1[31:0]} * {{32'b0},alu_src2[31:0]};
wire [31:0] mulh_32_result = mulh_64_result[63:32];
wire [31:0] mulhu_32_result = mulh_64_result[63:32];

assign alu_result = (alu_op == 5'd1 || alu_op == 5'd2) ? adder_result :
                    (alu_op == 5'd3) ? (alu_src1 ^ alu_src2) :
                    (alu_op == 5'd4) ? (alu_src1 | alu_src2) :
                    (alu_op == 5'd5) ? (alu_src1 & alu_src2) :
                    (alu_op == 5'd6) ? (alu_src1 <<  alu_src2[4:0]) :
					(alu_op == 5'd7) ? (alu_src1 >>  alu_src2[4:0]) :
					(alu_op == 5'd8) ? ($signed(alu_src1) >>> alu_src2[4:0]) :
                    (alu_op == 5'd17) ? (alu_src1 * alu_src2) :
                    (alu_op == 5'd18) ? mulh_32_result :
                    (alu_op == 5'd19) ? mulhu_32_result :
                    (alu_op == 5'd20) ? $signed(alu_src1) / $signed(alu_src2) :
                    (alu_op == 5'd21) ? (alu_src1 / alu_src2) :
                    (alu_op == 5'd22) ? ($signed(alu_src1) % $signed(alu_src2)) :
                    (alu_op == 5'd23) ? (alu_src1 % alu_src2) :
                    (ex_op  == 4'd5 || ex_op  == 4'd6)  ? (alu_src1 + alu_src2) :
                    32'b0 ;


                    

assign compare_result = (alu_op == 5'd9) ? slt_result :
                        (alu_op == 5'd10) ? sltu_result :
                        (alu_op == 5'd11) ? (alu_src1 == alu_src2) :
                        (alu_op == 5'd12) ? (alu_src1 != alu_src2) :
                        (alu_op == 5'd13) ? slt_result :
                        (alu_op == 5'd14) ? ~slt_result :
                        (alu_op == 5'd15) ? sltu_result :
                        (alu_op == 5'd16) ? ~sltu_result :
                        1'b0;


endmodule
/* verilator lint_on UNUSED  */
