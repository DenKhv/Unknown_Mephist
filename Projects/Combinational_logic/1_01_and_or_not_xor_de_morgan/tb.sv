module tb;

logic [2:0] in;
logic [7:0] out;

top i_top
(
.in (in),
.out (out)
);

initial
begin 
    $dumpvars;
    repeat(10)
    begin 
        in <= $urandom();
    end
  
  /*tb_b
  initial
  begin 
    $dumpvars;
    repeat(10)
    begin 
        for(integer in=0; in <= 3'b111; in++)
    end
  
  */


end
endmodule

