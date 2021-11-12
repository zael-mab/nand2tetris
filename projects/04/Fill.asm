    @k
    M=0

(TOP)
    @x
    M=0
    @k
    D=M
    @INIT_K
    D;JGT

    @8192
    D=A
    @lim
    M=D

    @KBD
    D=M
    @k
    MD=D
    @BLACK_SCREEN
    D;JGT

    @TOP
    0;JMP

(BLACK_SCREEN)
    @x
    D=M
    @SCREEN
    A=D+A
    M=-1
    @x
    MD=D+1
    @lim
    D=M-D
    @BLACK_SCREEN
    D;JGT

(KEEP_IT_BALCK)
    @KBD
    D=M
    @KEEP_IT_BALCK
    D;JGT
    @TOP
    0;JEQ

(CLEAR_SCREEN)
    @x
    D=M
    @SCREEN
    A=D+A
    M=0
    @x
    MD=D+1
    @lim
    D=M-D
    @TOP
    D;JEQ
    @CLEAR_SCREEN
    0;JMP

(INIT_K)
    @k
    M=0
    @CLEAR_SCREEN
    0;JMP