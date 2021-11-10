
// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)



    // intial R2, R2 = 0
    @R2
    M=0
    // check r0 and r1
    @R0
    D=M
    @END
    D;JEQ

    @R1
    D=M
    @END
    D;JEQ
    //
    @R0
    D=M-D
    @SEC
    D;JGT
    // initiate x with R0
    @R0
    D=M
    @x
    M=D
    @R1
    D=M
    @val
    M=D
    @LOOP
    0;JMP

(SEC)
    // initiate x with R1
    @R1
    D=M
    @x
    M=D
    @R0
    D=M
    @val
    M=D


// WHILE
(LOOP)
    @x      // if x == 0 goto END
    D=M
    @END
    D;JEQ
    @val
    D=M
    @R2
    M=D+M
    @x
    MD=M-1
    @LOOP
    D;JGT

(END)
    @END
    0;JMP

