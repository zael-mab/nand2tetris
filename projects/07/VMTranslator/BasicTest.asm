//push constant 17
@17
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 17
@17
D=A
@0
A=M
M=D
@0
M=M+1
//eq
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@FALSE3
D;JNE
@0
A=M
MD=1
@GO
0;JMP
(FALSE3)
@0
A=M
M=0
(GO)
@0
M=M+1
//push constant 17
@17
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 16
@16
D=A
@0
A=M
M=D
@0
M=M+1
//eq
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@FALSE6
D;JNE
@0
A=M
MD=1
@GO
0;JMP
(FALSE6)
@0
A=M
M=0
(GO)
@0
M=M+1
//push constant 16
@16
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 17
@17
D=A
@0
A=M
M=D
@0
M=M+1
//eq
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@FALSE9
D;JNE
@0
A=M
MD=1
@GO
0;JMP
(FALSE9)
@0
A=M
M=0
(GO)
@0
M=M+1
//push constant 892
@892
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 891
@891
D=A
@0
A=M
M=D
@0
M=M+1
//lt
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@FALSE12
D;JGT
@0
A=M
MD=1
@GO
0;JMP
(FALSE12)
@0
A=M
M=0
(GO)
@0
M=M+1
//push constant 891
@891
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 892
@892
D=A
@0
A=M
M=D
@0
M=M+1
//lt
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@FALSE15
D;JGT
@0
A=M
MD=1
@GO
0;JMP
(FALSE15)
@0
A=M
M=0
(GO)
@0
M=M+1
//push constant 891
@891
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 891
@891
D=A
@0
A=M
M=D
@0
M=M+1
//lt
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@FALSE18
D;JGT
@0
A=M
MD=1
@GO
0;JMP
(FALSE18)
@0
A=M
M=0
(GO)
@0
M=M+1
//push constant 32767
@32767
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 32766
@32766
D=A
@0
A=M
M=D
@0
M=M+1
//gt
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@FALSE21
D;JLT
@0
A=M
MD=1
@GO
0;JMP
(FALSE21)
@0
A=M
M=0
(GO)
@0
M=M+1
//push constant 32766
@32766
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 32767
@32767
D=A
@0
A=M
M=D
@0
M=M+1
//gt
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@FALSE24
D;JLT
@0
A=M
MD=1
@GO
0;JMP
(FALSE24)
@0
A=M
M=0
(GO)
@0
M=M+1
//push constant 32766
@32766
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 32766
@32766
D=A
@0
A=M
M=D
@0
M=M+1
//gt
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@FALSE27
D;JLT
@0
A=M
MD=1
@GO
0;JMP
(FALSE27)
@0
A=M
M=0
(GO)
@0
M=M+1
//push constant 57
@57
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 31
@31
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 53
@53
D=A
@0
A=M
M=D
@0
M=M+1
//add
@0
AM=M-1
D=M
@0
AM=M-1
D=M+D
@0
A=M
M=D
@0
M=M+1
//push constant 112
@112
D=A
@0
A=M
M=D
@0
M=M+1
//sub
@0
AM=M-1
D=M
@0
AM=M-1
D=M-D
@0
A=M
M=D
@0
M=M+1
//neg
@0
AM=M-1
M=-M
@0
M=M+1//and
@0
AM=M-1
D=M
@0
AM=M-1
D=D&M
@0
A=M
M=D
@0
M=M+1
//push constant 82
@82
D=A
@0
A=M
M=D
@0
M=M+1
//or
@0
AM=M-1
D=M
@0
AM=M-1
D=D|M
@0
A=M
M=D
@0
M=M+1
//not
@0
A=M-1
M=!M