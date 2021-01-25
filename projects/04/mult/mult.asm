// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)

///////////////////////////
//Desigb the program using pseudo code
//-Write the program in assembly language
//--test the program (on paper using a variable-value trace table)
//        |0| |1| |2| ...
// R1  =  |3| |3| |3| ...
// n   =  |3| |3| |3|
// i   =  |1| |2| |3|
// sum =  |1| |3| |6|

// 1 . i = 32 * row + col/16 => address
//      world = Screen[ 32*row + col/16 ]
//      world = RAM [ 16384 + 32*row + col/16 ]
// 2 . set the  (col%16)th   bit of word to 0 or 1
// 3 . Commit word to the RAM

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
    @100
    D=A
    @arr
    M=D

    @10    //n = 10
    D=A
    @n
    M=D

        // init i = 0
    @i
    M=0

(LOOP)
        // if i == n goto END
    @i
    D=M
    @n
    D=D-M
    @END
    D;JEQ

        // RAM[arr + i] = -1
    @arr
    D=M
    @i
    A=D+M
    M=-1

        // i++
    @i
    M=M+1

    @LOOP
    0;JMP

(END)
    @END
    0;JMP