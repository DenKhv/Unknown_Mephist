// See file src/basics-graphics-music/LICENSE
// Simplified version by Boris Matveev (c) Orion
// Original file moved to tb.sv_fpga
module tb;

    logic [1:0]  in;
    logic [3:0]  out[4];
    //------------------------------------------------------------------------

    top i_top
    (
        .in      ( in  ),
        .out     ( out )
    );

    //------------------------------------------------------------------------
    // Create checking task as in mux example
    task check (input[1:0] in);

    endtask


    initial
    begin
        $dumpvars;
        repeat (8)
        begin
             # 10
             in <= $urandom ();
        end
        check(in);
        $finish;
    end

endmodule
