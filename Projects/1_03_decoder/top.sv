// See file src/basics-graphics-music/LICENSE
// Simplified version by Boris Matveev (c) Orion
// Original file moved to top.sv_fpga
module top(
    input[1:0] in,
    output [3:0] out[4]
);

    //------------------------------------------------------------------------

    // Implementation 1: tedious

    wire [3:0] dec0;

    assign dec0 [0] = ~ in [1] & ~ in [0];
    assign dec0 [1] = ~ in [1] &   in [0];
    assign dec0 [2] =   in [1] & ~ in [0];
    assign dec0 [3] =   in [1] &   in [0];

    // Implementation 2: case

    logic [3:0] dec1;

    always_comb
        case (in)
        2'b00: dec1 = 4'b0001;
        2'b01: dec1 = 4'b0010;
        2'b10: dec1 = 4'b0100;
        2'b11: dec1 = 4'b1000;
        endcase

    // Implementation 3: shift

    wire [3:0] dec2 = 4'b0001 << in;

    // Implementation 4: index

    logic [3:0] dec3;

    always_comb
    begin
        dec3 = '0;
        dec3 [in] = 1'b1;
    end

    //------------------------------------------------------------------------
    assign out[0] = dec0;
    assign out[1] = dec1;
    assign out[2] = dec2;
    assign out[3] = dec3;

endmodule
