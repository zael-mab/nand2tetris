// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
    
    @R2
    M=0
    @x
    M=1

    @R0
    D=M
    @R1
    D=M

    @R0
    D=D-M
    @LOOP
    D;JGT
    @R1
    D=M
    @tmp
    M=D
    @R0
    D=M
    @R1
    M=D
    @tmp
    D=M
    @R0
    M=D


(LOOP)
    @R0
    D=M
    @x
    D=M&D
    @INCR
    D;JLE

    @R1
    D=M
    @R2
    M=M+D

(INCR)

    @R1
    D=M
    @R1
    M=D+M

    @x
    D=M
    @x
    M=D+M

    @R0
    D=M
    @x
    D=D-M
    @LOOP
    D;JGE

(END)
    @END
    0;JMP
