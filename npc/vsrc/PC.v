import "DPI-C" function void read_pc(int pc); 

module PC(
    input clk,
    input rst,
    input [3:0] pc_op,
    input [31:0] rs1_data,
    input [31:0] imm,
    input compare_result,
    output reg [31:0] pc
);

wire none   = (pc_op == 4'd0);
wire branch = (pc_op == 4'd1);
wire jal    = (pc_op == 4'd2);
wire jalr   = (pc_op == 4'd3);
wire inc4   = (pc_op == 4'd4);

wire is_branch = compare_result & branch;
wire is_inc4   = inc4 | ((~is_branch) & branch);

reg [31:0] current_pc;

wire [31:0] pc_a = ({32{jal | none | is_branch | is_inc4}} & current_pc)
            | ({32{jalr}} & rs1_data);
wire [31:0] pc_b = ({32{is_branch | jal | jalr}} & imm)
            | ({32{none}} & 32'd0)
            | ({32{is_inc4}} & 32'd4);

wire [31:0] next_pc;
assign next_pc = pc_a + pc_b;

always @(posedge clk) begin
    if (rst) current_pc = 32'h80000000;
    else current_pc = next_pc;
end

always @(negedge clk) begin
    read_pc(next_pc);
end

assign pc = current_pc;

endmodule
