
module top

( input [2:0] in,
output [7:0] out
);

assign out = 8'b1 << in;
endmodule

/*module top_b
( input [2:0] in,
output [7:0]
);
always @(*)
begin
    if(in==3'b0)
    out = 8'b1;
    else if(in==3'b1)
    out = 8'b2;
    else if(in==3'b2)
    out = 8'b4;
    else if(in==3'b3)
    out = 8'b8;
    else if(in==3'b4)
    out = 8'b16;
    else if(in==3'b5)
    out = 8'b32;
    else if(in==3'b6)
    out = 8'b64;
    else if(in==3'b7)
    out = 8'b128;
end
endmodule

module top_v
( input [2:0] in,
output [7:0] out
);
always @(*)
begin
    case(in)
    0: out = 8'b1;
    1: out = 8'b2;
    2: out = 8'b4;
    3: out = 8'b8;
    4: out = 8'b16;
    5: out = 8'b32;
    6: out = 8'b64;
    7: out = 8'b128;
    endcase
end

endmodule

module top_g
( input [2:0] in,
output [7:0] out
);
assign out = 
   (in==0) ? 8'b1
 : (in==1) ? 8'b2 
 : (in==2) ? 8'b4
 : (in==3) ? 8'b8 
 : (in==4) ? 8'b16 
 : (in==5) ? 8'b32 
 : (in==6) ? 8'b64
 : (in==7) ? 8'b128

endmodule

module top_d
( input [2:0] in,
output [7:0] out
);
assign out[0] = ~(in[2]&in[1]&in[0]);
assign out[1] = ~in[2]&~in[1]&in[0];
assign out[2] = ~in[2]&in[1]&~in[0];
assign out[3] = ~in[2]&in[1]&in[0];
assign out[4] = in[2]&~in[1]&~in[0];
assign out[5] = in[2]&~in[1]&in[0];
assign out[6] = in[2]&in[1]&~in[0];
assign out[7] = in[2]&in[1]&in[0];

endmodule