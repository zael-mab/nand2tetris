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

(LOOP)

    @SCREEN
    D=A
    @address        // address = 16384 (screen’s base address)
    M=D

    @8192           // last address of the Screen memory map
    D=A
    @x
    M=D
    
    @i              // i = 0  
    M=0

    @KBD            // address of the keyboard memory map
    D=M
    @DRAW
    D;JGT

(CLEAR)

    @address
    D=M
    
    @i
    A=D+M
    M=0             //  Screen[i] = 0  (white pixl)
    
    @i
    M=M+1           //  i += 1
    
    @i
    D=M
    @x
    D=D-M           //  if  i < 8192
    @CLEAR          //  then: goto CLAER
    D;JLT

    @LOOP           //  else: goto LOOP
    0;JMP


(DRAW)

    @address
    D=M
    
    @i
    A=D+M
    M=-1            //  Screen[i] = -1 (1111111111111111 = Black pixl)
    
    @i
    M=M+1           // i += 1
    
    @i
    D=M
    @x
    D=D-M           //if  i < 8192
    @DRAW           //  then: goto DRAW
    D;JLT

    @LOOP           //  else: goto LOOP
    0;JMP