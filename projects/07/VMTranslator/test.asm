//push constant 3030
@3030
D=A
@0
A=M
M=D
@0
M=M+1
//pop pointer 0
@0
D=A
@3
M=M+D
@0
AM=M-1
D=M
@3
A=M
M=D
@0
D=A
@3
M=M-D
//push constant 4030
@4030
D=A
@0
A=M
M=D
@0
M=M+1
//pop pointer 1
@1
D=A
@4
M=M+D
@0
AM=M-1
D=M
@4
A=M
M=D
@1
D=A
@4
M=M-D