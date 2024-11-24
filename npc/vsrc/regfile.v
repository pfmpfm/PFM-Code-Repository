/* verilator lint_off UNUSED */
import "DPI-C" function void set_gpr_ptr(input logic [31:0] rf_ptr[]);

module regfile (
  input clk,
  input  [4:0] raddr1,
  output [31:0] rdata1,  
  input  [4:0] raddr2,
  output [31:0] rdata2,
  input  wen,
  input  [4:0] waddr,
  input  [31:0] wdata
);
  reg [31:0] rf [31:0];

  assign rdata1 = rf[raddr1];
  assign rdata2 = rf[raddr2];
  
  
  always @(posedge clk) begin
        rf[waddr] <= (waddr == 5'b0) ? 32'b0 : wdata;
  end
  

  initial set_gpr_ptr(rf); // 调用 DPI-C 函数

endmodule
/* verilator lint_on UNUSED */
