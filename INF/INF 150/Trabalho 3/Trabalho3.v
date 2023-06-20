%%verilog
module test(a, b, g,e, G,E);
	input [5:0] a,b;
	output g,e,G,E;
	// alto nivel
	assign G = a>b;
	assign E = a == b;
	// com modulos
	wire [5:0] gi,ei;
	comp M5(a[5],b[5],1'b0,1'b1,gi[5],ei[5]);
	comp M4(a[4],b[4],gi[5],ei[5],gi[4],ei[4]);
	comp M3(a[3],b[3],gi[4],ei[4],gi[3],ei[3]);
	comp M2(a[2],b[2],gi[3],ei[3],gi[2],ei[2]);
	comp M1(a[1],b[1],gi[2],ei[2],gi[1],ei[1]);
	comp M0(a[0],b[0],gi[1],ei[1],g,e);

endmodule

module comp(a,b,gi,ei,go,eo);
	input a,b,gi,ei;
	output go,eo;
	assign go = (~a & b) | (a & ~b) | (gi);
	assign eo = (gi & ei) | (~gi & ~a) | (~gi & b);
endmodule

module logic_testbench();
	reg [11:0] counter;
	wire g,e,G,E;
	reg falha;

	integer k;
	test t(counter[11:6],counter[5:0],g,e,G,E);
	initial begin
		counter = 0;
		falha = 0;
		for (k=1; k<4096; k=k+1)
	  	begin
     	#1
		if ( (g !== G || e !== E) && G !== E ) falha = 1;
		if ( (g !== G || e !== E) && G !== E ) 
			$display("line!%d : a=%d | b=%d | g=%b | G=%b | e=%b | E=%b", counter, counter[11:6], counter[5:0], g,G,e,E);
		#1 counter = k;
		end
    	$display("Falha = %b", falha);
		$finish;
	end
endmodule