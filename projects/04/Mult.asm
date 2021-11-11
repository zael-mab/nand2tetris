// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

// init R2 = 0
    @R2
    M=0
    @holder1
    M=0
    @holder2
    M=0
// check R1 and R0
    @R0
    D=M
    @END
    D;JEQ

    @R1
    D=M
    @END
    D;JEQ




    @R0
    D=M
    @MINS
    D;JLT

(CHECK)
    @R1
    D=M
    @MINS_P
    D;JLT

    

(INIT)
// flip R1 and R0
    @R0
    D=M-D
    @FLIP
    D;JGT

// init x  and R2
    @R0
    D=M
    @x
    M=D
    @LOOP
    0;JMP

(FLIP)
    @R1
    D=M
    @x
    M=D
    
    @R0
    D=M
    @R1
    M=D
    
    @x
    D=M
    @R0
    M=D


// Loop
(LOOP)
    @R1
    D=M
    @R2
    M=M+D
    @x
    MD=M-1
    @LOOP
    D;JGT

    @holder0
    D=M
    @holder1
    D=M-D
    @RES
    D;JGT
    
(CHECK_PP)
    @holder0
    D=M
    @PLUS
    D;JLT

(CHECK_P)
    @holder1
    D=M
    @PLUS_P
    D;JLT


(END)
    @END
    0;JMP

(RES)
    @R2
    M=-M
    @CHECK_PP
    0;JMP

///// HANDELING NEGATIVE
(MINS)
    @holder0
    M=-1
    @R0
    M=-M
    @CHECK
    0;JMP

(MINS_P)
    @holder1
    M=-1
    @R1
    M=-M
    @INIT
    0;JMP

(PLUS)
    @R0
    M=-M
    @CHECK_P
    0;JMP

(PLUS_P)
    @R1
    M=-M
    @END
    0;JMP
