module test(a, b, g,e);
input [9:0] a,b;
output g,e;

  wire [7:0] gi,ei;
  compNo M4(a[9],a[8],b[9],b[8],gi[5],ei[5]);
  compNo M3(a[7],a[6],b[7],b[6],gi[4],ei[4]);
  compNo M2(a[5],a[4],b[5],b[4],gi[3],ei[3]);
  compNo M1(a[3],a[2],b[3],b[2],gi[2],ei[2]);
  compNo M0(a[1],a[0],b[1],b[0],gi[1],ei[1]);
  
  compNt N3(gi[2],ei[2],gi[1],ei[1],gi[7],ei[7]);
  compNt N2(gi[4],ei[4],gi[3],ei[3],gi[6],ei[6]);
  compNt N1(gi[6],ei[6],gi[7],ei[7],gi[0],ei[0]);
  compNt N0(gi[5],ei[5],gi[0],ei[0],g,e);
endmodule


module compNo(a1,a0,b1,b0,G1,E1);
  input a1,a0,b1,b0;
  output G1,E1;
  assign G1 = (~a0 & b0) | (~a1 & b1) | (a0 & ~b0) | (a1 & ~b1);
  assign E1 = (~a1 & ~a0) | (~a1 & b0) | (~a1 & b1) | (~a0 & b1) | (b1 & b0);
endmodule

module compNt(gi,ei,go,eo,G2,E2);
  input gi,ei,go,eo;
  output G2,E2;
  assign G2 = (go) | (gi);
  assign E2 = (gi & ei) | (~gi & eo);
endmodule

module logic_testbench();
reg [19:0] counter;
wire g,e;

integer k;
	test t(counter[19:10],counter[9:0],g,e);
	initial begin

//module comp(a,b,gi,ei,go,eo);(gi,ei,go,eo,G2,E2);
//  input gi,ei,go,eo;
//  output G2,E2;
//	assign G2 = (~gi & ei) | (gi & ~ei) | (go);
//	assign E2 = (go & eo) | (~go & ~gi) | (~go & ei);
//endmodule