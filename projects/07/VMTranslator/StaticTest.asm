//push constant 111
@111
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 333
@333
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 888
@888
D=A
@0
A=M
M=D
@0
M=M+1
//pop static 8
@0
AM=M-1
D=M
@StaticTest.asm.8
M=D
//pop static 3
@0
AM=M-1
D=M
@StaticTest.asm.3
M=D
//pop static 1
@0
AM=M-1
D=M
@StaticTest.asm.1
M=D
//push static 3
@StaticTest.asm.3
D=M
@0
A=M
M=D
@0
M=M+1
//push static 1
@StaticTest.asm.1
D=M
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
//push static 8
@StaticTest.asm.8
D=M
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
