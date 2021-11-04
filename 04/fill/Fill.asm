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
// start counter at 0
@i
M=0
// loop resets after 8000 iterations
@ceiling
@8192
D=A
@ceiling
M=D

(LOOP)
  // if (i > ceiling) set i to 0
  @i
  D=M
  @ceiling
  D=D-M
  @0
  D;JGT
  // make RAM register for screen -1 so it is black if key pressed otherwise
  // white

  @KBD
  D=M
  @BLACK
  D;JNE
  
  // make RAM register 0 (white)
  @i
  D=M
  @SCREEN
  A=D+A
  M=0
  @inc
  0;JMP

  // make ram register -1 (black)
  (BLACK)
  @i
  D=M
  @SCREEN
  A=D+A
  M=-1

  // increment i 
  (inc)
  @i
  M=M+1
  @LOOP
  0;JMP