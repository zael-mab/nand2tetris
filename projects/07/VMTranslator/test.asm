//push constant 10
@10
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 21
@21
D=A
@0
A=M
M=D
@0
M=M+1
//pop local 0
@0
D=A
@1
M=M+D
@0
AM=M-1
D=M
@1
A=M
M=D
@0
D=A
@1
M=M-D
//push constant 22
@22
D=A
@0
A=M
M=D
@0
M=M+1
//push constant 36
@36
D=A
@0
A=M
M=D
@0
M=M+1
//pop argument 2
@2
D=A
@2
M=M+D
@0
AM=M-1
D=M
@2
A=M
M=D
@2
D=A
@2
M=M-D
//push constant 42
@42
D=A
@0
A=M
M=D
@0
M=M+1
//pop this 6
@6
D=A
@3
M=M+D
@0
AM=M-1
D=M
@3
A=M
M=D
@6
D=A
@3
M=M-D
//push constant 45
@45
D=A
@0
A=M
M=D
@0
M=M+1
//pop that 5
@5
D=A
@4
M=M+D
@0
AM=M-1
D=M
@4
A=M
M=D
@5
D=A
@4
M=M-D
//push constant 510
@510
D=A
@0
A=M
M=D
@0
M=M+1
//push temp 6
@11
D=M
@0
A=M
M=D
@0
M=M+1
//push local 0
@0
D=A
@1
A=M+D
D=M
@0
A=M
M=D
@0
M=M+1
//push that 5
@5
D=A
@4
A=M+D
D=M
@0
A=M
M=D
@0
M=M+1
//push argument 1
@1
D=A
@2
A=M+D
D=M
@0
A=M
M=D
@0
M=M+1
//push this 6
@6
D=A
@3
A=M+D
D=M
@0
A=M
M=D
@0
M=M+1
//pop temp 6
@0
AM=M-1
D=M
@11
M=D