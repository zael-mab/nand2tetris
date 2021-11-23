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
AM=M-1
D=M
@3
M=D
//push constant 4030
@4030
D=A
@0
A=M
M=D
@0
M=M+1
//pop this 1
@1
D=A
@3
M=M+D
@0
AM=M-1
D=M
@3
A=M
M=D
@1
D=A
@3
M=M-D
//push constant 2030
@2030
D=A
@0
A=M
M=D
@0
M=M+1
//push pointer 1
@4
D=M
@0
A=M
M=D
@0
M=M+1
//push constant 1030
@1030
D=A
@0
A=M
M=D
@0
M=M+1
//pop that 3
@3
D=A
@4
M=M+D
@0
AM=M-1
D=M
@4
A=M
M=D
@3
D=A
@4
M=M-D
//push this 3
@3
D=A
@3
A=M+D
D=M
@0
A=M
M=D
@0
M=M+1
//push constant 3050
@3050
D=A
@0
A=M
M=D
@0
M=M+1
//push pointer 0
@3
D=M
@0
A=M
M=D
@0
M=M+1
//push constant 1080
@1080
D=A
@0
A=M
M=D
@0
M=M+1
//pop that 2
@2
D=A
@4
M=M+D
@0
AM=M-1
D=M
@4
A=M
M=D
@2
D=A
@4
M=M-D