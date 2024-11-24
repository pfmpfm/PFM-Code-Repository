import "DPI-C" function void mem_write(int waddr, int wdata, int len);
import "DPI-C" function int mem_read(int raddr, int len);


module MEM(
    input clk,
    input rst,
    input [31:0] pc,
    input [4:0] rd,
    input [31:0] rs2_data,
    input [31:0] imm,
    input [3:0] mem_op,
    input [31:0] ex_alu_data,
    output [31:0] mem_data,
    output load_valid,
    output reg [4:0] rd_2,
    output [31:0]rw_addr,
    output [31:0] read_data
);

wire op_none = (mem_op == 4'd0);
wire op_lb   = (mem_op == 4'd1);
wire op_lbu  = (mem_op == 4'd2);
wire op_lh   = (mem_op == 4'd3);
wire op_lw   = (mem_op == 4'd4);
wire op_lhu  = (mem_op == 4'd5);
wire op_sb   = (mem_op == 4'd6);
wire op_sh   = (mem_op == 4'd7);
wire op_sw   = (mem_op == 4'd8);

wire isLoad = (op_lb | op_lbu | op_lh | op_lhu | op_lw) & ~op_none;
wire isStore= (op_sb | op_sh | op_sw) & ~op_none;

wire is1byte = op_lb | op_lbu | op_sb;
wire is2byte = op_lh | op_lhu | op_sh;
wire is4byte = op_lw | op_sw;

wire unsigned_load = op_lhu | op_lbu;
wire signed_load   = op_lh  | op_lb | op_lw;

assign load_valid  = unsigned_load | signed_load;


wire [31:0] signed_mem_data = (is1byte) ? {{24{read_data[7]}}, read_data[7:0]} :
                              (is2byte) ? {{16{read_data[15]}}, read_data[15:0]} :
                              (is4byte) ? read_data : read_data;

wire [31:0] unsigned_mem_data = (is1byte) ? {{24{1'b0}}, read_data[7:0]} :
                                (is2byte) ? {{16{1'b0}}, read_data[15:0]} :
                                (is4byte) ? read_data : read_data;

assign mem_data = signed_load ? signed_mem_data :
                  unsigned_load ? unsigned_mem_data :
                  32'b0;                                

/* 写入数据 */
wire [31:0] write_data = (is1byte) ? {24'b0, rs2_data[7:0]} :
                         (is2byte) ? {16'b0, rs2_data[15:0]} :
                         (is4byte) ? rs2_data : rs2_data;

always @(posedge clk) begin
    rd_2 = rd;
end

assign rw_addr   = op_none ? 32'b0 : ex_alu_data;
wire [31:0] len  =  (is1byte) ? 32'd1 : (is2byte) ? 32'd2 : (is4byte) ? 32'd4 : 32'd4;
assign read_data = (rw_addr != 32'b0 && load_valid) ? mem_read(rw_addr, len) : 32'b0;


always @(*) begin
    if(rw_addr != 32'b0) begin
        //if(load_valid) read_data <= mem_read(rw_addr);
        if(isStore) mem_write(rw_addr, write_data, len);
    end
end

endmodule
