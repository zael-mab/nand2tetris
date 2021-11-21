
@i
D=M

@local      
AM=M+D      //addr = local + i
D=M         // D = *addr

@sp         //  *sp = D
A=M
M=D
@sp         //  
M=M+1
