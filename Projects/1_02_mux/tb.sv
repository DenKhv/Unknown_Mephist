// see file src/basics-graphics-music/LICENSE
// Simplified version by Boris Matveev (c) Orion
// Original file moved to tb.sv_fpga
module tb;

    logic a;
    logic b;
    logic sel;
    logic[7:0] mux;

    top i_top
    (
        .a        ( a ),
        .b        ( b ),
        .sel      ( sel ),
        .mux      ( mux )
    );

    //------------------------------------------------------------------------
    // Exercise 1: modify check task to display when check is correct.


    task check (input sel, a, b);

        logic result, expected;
        int n_muxes_to_check;

        // Black-box testing - checking the output
        result   = mux [0];
        expected = sel ? a : b;

        if (result !== expected)
            $display ("Mismatch: %b ? %b : %b. expected: %b actual: %b",
                sel, a, b, expected, result);

        //--------------------------------------------------------------------
        // Checking multiple bits
        // Exercise 2: modify code below to make "check" task check all muxes.
        // It should also display when check is correct.

        // n_muxes_to_check = $bits (mux);

        // for (int i = 0; i < n_muxes_to_check; i ++) beign

        //end
    endtask

    //------------------------------------------------------------------------

    // The stimulus generation

    initial
    begin
        $dumpvars;

        // Exhaustive direct testing aka brute force testing

        for (int isel = 0; isel <= 1; isel ++)
        for (int ia   = 0; ia   <= 1; ia   ++)
        for (int ib   = 0; ib   <= 1; ib   ++)
        begin
             sel = isel;
             a   = ia  ;
             b   = ib  ;

             # 10

             check (sel, a, b);
        end

        // Another way of doing it

        for (int i = 0; i < 8; i ++)
        begin
             {sel,a,b} = i;
             
             # 10

             check (sel, a, b);
        end

        // Randomized testing

        repeat (8)
        begin
             # 10

             sel =  $urandom ();
             a   =  $urandom ();
             b   =  $urandom ();

             check (sel, a, b);
        end

        $finish;
    end

endmodule
