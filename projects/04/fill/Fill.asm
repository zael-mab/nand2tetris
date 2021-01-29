// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.



// 1 . i = 32 * row + col/16 => address
//      world = Screen[ 32*row + col/16 ]
//      world = RAM [ 16384 + 32*row + col/16 ]
// 2 . set the  (col%16)th   bit of word to 0 or 1
// 3 . Commit word to the RAM
/////////////////////////////////
// addr = SCREEN
// n = RAM[0]
// i = 0

// LOOP:
//      if  i > n  goto END
//      RAM[addr] = -1
    // advanced to the next row
//     addr = addr + 32
//     i = i + 1
//     goto LOOP

// END:
//     goto END
//////////////////////////////////


    @SCREEN
    D=A
    @addr
    M=D     //  addr = 16384 (screen's base address)

(LOOP)
    @KBD
    D=M
    @LOOP
    D;JGT
    @LOOP
    0;JMP