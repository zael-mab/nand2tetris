
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
    //check if R0 > R1
    @R0
    D=M-D
    @SEC    // if (R0 < R1) goto SEC
    D;JGT
    // initiate x with R0
    @R0
    D=M
    @x
    M=D

    // FLIP R1 AND R0
    // r0 = r1
    @R1
    D=M
    @R0
    M=D
    // r1 = x
    @x
    D=M
    @R1
    M=D
    
    @LOOP
    0;JMP

(SEC)
    // initiate x with R1
    @R1
    D=M
    @x
    M=D


// WHILE
(LOOP)
    @R0
    D=M
    @R2
    M=D+M
    @x
    MD=M-1
    @LOOP       // if x > 0 goto LOOP else goto END
    D;JGT

(END)
    @END
    0;JMP

