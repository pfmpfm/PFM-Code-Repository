
module WBU(
    input [31:0] ex_alu_data,
    input [31:0] mem_data,
    input load_valid,
    output [31:0] wb_data
);

assign wb_data = (load_valid) ? mem_data : ex_alu_data;


endmodule