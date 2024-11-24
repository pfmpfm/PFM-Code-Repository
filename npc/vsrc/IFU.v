
import "DPI-C" function void itrace(int inst);


module IFU(
    input clk,
    input rst,  // 添加复位信号
    input [31:0] pc,
    output reg [31:0] inst
);
    
    always @(posedge clk) begin
         if(pc!=32'b0) inst = mem_read(pc, 4);
    end

    always @(negedge clk) begin
        if (!rst) begin  // 非复位状态才记录
            itrace(inst);
        end
    end

endmodule


