# Tic-Tac-Toe-on-Arduino
Tic Tac Toe made on `arduino mega 2560` with a `touch screen 3.5" TFTLCD for arduino 2560 from mcufriend.com`.The source code includes all the necessary libraries needed for the project to work.
 This project have many features including the 2 player option so that 2 players can play tic tac toe with each other and also the one player option, which is controlled by a simple Ai.
### Note
I have only tried this with arduino mega 2560 and touch screen 3.5" TFTLCD for arduino 2560 from mcufriend.com.If you have any other arduino or touch screen your configuration may differ.One important thing to change is 
`UTFT    myGLCD(R61581, 38, 39, 40, 41); //3.5" TFTLCD for arduino 2560 from mcufriend.com`
Line 23 on Tic-tac.ino file.To match the code with yours touch screen.i.e `R61581` and the configurations pins.
## Working
Mount the TFTLLCD on the arduino mega 2560 such that all the pins of TFTLCD are inserted in the arduino mega properly.Then extract the libraries.zip and then upload the Tic-tac.ino to the arduino and enjoy the Tic Tac Toe on your arduino.
