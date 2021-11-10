//      while (i < n)
//          arr[i] = -1
    
    
    // arr = 100
    @100
    D=A
    @arr
    M=D

    // n = 10
    @10
    D=A
    @n
    M=D

    // i = 0
    @0
    D=A
    @i
    M=D



(LOOP)
    //  i < n
    @i
    D=M
    @n
    D=M-D
    @END
    D;JEQ

    @i
    D=M
    // arr[i] = -1
    @arr 
    A=D+M
    M=-1
    // i++
    @i
    M=D+1

    @LOOP
    0;JMP

(END)
    @END
    0;JMP