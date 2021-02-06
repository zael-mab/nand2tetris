
    @R0
    D=M

    @R1
    D=M

    @R2
    M=0

    @x
    M=0

(LOOP)
    
    @x
    M=M+1
    @R1
    D=M
    @R2
    M=D+M
    
    @x
    D=M
    @R0
    D=M-D
    @LOOP
    D;JGT

(END)
    @END
    0;JMP
