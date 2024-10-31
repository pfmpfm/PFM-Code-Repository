/* verilator lint_off UNUSED */
import "DPI-C" function void set_gpr_ptr(input logic [31:0] rf_ptr[]);

module regfile (
  input clk,
  input  [31:0] wdata,
  input  [4:0] waddr,
  input  [4:0] raddr,
  output reg [31:0] rdata,
  output reg [31:0] rf [31:0], 
  input  wen
);
    
  always @(posedge clk) begin
    if (wen) 
      rf[waddr] <= wdata;
    else 
      rdata <= rf[raddr];
  end

  initial begin
    set_gpr_ptr(rf); // 调用 DPI-C 函数
  end

endmodule
/* verilator lint_on UNUSED */

