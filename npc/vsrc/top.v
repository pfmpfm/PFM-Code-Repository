/* verilator lint_off UNUSED  */

module top(
	input  clk,
	input  rst,
	output reg[31:0]debug_rs1_data,
	output reg[31:0]debug_rs2_data,
	output reg[31:0]debug_imm,
	output [31:0]debug_write_idx,
	output [31:0]debug_write_data,
	output reg[31:0]debug_rw_addr
);


always @(posedge clk) begin
	debug_rs1_data <= rs1_data;
	debug_rs2_data <= rs2_data;
	debug_imm <= imm;
    debug_write_idx <= {27'b0,rd_2};
    debug_write_data <= write_data;
	debug_rw_addr <= rw_addr;
end
//assign debug_write_idx  = {27'b0,rd_2};
//assign debug_write_data = mem_data;  // 直接连接，不经过寄存器

/**************PC**************/
reg [31:0] pc;
PC _pc(
	.clk(clk),
	.rst(rst),
	.pc_op(pc_op),
	.rs1_data(rs1_data),
	.imm(imm),
	.compare_result(compare_result),
	.pc(pc)
);

/**************IFU模块**************/
reg [31:0] inst;
IFU ifu(
	.clk(clk),
	.rst(rst),
	.pc(pc),
	.inst(inst)
);

/**************IDU模块**************/
/*输出的指令操作数*/
wire [4:0] rs1;
wire [4:0] rs2;
wire [4:0] rd;
wire [31:0] imm;

/*输出的控制信号*/
wire [4:0] alu_op;
wire [3:0] mem_op;
wire [3:0] ex_op;
wire [3:0] pc_op;

IDU idu(
	.inst(inst),
	.rs1(rs1),
	.rs2(rs2),
	.rd(rd),
	.imm(imm),
	.alu_op(alu_op),
	.mem_op(mem_op),
	.ex_op(ex_op),
	.pc_op(pc_op)
);

/**************Regfile**************/
wire [31:0] rs1_data;
wire [31:0] rs2_data;
wire [4:0] write_idx = rd_2;
wire [31:0] write_data = wb_data;

regfile Regfile(
	.clk(clk),
	.raddr1(rs1),
	.rdata1(rs1_data),
	.raddr2(rs2),
	.rdata2(rs2_data),
	.wen(1'b1), //一直写实能
	.waddr(write_idx),
	.wdata(write_data)

);

/**************EXU模块**************/
wire [31:0] ex_alu_data;
wire compare_result;

EXU exu(
	.pc(pc),
	.rd(rd),
	.rs1_data(rs1_data),
	.rs2_data(rs2_data),
	.imm(imm),
	.alu_op(alu_op),
	.ex_op(ex_op),
	.ex_alu_data(ex_alu_data),
	.compare_result(compare_result)
);

/**************MEM模块**************/
wire [31:0] mem_data;
wire load_valid;
reg [4:0] rd_2;
wire [31:0] read_data;

MEM mem(
	.clk(clk),
	.rst(rst),
	.pc(pc),
	.rd(rd),
	.rs2_data(rs2_data),
	.imm(imm),
	.mem_op(mem_op),
	.ex_alu_data(ex_alu_data),
	.mem_data(mem_data),
	.load_valid(load_valid),
	.rd_2(rd_2),
	.rw_addr(rw_addr),
	.read_data(read_data)
);


/**************WBU模块**************/
wire [31:0] wb_data;
wire [31:0] rw_addr;

WBU wbu(
	.ex_alu_data(ex_alu_data),
	.mem_data(mem_data),
	.load_valid(load_valid),
	.wb_data(wb_data)
);


endmodule
/* verilator lint_on UNUSED  */
