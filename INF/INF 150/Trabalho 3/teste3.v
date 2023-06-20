module test(a, b, g,e);
input [5:0] a,b;
output g,e;

  wire [3:0] gi,ei;
  compNo M2(a[5],a[4],b[5],b[4],gi[3],ei[3]);
  compNo M1(a[3],a[2],b[3],b[2],gi[2],ei[2]);
  compNo M0(a[1],a[0],b[1],b[0],gi[1],ei[1]);
  compNt N1(gi[2],ei[2],gi[1],ei[1],gi[0],ei[0]);
  compNt N0(gi[3],ei[3],gi[0],ei[0],g,e);
endmodule


module compNo(a1,a0,b1,b0,G1,E1);
  input a1,a0,b1,b0;
  output GS,ES;
  assign GS = (~a0 & b0) | (~a1 & b1) | (a0 & ~b0) | (a1 & ~b1);
  assign ES = (~a1 & ~a0) | (~a1 & b0) | (~a1 & b1) | (~a0 & b1) | (b1 & b0);
endmodule

module compNt(gi,ei,go,eo,G2,E2);
  input gi,ei,go,eo;
  output G2,E2;
  assign G2 = (~gi & go) | (~ei & eo) | (gi & ~go) | (ei & ~eo);
  assign E2 = (~gi) | (~ei & go) | (go & eo);
endmodule

//module comp(a,b,gi,ei,go,eo);(gi,ei,go,eo,G2,E2);
//  input gi,ei,go,eo;
//  output G2,E2;
//	assign G2 = (~gi & ei) | (gi & ~ei) | (go);
//	assign E2 = (go & eo) | (~go & ~gi) | (~go & ei);
//endmodule