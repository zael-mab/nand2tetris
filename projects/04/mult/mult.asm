// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)


    @R0
    M=D

    @R1
    M=D

    @R2
    M=D

(LOOP)
    @
    M=0
    



    if r1 > r0
        t0 = r0 = 5 
        t1 = r1 = 20
    else
        t0 = r1
        t1 = r0
    x = 1
    while (x <= 5)
    {
        if (x == 1 && (x & 5))
            sum += 20;
        if (x & 5)
        {
            20 <= 20 << 1
            sum += t0
        }
        x = x + x
    }







///////////////////////////
//Desigb the program using pseudo code
//-Write the program in assembly language
//--test the program (on paper using a variable-value trace table)
//        |0| |1| |2| ...
// R1  =  |3| |3| |3| ...
// n   =  |3| |3| |3|
// i   =  |1| |2| |3|
// sum =  |1| |3| |6|


// r0[0..15] , r1[0..15], r2[0..15]=false, t[0..15]=false;


// t[i]+= r1[i] * r1[j]

//       10011  19
// x     10101  21
// =   --------
//       10011
//     10011xx
// + 10011xxxx
// =  --------
//   110001111
// Put your code here.



            // arr = 100
//     @100
//     D=A
//     @arr
//     M=D

//     @10    //n = 10
//     D=A
//     @n
//     M=D

//         // init i = 0
//     @i
//     M=0

// (LOOP)
//         // if i == n goto END
//     @i
//     D=M
//     @n
//     D=D-M
//     @END
//     D;JEQ   //if D == 0 goto End

//         // RAM[arr + i] = -1
//     @arr
//     D=M
//     @i
//     A=D+M
//     M=-1

//         // i++
//     @i
//     M=M+1

//     @LOOP
//     0;JMP

// (END)
//     @END
//     0;JMP