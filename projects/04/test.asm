// Mutiplies R0 and R1 and stores the results in R2
// (R0, R1, R2 refer to RAM[0], RAM[1] and RAM[2], respectively.)


    @R0
    D=M
    @R1
    D=M+D
    @R2
    M=D

(END)
    @END
    0;JMP