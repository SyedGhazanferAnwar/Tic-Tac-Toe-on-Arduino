//
// This program requires the UTFT library.
//
// It is assumed that the display module is connected to an
// appropriate shield or that you know how to change the pin
// numbers in the setup.
//

#include <UTFT.h>
#include <UTouch.h>

// Initialize display
// ------------------
// Set the pins to the correct ones for your development board
// -----------------------------------------------------------
// Standard Arduino Uno/2009 Shield            : <display model>,19,18,17,16
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
// CTE TFT LCD/SD Shield for Arduino Due       : <display model>,25,26,27,28
// Teensy 3.x TFT Test Board                   : <display model>,23,22, 3, 4
// ElecHouse TFT LCD/SD Shield for Arduino Due : <display model>,22,23,31,33
//
// Remember to change the model parameter to suit your display module!
UTFT    myGLCD(R61581, 38, 39, 40, 41); //3.5" TFTLCD for arduino 2560 from mcufriend.com

// Initialize touchscreen
// ----------------------
// Set the pins to the correct ones for your development board
// -----------------------------------------------------------
// Standard Arduino Uno/2009 Shield            : 15,10,14, 9, 8
// Standard Arduino Mega/Due shield            :  6, 5, 4, 3, 2
// CTE TFT LCD/SD Shield for Arduino Due       :  6, 5, 4, 3, 2
// Teensy 3.x TFT Test Board                   : 26,31,27,28,29
// ElecHouse TFT LCD/SD Shield for Arduino Due : 25,26,27,29,30
//
UTouch  myTouch( 6, 5, 4, 3, 2);

// Declare which fonts we will be using
extern uint8_t BigFont[];
int x, y;
int turn=0;
bool touched[9]={false,false,false,false,false,false,false,false,false};
int i,j;
int arr2d[][3]={{0,0,0},{0,0,0},{0,0,0}};
bool win=false;
bool player_1=false;
int ou;
//RESOLUTION:    480x320


//*********** CUTSOM FUNCTIONS*********************//

void circle_9()
{

     myGLCD.setColor(0,0, 255);
     
  myGLCD.drawCircle(400,265,40);
  myGLCD.drawCircle(400,265,39);
 myGLCD.drawCircle(400,265,38);
 myGLCD.drawCircle(400,265,37);
 myGLCD.drawCircle(400,265,36);
 myGLCD.drawCircle(400,265,35);
}
void circle_8()
{
     myGLCD.setColor(0,0, 255);

  myGLCD.drawCircle(230,265,40);
  myGLCD.drawCircle(230,265,39);
 myGLCD.drawCircle(230,265,38);
 myGLCD.drawCircle(230,265,37);
  myGLCD.drawCircle(230,265,36);
 myGLCD.drawCircle(230,265,35);
}
void circle_7()
{   
     myGLCD.setColor(0,0, 255);

   myGLCD.drawCircle(70,265,40);
  myGLCD.drawCircle(70,265,39);
   myGLCD.drawCircle(70,265,38);
  myGLCD.drawCircle(70,265,37);
     myGLCD.drawCircle(70,265,36);
  myGLCD.drawCircle(70,265,35);
}

void circle_6()
{
     myGLCD.setColor(0,0, 255);

  myGLCD.drawCircle(400,155,40);
  myGLCD.drawCircle(400,155,39);
 myGLCD.drawCircle(400,155,38);
 myGLCD.drawCircle(400,155,37);
  myGLCD.drawCircle(400,155,36);
 myGLCD.drawCircle(400,155,35);
}
void circle_5()
{
     myGLCD.setColor(0,0, 255);

  myGLCD.drawCircle(230,155,40);
  myGLCD.drawCircle(230,155,39);
 myGLCD.drawCircle(230,155,38);
 myGLCD.drawCircle(230,155,37);
  myGLCD.drawCircle(230,155,36);
 myGLCD.drawCircle(230,155,35);
}
void circle_4()
{
     myGLCD.setColor(0,0, 255);

   myGLCD.drawCircle(70,155,40);
  myGLCD.drawCircle(70,155,39);
   myGLCD.drawCircle(70,155,38);
  myGLCD.drawCircle(70,155,37);
     myGLCD.drawCircle(70,155,36);
  myGLCD.drawCircle(70,155,35);
}
void circle_3()
{
   myGLCD.setColor(0, 0, 255);

  myGLCD.drawCircle(400,50,40);
  myGLCD.drawCircle(400,50,39);
 myGLCD.drawCircle(400,50,38);
 myGLCD.drawCircle(400,50,37);
  myGLCD.drawCircle(400,50,36);
 myGLCD.drawCircle(400,50,35);
}
void circle_2()
{
     myGLCD.setColor(0,0, 255);
  
 myGLCD.drawCircle(230,50,40);
 myGLCD.drawCircle(230,50,39);
 myGLCD.drawCircle(230,50,38);
 myGLCD.drawCircle(230,50,37);
myGLCD.drawCircle(230,50,36);
 myGLCD.drawCircle(230,50,35);
 
}
void circle_1()
{
     myGLCD.setColor(0,0, 255);

 myGLCD.drawCircle(70,50,40);
 myGLCD.drawCircle(70,50,39);
 myGLCD.drawCircle(70,50,38);
 myGLCD.drawCircle(70,50,37);
 myGLCD.drawCircle(70,50,36);
 myGLCD.drawCircle(70,50,35);
}
void cross_9()
{
   myGLCD.setColor(255, 0, 0);
  //9th box
 myGLCD.drawLine(460,300,360,240);//120.80.20.20
 myGLCD.drawLine(459,300,359,240);
  myGLCD.drawLine(458,300,358,240);
 myGLCD.drawLine(457,300,357,240);
  myGLCD.drawLine(456,300,356,240);
  myGLCD.drawLine(455,300,355,240);
  myGLCD.drawLine(454,300,354,240);
 myGLCD.drawLine(453,300,353,240);
  myGLCD.drawLine(452,300,352,240);
  myGLCD.drawLine(451,300,351,240);
  myGLCD.drawLine(450,300,350,240);
  myGLCD.drawLine(449,300,349,240);
 myGLCD.drawLine(448,300,348,240);
  myGLCD.drawLine(447,300,347,240);
//above is 14 pixel wide line
//
   myGLCD.drawLine(460,240,360,300);
  myGLCD.drawLine(459,240,359,300);
  myGLCD.drawLine(458,240,358,300);
  myGLCD.drawLine(457,240,357,300);
  myGLCD.drawLine(456,240,356,300);
  myGLCD.drawLine(455,240,355,300);
  myGLCD.drawLine(454,240,354,300);
  myGLCD.drawLine(453,240,353,300);
  myGLCD.drawLine(452,240,352,300);
  myGLCD.drawLine(451,240,351,300);
  myGLCD.drawLine(450,240,350,300);
  myGLCD.drawLine(449,240,349,300);
  myGLCD.drawLine(448,240,348,300);
  myGLCD.drawLine(447,240,347,300);

}
void cross_8()
{
     myGLCD.setColor(255, 0, 0);

  //8th box

 myGLCD.drawLine(290,300,190,240);//120.80.20.20
 myGLCD.drawLine(289,300,189,240);
  myGLCD.drawLine(288,300,188,240);
 myGLCD.drawLine(287,300,187,240);
  myGLCD.drawLine(288,300,186,240);
  myGLCD.drawLine(287,300,185,240);
  myGLCD.drawLine(286,300,184,240);
 myGLCD.drawLine(285,300,183,240);
  myGLCD.drawLine(284,300,182,240);
  myGLCD.drawLine(283,300,181,240);
  myGLCD.drawLine(282,300,180,240);
  myGLCD.drawLine(281,300,179,240);
 myGLCD.drawLine(280,300,178,240);
  myGLCD.drawLine(279,300,177,240);
//above is 14 pixel wide line
//
   myGLCD.drawLine(290,240,190,300);
 myGLCD.drawLine(280,240,189,300);
  myGLCD.drawLine(289,240,188,300);
  myGLCD.drawLine(288,240,187,300);
  myGLCD.drawLine(287,240,186,300);
  myGLCD.drawLine(286,240,185,300);
  myGLCD.drawLine(285,240,184,300);
  myGLCD.drawLine(284,240,183,300);
  myGLCD.drawLine(283,240,182,300);
  myGLCD.drawLine(282,240,181,300);
  myGLCD.drawLine(281,240,180,300);
  myGLCD.drawLine(280,240,179,300);
  myGLCD.drawLine(279,240,178,300);
  myGLCD.drawLine(278,240,177,300);

}


void cross_7()
{
    //7th box
   myGLCD.setColor(255, 0, 0);

  myGLCD.drawLine(120,300,20,240);//120.80.20.20
 myGLCD.drawLine(119,300,19,240);
  myGLCD.drawLine(118,300,18,240);
 myGLCD.drawLine(117,300,17,240);
  myGLCD.drawLine(118,300,16,240);
  myGLCD.drawLine(117,300,15,240);
  myGLCD.drawLine(116,300,14,240);
 myGLCD.drawLine(115,300,13,240);
  myGLCD.drawLine(114,300,12,240);
  myGLCD.drawLine(113,300,11,240);
  myGLCD.drawLine(112,300,10,240);
  myGLCD.drawLine(111,300,9,240);
 myGLCD.drawLine(110,300,8,240);
  myGLCD.drawLine(109,300,7,240);
//above is 14 pixel wide line
//
 myGLCD.drawLine(120,240,19,300);
  myGLCD.drawLine(119,240,18,300);
  myGLCD.drawLine(118,240,17,300);
  myGLCD.drawLine(117,240,16,300);
  myGLCD.drawLine(116,240,11,300);
  myGLCD.drawLine(115,240,14,300);
  myGLCD.drawLine(114,240,13,300);
  myGLCD.drawLine(113,240,12,300);
  myGLCD.drawLine(112,240,11,300);
  myGLCD.drawLine(111,240,10,300);
  myGLCD.drawLine(110,240,9,300);
  myGLCD.drawLine(109,240,8,300);
  myGLCD.drawLine(108,240,7,300);
  myGLCD.drawLine(107,240,6,300);
}

void cross_6()
{
    //6th box
  //first line 14 px wide
     myGLCD.setColor(255, 0, 0);

 myGLCD.drawLine(360,190,460,130);//120.80.20.20
 myGLCD.drawLine(359,190,459,130);
  myGLCD.drawLine(358,190,458,130);
 myGLCD.drawLine(357,190,457,130);
 myGLCD.drawLine(356,190,456,130);
  myGLCD.drawLine(355,190,455,130);
  myGLCD.drawLine(354,190,454,130);
 myGLCD.drawLine(353,190,453,130);
 myGLCD.drawLine(352,190,452,130);
  myGLCD.drawLine(351,190,451,130);
  myGLCD.drawLine(350,190,450,130);
 myGLCD.drawLine(349,190,449,130);
 myGLCD.drawLine(348,190,448,130);
  myGLCD.drawLine(347,190,447,130);
//above is 14 pixel wide line

  myGLCD.drawLine(460,190,360,130);
 myGLCD.drawLine(459,190,359,130);
 myGLCD.drawLine(458,190,358,130);
  myGLCD.drawLine(457,190,357,130);
  myGLCD.drawLine(456,190,356,130);
  myGLCD.drawLine(455,190,356,130);
  myGLCD.drawLine(454,190,355,130);
  myGLCD.drawLine(453,190,354,130);
  myGLCD.drawLine(452,190,353,130);
  myGLCD.drawLine(451,190,352,130);
  myGLCD.drawLine(450,190,351,130);
  myGLCD.drawLine(449,190,350,130);
  myGLCD.drawLine(448,190,349,130);
  myGLCD.drawLine(447,190,348,130);
}

void cross_5()
{
     myGLCD.setColor(255, 0, 0);

      //5th box
  //first line 14 px wide
 myGLCD.drawLine(290,190,190,130);//120.80.20.20
 myGLCD.drawLine(289,190,189,130);
  myGLCD.drawLine(288,190,188,130);
 myGLCD.drawLine(287,190,187,130);
 myGLCD.drawLine(286,190,186,130);
  myGLCD.drawLine(285,190,185,130);
  myGLCD.drawLine(284,190,184,130);
 myGLCD.drawLine(283,190,183,130);
 myGLCD.drawLine(282,190,183,130);
  myGLCD.drawLine(281,190,181,130);
  myGLCD.drawLine(280,190,180,130);
 myGLCD.drawLine(279,190,179,130);
 myGLCD.drawLine(278,190,178,130);
  myGLCD.drawLine(277,190,177,130);
//above is 14 pixel wide line

  myGLCD.drawLine(190,190,290,130);
 myGLCD.drawLine(189,190,289,130);
 myGLCD.drawLine(188,190,288,130);
  myGLCD.drawLine(187,190,287,130);
  myGLCD.drawLine(186,190,286,130);
  myGLCD.drawLine(185,190,286,130);
  myGLCD.drawLine(184,190,285,130);
  myGLCD.drawLine(183,190,284,130);
  myGLCD.drawLine(182,190,283,130);
  myGLCD.drawLine(181,190,282,130);
  myGLCD.drawLine(180,190,281,130);
  myGLCD.drawLine(179,190,280,130);
  myGLCD.drawLine(178,190,279,130);
  myGLCD.drawLine(177,190,278,130);


}

void cross_4()
{
     myGLCD.setColor(255, 0, 0);

     //4th box
//first line
  myGLCD.drawLine(120,190,20,130);//120.80.20.20
 myGLCD.drawLine(119,190,19,130);
  myGLCD.drawLine(118,190,18,130);
 myGLCD.drawLine(117,190,17,130);
 myGLCD.drawLine(116,190,16,130);
  myGLCD.drawLine(115,190,15,130);
  myGLCD.drawLine(114,190,14,130);
 myGLCD.drawLine(113,190,13,130);
 myGLCD.drawLine(112,190,13,130);
  myGLCD.drawLine(111,190,11,130);
  myGLCD.drawLine(110,190,10,130);
 myGLCD.drawLine(109,190,9,130);
 myGLCD.drawLine(108,190,8,130);
  myGLCD.drawLine(107,190,7,130);
//above is 14 pixel wide line

  myGLCD.drawLine(20,190,120,130);
 myGLCD.drawLine(19,190,119,130);
 myGLCD.drawLine(18,190,118,130);
  myGLCD.drawLine(17,190,117,130);
  myGLCD.drawLine(16,190,116,130);
  myGLCD.drawLine(15,190,116,130);
  myGLCD.drawLine(14,190,115,130);
  myGLCD.drawLine(13,190,114,130);
  myGLCD.drawLine(12,190,113,130);
  myGLCD.drawLine(11,190,112,130);
  myGLCD.drawLine(10,190,111,130);
  myGLCD.drawLine(9,190,110,130);
  myGLCD.drawLine(8,190,109,130);
  myGLCD.drawLine(7,190,108,130);
}

void cross_3()
{
     myGLCD.setColor(255, 0, 0);

   //3rd box
  //first line 14 px wide
    myGLCD.drawLine(360,80,460,20);
    myGLCD.drawLine(359,80,459,20);
    myGLCD.drawLine(358,80,458,20);
    myGLCD.drawLine(357,80,457,20);
    myGLCD.drawLine(356,80,456,20);
    myGLCD.drawLine(355,80,455,20);
    myGLCD.drawLine(354,80,454,20);
    myGLCD.drawLine(353,80,453,20);
    myGLCD.drawLine(352,80,452,20);
    myGLCD.drawLine(351,80,451,20);
    myGLCD.drawLine(350,80,450,20);
    myGLCD.drawLine(349,80,449,20);
    myGLCD.drawLine(348,80,448,20);
    myGLCD.drawLine(347,80,447,20);


  //2nd line 14 px wide
    myGLCD.drawLine(460,80,360,20);
    myGLCD.drawLine(459,80,359,20);
    myGLCD.drawLine(458,80,358,20);
    myGLCD.drawLine(457,80,357,20);
    myGLCD.drawLine(456,80,356,20);
    myGLCD.drawLine(455,80,355,20);
    myGLCD.drawLine(454,80,354,20);
    myGLCD.drawLine(453,80,353,20);
    myGLCD.drawLine(452,80,352,20);
    myGLCD.drawLine(451,80,351,20);
    myGLCD.drawLine(450,80,350,20);
    myGLCD.drawLine(449,80,349,20);
    myGLCD.drawLine(448,80,348,20);
    myGLCD.drawLine(447,80,347,20);
}

void cross_2()
{
     myGLCD.setColor(255, 0, 0);

  //2nd box
  //first line 14 px wide
    myGLCD.drawLine(290,80,190,20);
    myGLCD.drawLine(289,80,189,20);
    myGLCD.drawLine(288,80,188,20);
    myGLCD.drawLine(287,80,187,20);
    myGLCD.drawLine(286,80,186,20);
    myGLCD.drawLine(285,80,185,20);
    myGLCD.drawLine(284,80,184,20);
    myGLCD.drawLine(283,80,183,20);
    myGLCD.drawLine(282,80,182,20);
    myGLCD.drawLine(281,80,181,20);
    myGLCD.drawLine(280,80,180,20);
    myGLCD.drawLine(279,80,179,20);
    myGLCD.drawLine(278,80,178,20);
    myGLCD.drawLine(277,80,177,20);


  //2nd line 14 px wide
    myGLCD.drawLine(190,80,290,20);
    myGLCD.drawLine(189,80,289,20);
    myGLCD.drawLine(188,80,288,20);
    myGLCD.drawLine(187,80,287,20);
    myGLCD.drawLine(186,80,286,20);
    myGLCD.drawLine(185,80,285,20);
    myGLCD.drawLine(184,80,284,20);
    myGLCD.drawLine(183,80,283,20);
    myGLCD.drawLine(182,80,282,20);
    myGLCD.drawLine(181,80,281,20);
    myGLCD.drawLine(180,80,280,20);
    myGLCD.drawLine(179,80,279,20);
    myGLCD.drawLine(178,80,278,20);
    myGLCD.drawLine(177,80,277,20);
}

void cross_1()
{
     myGLCD.setColor(255, 0, 0);

   //for first box
  myGLCD.drawLine(120,80,20,20);
  myGLCD.drawLine(119,80,19,20);
  myGLCD.drawLine(118,80,18,20);
  myGLCD.drawLine(117,80,17,20);
  myGLCD.drawLine(116,80,16,20);
  myGLCD.drawLine(115,80,15,20);
  myGLCD.drawLine(114,80,14,20);
  myGLCD.drawLine(113,80,13,20);
  myGLCD.drawLine(112,80,12,20);
  myGLCD.drawLine(111,80,11,20);
  myGLCD.drawLine(110,80,10,20);
  myGLCD.drawLine(109,80,9,20);
  myGLCD.drawLine(108,80,8,20);
  myGLCD.drawLine(107,80,7,20);
//above is 14 pixel wide line
//
  myGLCD.drawLine(20,80,120,20);
  myGLCD.drawLine(19,80,119,20);
  myGLCD.drawLine(18,80,118,20);
  myGLCD.drawLine(17,80,117,20);
  myGLCD.drawLine(16,80,116,20);
  myGLCD.drawLine(15,80,115,20);
  myGLCD.drawLine(14,80,114,20);
  myGLCD.drawLine(13,80,113,20);
  myGLCD.drawLine(12,80,112,20);
  myGLCD.drawLine(11,80,111,20);
  myGLCD.drawLine(10,80,110,20);
  myGLCD.drawLine(9,80,109,20);
  myGLCD.drawLine(8,80,108,20);
  myGLCD.drawLine(7,80,107,20);

}


void wined(int a){
    delay(1200);
  myGLCD.clrScr();
  if(a==1){
    myGLCD.setColor(255,0,0);
    myGLCD.setBackColor(0,0,0);
    myGLCD.print("PLAYER ",80,150);
    myGLCD.print("1 WINS",200,150);
    win=true;
    return;
  }
  if(a==2 &&!player_1){
    myGLCD.setColor(0,0, 255);
    myGLCD.setBackColor(0,0,0);
    myGLCD.print("PLAYER ",80,150);
    myGLCD.print("2 WINS",200,150);
    win=true;
    return;
  }
  else if(player_1)
  {
    myGLCD.setColor(0,0, 255);
    myGLCD.setBackColor(0,0,0);
    myGLCD.print("COMPUTER ",90,150);
    myGLCD.print("WINS",250,150);
    win=true; 
    return;
  }
  
  delay(500);
}

void draw()
{
     myGLCD.setColor(255, 255, 255);
     myGLCD.setBackColor(0,0,0);
    myGLCD.clrScr();
    myGLCD.print("DRAW ",200,150);
    delay(500);
    win=true;
}



void start_menu()
{
    myGLCD.setColor(0, 0,255);
  myGLCD.print("ARDUINO TIC TAC TOE GAME", 40, 50);
      myGLCD.setColor(255, 0, 0);
  myGLCD.fillRoundRect (150, 120, 320, 180);
  myGLCD.fillRoundRect (150, 220, 320, 280);
  myGLCD.setColor(255, 255, 255);
  myGLCD.setBackColor (255, 0, 0);

  myGLCD.print("1 PLAYER",170,140);
  myGLCD.print("2 PLAYER",170,240);

  while (1)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();

      if(x>=150 &&x<=320 &&y>=120 &&y<=180)
      {
        player_1=true;
        myGLCD.clrScr();
        break;
      }
       if(x>=150 &&x<=320 &&y>=220 &&y<=280)
      {
        player_1=false;
        myGLCD.clrScr();
        break;
      }
      
    }
  }

}


void comp_move(int a)
{
  //computer turn are 1,3,5,7 which is a

  check_win();
  if(win==true)return;

//combinatiopn 1 diagonal left to right
  if(arr2d[0][0]==2)
  {
     if(arr2d[1][1]==2)
     {
      if(!touched[8]){
        circle_9();
        turn++;
        touched[8]=true;
        arr2d[2][2]=2;
        return;
      }        
     }
     if(arr2d[2][2]==2)
     {
      if(!touched[4]){
        circle_5();
        turn++;
        touched[4]=true;
        arr2d[1][1]=2;
        return;
      }        
     }
  }
   if(arr2d[2][2]==2)
  {
     if(arr2d[1][1]==2)
     {
      if(!touched[0]){
        circle_1();
        turn++;
        touched[0]=true;
        arr2d[0][0]=2;
        return;
      }        
     }
     if(arr2d[0][0]==2)
     {
      if(!touched[4]){
        circle_5();
        turn++;
        touched[4]=true;
        arr2d[1][1]=2;
        return;
      }        
     }
  }


    //combinatiopn 2 diagonal lright to left
   if(arr2d[0][2]==2)
  {
     if(arr2d[1][1]==2)
     {
      if(!touched[6]){
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
      }
     }
     if(arr2d[2][0]==2)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return; 
      }
     }
     }

     
     if(arr2d[2][0]==2)
     {
      if(!touched[4]){
        circle_5();
        turn++;
        touched[4]=true;
        arr2d[1][1]=2;
        return;
      }        
     }

    if(arr2d[0][2]==2)
  {
     if(arr2d[1][1]==2)
     {
      if(!touched[6]){
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
      }
     }
     if(arr2d[2][0]==2)
     {
      if(!touched[4]){
        circle_5();
        turn++;
        touched[4]=true;
        arr2d[1][1]=2;
        return;
      }        
     }
  }

  
  //combination 3 left to right row1
   if(arr2d[0][0]==2)
  {
     if(arr2d[0][1]==2)
     {
      if(!touched[2]){
        circle_3();
          turn++;
          touched[2]=true;
          arr2d[0][2]=2;
          return; 
      }
     }
     if(arr2d[0][2]==2)
     {
      if(!touched[1]){
        circle_2();
          turn++;
          touched[1]=true;
          arr2d[0][1]=2;
          return; 
      }
     }
  }
  if(arr2d[0][2]==2)
  {
     if(arr2d[0][1]==2)
     {
      if(!touched[0]){
        circle_1();
          turn++;
          touched[0]=true;
          arr2d[0][0]=2;
          return; 
      }
     }
     if(arr2d[0][0]==2)
     {
      if(!touched[1]){
        circle_2();
          turn++;
          touched[1]=true;
          arr2d[0][1]=2;
          return; 
      }
     }
  }

  
    //combinatiopn 4 diagonal left to right row 2
   if(arr2d[1][0]==2)
  {
     if(arr2d[1][1]==2)
     {
      if(!touched[5]){
          circle_6();
          turn++;
          touched[5]=true;
          arr2d[1][2]=2;
          return; 
      }
     }
     if(arr2d[1][2]==2)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return; 
      }
     }
  }
  
   if(arr2d[1][2]==2)
  {
     if(arr2d[1][1]==2)
     {
      if(!touched[3]){
          circle_4();
          turn++;
          touched[3]=true;
          arr2d[1][0]=2;
          return; 
      }
     }
     if(arr2d[1][0]==2)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return; 
      }
     }
  }

   //combinatiopn 5 diagonal left to right row 3
   if(arr2d[2][0]==2)
  {
     if(arr2d[2][1]==2)
     {
      if(!touched[8]){
          circle_9();
          turn++;
          touched[8]=true;
          arr2d[2][2]=2;
          return; 
      }
     }
     if(arr2d[2][2]==2)
     {
      if(!touched[7]){
          circle_8();
          turn++;
          touched[7]=true;
          arr2d[2][1]=2;
          return; 
      }
     }
  }

     if(arr2d[2][2]==2)
  {
     if(arr2d[2][1]==2)
     {
      if(!touched[6]){
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
      }
     }
     if(arr2d[2][0]==2)
     {
      if(!touched[7]){
          circle_8();
          turn++;
          touched[7]=true;
          arr2d[2][1]=2;
          return; 
      }
     }
  }

//combinatiopn 6 up to down col 1
   if(arr2d[0][0]==2)
  {
     if(arr2d[1][0]==2)
     {
      if(!touched[6]){
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
      }
     }
     if(arr2d[2][0]==2)
     {
      if(!touched[3]){
          circle_4();
          turn++;
          touched[3]=true;
          arr2d[1][0]=2;
          return; 
      }
     }
  }
   if(arr2d[2][0]==2)
  {
     if(arr2d[1][0]==2)
     {
      if(!touched[0]){
          circle_1();
          turn++;
          touched[0]=true;
          arr2d[0][0]=2;
          return; 
      }
     }
     if(arr2d[0][0]==2)
     {
      if(!touched[3]){
          circle_4();
          turn++;
          touched[3]=true;
          arr2d[1][0]=2;
          return; 
      }
     }
  }

//combinatiopn 7 up to down col 2
  if(arr2d[0][1]==2)
  {
     if(arr2d[1][1]==2)
     {
      if(!touched[7]){
          circle_8();
          turn++;
          touched[7]=true;
          arr2d[2][1]=2;
          return;
      } 
     }
     if(arr2d[2][1]==2)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return;
      } 
     }
  }
   if(arr2d[2][1]==2)
  {
     if(arr2d[1][1]==2)
     {
      if(!touched[1]){
          circle_2();
          turn++;
          touched[1]=true;
          arr2d[0][1]=2;
          return;
      } 
     }
     if(arr2d[0][1]==2)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return;
      } 
     }
  }


  //combinatiopn 8 up to down col 3
  if(arr2d[0][2]==2)
  {
     if(arr2d[1][2]==2)
     {
      if(!touched[8]){
          circle_9();
          turn++;
          touched[8]=true;
          arr2d[2][2]=2;
          return; 
      }
     }
      if(arr2d[2][2]==2)
     {
      if(!touched[5]){
          circle_6();
          turn++;
          touched[5]=true;
          arr2d[1][2]=2;
          return; 
      }
     }
  }
   if(arr2d[2][2]==2)
  {
     if(arr2d[1][2]==2)
     {
      if(!touched[2]){
          circle_3();
          turn++;
          touched[2]=true;
          arr2d[0][2]=2;
          return; 
      }
     }
      if(arr2d[0][2]==2)
     {
      if(!touched[5]){
          circle_6();
          turn++;
          touched[5]=true;
          arr2d[1][2]=2;
          return; 
      }
     }
  }

  //combinatiopn 1 diagonal left to right
  if(arr2d[0][0]==1)
  {
     if(arr2d[1][1]==1)
     {
      if(!touched[8]){
        circle_9();
        turn++;
        touched[8]=true;
        arr2d[2][2]=2;
        return;
      }        
     }
     if(arr2d[2][2]==1)
     {
      if(!touched[4]){
        circle_5();
        turn++;
        touched[4]=true;
        arr2d[1][1]=2;
        return;
      }        
     }
  }
   if(arr2d[2][2]==1)
  {
     if(arr2d[1][1]==1)
     {
      if(!touched[0]){
        circle_1();
        turn++;
        touched[0]=true;
        arr2d[0][0]=2;
        return;
      }        
     }
     if(arr2d[0][0]==1)
     {
      if(!touched[4]){
        circle_5();
        turn++;
        touched[4]=true;
        arr2d[1][1]=2;
        return;
      }        
     }
  }


    //combinatiopn 2 diagonal lright to left
   if(arr2d[0][2]==1)
  {
     if(arr2d[1][1]==1)
     {
      if(!touched[6]){
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
      }
     }
     if(arr2d[2][0]==1)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return; 
      }
     }
     }

     
     if(arr2d[2][0]==1)
     {
      if(!touched[4]){
        circle_5();
        turn++;
        touched[4]=true;
        arr2d[1][1]=2;
        return;
      }        
     }

    if(arr2d[0][2]==1)
  {
     if(arr2d[1][1]==1)
     {
      if(!touched[6]){
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
      }
     }
     if(arr2d[2][0]==1)
     {
      if(!touched[4]){
        circle_5();
        turn++;
        touched[4]=true;
        arr2d[1][1]=2;
        return;
      }        
     }
  }

  
  //combination 3 left to right row1
   if(arr2d[0][0]==1)
  {
     if(arr2d[0][1]==1)
     {
      if(!touched[2]){
        circle_3();
          turn++;
          touched[2]=true;
          arr2d[0][2]=2;
          return; 
      }
     }
     if(arr2d[0][2]==1)
     {
      if(!touched[1]){
        circle_2();
          turn++;
          touched[1]=true;
          arr2d[0][1]=2;
          return; 
      }
     }
  }
  if(arr2d[0][2]==1)
  {
     if(arr2d[0][1]==1)
     {
      if(!touched[0]){
        circle_1();
          turn++;
          touched[0]=true;
          arr2d[0][0]=2;
          return; 
      }
     }
     if(arr2d[0][0]==1)
     {
      if(!touched[1]){
        circle_2();
          turn++;
          touched[1]=true;
          arr2d[0][1]=2;
          return; 
      }
     }
  }

  
    //combinatiopn 4 diagonal left to right row 2
   if(arr2d[1][0]==1)
  {
     if(arr2d[1][1]==1)
     {
      if(!touched[5]){
          circle_6();
          turn++;
          touched[5]=true;
          arr2d[1][2]=2;
          return; 
      }
     }
     if(arr2d[1][2]==1)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return; 
      }
     }
  }
  
   if(arr2d[1][2]==1)
  {
     if(arr2d[1][1]==1)
     {
      if(!touched[3]){
          circle_4();
          turn++;
          touched[3]=true;
          arr2d[1][0]=2;
          return; 
      }
     }
     if(arr2d[1][0]==1)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return; 
      }
     }
  }

   //combinatiopn 5 diagonal left to right row 3
   if(arr2d[2][0]==1)
  {
     if(arr2d[2][1]==1)
     {
      if(!touched[8]){
          circle_9();
          turn++;
          touched[8]=true;
          arr2d[2][2]=2;
          return; 
      }
     }
     if(arr2d[2][2]==1)
     {
      if(!touched[7]){
          circle_8();
          turn++;
          touched[7]=true;
          arr2d[2][1]=2;
          return; 
      }
     }
  }

     if(arr2d[2][2]==1)
  {
     if(arr2d[2][1]==1)
     {
      if(!touched[6]){
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
      }
     }
     if(arr2d[2][0]==1)
     {
      if(!touched[7]){
          circle_8();
          turn++;
          touched[7]=true;
          arr2d[2][1]=2;
          return; 
      }
     }
  }

//combinatiopn 6 up to down col 1
   if(arr2d[0][0]==1)
  {
     if(arr2d[1][0]==1)
     {
      if(!touched[6]){
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
      }
     }
     if(arr2d[2][0]==1)
     {
      if(!touched[3]){
          circle_4();
          turn++;
          touched[3]=true;
          arr2d[1][0]=2;
          return; 
      }
     }
  }
   if(arr2d[2][0]==1)
  {
     if(arr2d[1][0]==1)
     {
      if(!touched[0]){
          circle_1();
          turn++;
          touched[0]=true;
          arr2d[0][0]=2;
          return; 
      }
     }
     if(arr2d[0][0]==1)
     {
      if(!touched[3]){
          circle_4();
          turn++;
          touched[3]=true;
          arr2d[1][0]=2;
          return; 
      }
     }
  }

//combinatiopn 7 up to down col 2
  if(arr2d[0][1]==1)
  {
     if(arr2d[1][1]==1)
     {
      if(!touched[7]){
          circle_8();
          turn++;
          touched[7]=true;
          arr2d[2][1]=2;
          return;
      } 
     }
     if(arr2d[2][1]==1)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return;
      } 
     }
  }
   if(arr2d[2][1]==1)
  {
     if(arr2d[1][1]==1)
     {
      if(!touched[1]){
          circle_2();
          turn++;
          touched[1]=true;
          arr2d[0][1]=2;
          return;
      } 
     }
     if(arr2d[0][1]==1)
     {
      if(!touched[4]){
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return;
      } 
     }
  }


  //combinatiopn 8 up to down col 3
  if(arr2d[0][2]==1)
  {
     if(arr2d[1][2]==1)
     {
      if(!touched[8]){
          circle_9();
          turn++;
          touched[8]=true;
          arr2d[2][2]=2;
          return; 
      }
     }
      if(arr2d[2][2]==1)
     {
      if(!touched[5]){
          circle_6();
          turn++;
          touched[5]=true;
          arr2d[1][2]=2;
          return; 
      }
     }
  }
   if(arr2d[2][2]==1)
  {
     if(arr2d[1][2]==1)
     {
      if(!touched[2]){
          circle_3();
          turn++;
          touched[2]=true;
          arr2d[0][2]=2;
          return; 
      }
     }
      if(arr2d[0][2]==1)
     {
      if(!touched[5]){
          circle_6();
          turn++;
          touched[5]=true;
          arr2d[1][2]=2;
          return; 
      }
     }
  }


//now random 
for(i=0;i<9;i++)
{
  if(touched[i]==true)
  {
    ou=i;
  }
}
if(!touched[5]&&ou==1)
  {
          circle_6();
          turn++;
          touched[5]=true;
          arr2d[1][2]=2;
          return; 
  } 
  
    else if(!touched[7]&&ou==2)
  {
          circle_8();
          turn++;
          touched[7]=true;
          arr2d[2][1]=2;
          return; 
  } 
   else if(!touched[0]&&ou==3)
  {
          circle_1();
          turn++;
          touched[0]=true;
          arr2d[0][0]=2;
          return; 
  }
   else if(!touched[8]&&ou==4)
  {
          circle_9();
          turn++;
          touched[8]=true;
          arr2d[2][2]=2;
          return; 
  }
     else if(!touched[6]&&ou==5)
  {
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
  }
   else if(!touched[3]&&ou==6)
  {
          circle_4();
          turn++;
          touched[3]=true;
          arr2d[1][0]=2;
          return; 
  } 
  
//now for any remaining box without logic
  
  if(!touched[5])
  {
          circle_6();
          turn++;
          touched[5]=true;
          arr2d[1][2]=2;
          return; 
  } 
    else if(!touched[7])
  {
          circle_8();
          turn++;
          touched[7]=true;
          arr2d[2][1]=2;
          return; 
  } 
   else if(!touched[0])
  {
          circle_1();
          turn++;
          touched[0]=true;
          arr2d[0][0]=2;
          return; 
  }
   else if(!touched[8])
  {
          circle_9();
          turn++;
          touched[8]=true;
          arr2d[2][2]=2;
          return; 
  }
  else if(!touched[1])
  {
          circle_2();
          turn++;
          touched[1]=true;
          arr2d[0][1]=2;
          return; 
  } 
   else if(!touched[4])
  {
          circle_5();
          turn++;
          touched[4]=true;
          arr2d[1][1]=2;
          return; 
  } 
   else if(!touched[2])
  {
          circle_3();
          turn++;
          touched[2]=true;
          arr2d[0][2]=2;
          return; 
  }
    else if(!touched[6])
  {
          circle_7();
          turn++;
          touched[6]=true;
          arr2d[2][0]=2;
          return; 
  }
   else if(!touched[3])
  {
          circle_4();
          turn++;
          touched[3]=true;
          arr2d[1][0]=2;
          return; 
  } 
  
}



void check_win()
{
    //combinatiopn 1 diagonal left to right
  if(arr2d[0][0]==1)
  {
     if(arr2d[1][1]==1)
     {
        if(arr2d[2][2]==1)
        {
          wined(1);
          win=true;
          return;
        }
     }
  }
  if(arr2d[0][0]==2)
  {
     if(arr2d[1][1]==2)
     {
        if(arr2d[2][2]==2)
        {
          wined(2);
          win=true;
          return;
        }
     }
  }


    //combinatiopn 2 diagonal lright to left
  if(arr2d[0][2]==1)
  {
     if(arr2d[1][1]==1)
     {
        if(arr2d[2][0]==1)
        {
          wined(1);
          win=true;
          return;
        }
     }
  }
  if(arr2d[0][2]==2)
  {
     if(arr2d[1][1]==2)
     {
        if(arr2d[2][0]==2)
        {
          wined(2);
          win=true;
          return;
        }
     }
  }

  //combination 3 left to right row1
  if(arr2d[0][0]==1)
  {
     if(arr2d[0][1]==1)
     {
        if(arr2d[0][2]==1)
        {
          wined(1);
          win=true;
          return;
        }
     }
  }
  if(arr2d[0][0]==2)
  {
     if(arr2d[0][1]==2)
     {
        if(arr2d[0][2]==2)
        {
          wined(2);
          win=true;
          return;
        }
     }
  }

 

    //combinatiopn 4 diagonal left to right row 2
  if(arr2d[1][0]==1)
  {
     if(arr2d[1][1]==1)
     {
        if(arr2d[1][2]==1)
        {
          wined(1);
          win=true;
          return;
        }
     }
  }
  if(arr2d[1][0]==2)
  {
     if(arr2d[1][1]==2)
     {
        if(arr2d[1][2]==2)
        {
          wined(2);
          win=true;
          return;
        }
     }
  }

   //combinatiopn 5 diagonal left to right row 3
  if(arr2d[2][0]==1)
  {
     if(arr2d[2][1]==1)
     {
        if(arr2d[2][2]==1)
        {
          wined(1);
          win=true;
          return;
        }
     }
  }
  if(arr2d[2][0]==2)
  {
     if(arr2d[2][1]==2)
     {
        if(arr2d[2][2]==2)
        {
          wined(2);
          win=true;
          return;
        }
     }
  }

//combinatiopn 6 up to down col 1
  if(arr2d[0][0]==1)
  {
     if(arr2d[1][0]==1)
     {
        if(arr2d[2][0]==1)
        {
          wined(1);
          win=true;
          return;
        }
     }
  }
  if(arr2d[0][0]==2)
  {
     if(arr2d[1][0]==2)
     {
        if(arr2d[2][0]==2)
        {
          wined(2);
          win=true;
          return;
        }
     }
  }


//combinatiopn 7 up to down col 2
  if(arr2d[0][1]==1)
  {
     if(arr2d[1][1]==1)
     {
        if(arr2d[2][1]==1)
        {
          wined(1);
          win=true;
          return;
        }
     }
  }
  if(arr2d[0][1]==2)
  {
     if(arr2d[1][1]==2)
     {
        if(arr2d[2][1]==2)
        {
          wined(2);
          win=true;
          return;
        }
     }
  }



  //combinatiopn 8 up to down col 3
  if(arr2d[0][2]==1)
  {
     if(arr2d[1][2]==1)
     {
        if(arr2d[2][2]==1)
        {
          wined(1);
          win=true;
          return;
        }
     }
  }
  if(arr2d[0][2]==2)
  {
     if(arr2d[1][2]==2)
     {
        if(arr2d[2][2]==2)
        {
          wined(2);
          win=true;
          return;
        }
     }
  }

  if(turn==9 && !win)
  {
    draw();
    return;
  }
 }
//************ENDIING CUSTOM FUNCTIONS****************//


/*************************
**  Required functions  **
*************************/

void setup()
{
  // Initial setup
  myGLCD.InitLCD();
  myGLCD.clrScr();
    myGLCD.setBackColor(0, 0, 0);
  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  myGLCD.setFont(BigFont);
  turn=0;
  win=false;
  for(i=0;i<9;i++)touched[i]=false;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
        arr2d[i][j]=0;
    }
  }
    myGLCD.setColor(255, 255, 255);
    randomSeed(42);
    start_menu();
  //myGLCD.setBackColor(0, 0, 255);
  //myGLCD.print("GHAZANFER YOU ROCKS >>> :)", 50, 150);


  
  //parameter new assumption(from x,from y,to x,to y);
  //myGLCD.drawLine(280,100,190,10);
///////  myGLCD.drawLine(100,200,10,110);
//my theory 480x320 
 //parameters are(x,y,width=(x-num),height=(y-num));
// cross_2();
// //circle_1();
// circle_3();
// circle_4();
// cross_5();
// circle_6();
// circle_7();
// circle_8();
//circle_9();
// cross_1();

}

void loop()
{


//    vertical lines
  myGLCD.fillRoundRect (160, 0,150, 320);
  myGLCD.fillRoundRect (320, 0,310, 320);


  //horizontal lines
  myGLCD.fillRoundRect(0,107,479,97);
  myGLCD.fillRoundRect(0,214,479,204);
  while (true)
  {
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      
      //first row
      if ((y>=10) && (y<=107))  // Upper row
      {
        if ((x>=10) && (x<=160))  // Button: 1
        {
          if(turn%2==0 && !touched[0])
          {
           cross_1();
            turn++;
            touched[0]=true;
            arr2d[0][0]=1;
            if(player_1)comp_move(turn);
          }
          else if(!touched[0] &&!player_1){
            circle_1();
            turn++;
            touched[0]=true;
            arr2d[0][0]=2;
          }
        }
        if ((x>=161) && (x<=320))  // Button: 2
        {
            if(turn%2==0 &&!touched[1])
          {
            cross_2();
            turn++;
            touched[1]=true;
            arr2d[0][1]=1;
            if(player_1)comp_move(turn);

          }
          else if(!touched[1]&&!player_1){
            circle_2();
            turn++;
            touched[1]=true;
            arr2d[0][1]=2;
          }
//          else if(!touched[1])
//          {
//            comp_move(turn);
//            turn++;
//            touched[1]=true;
//            arr2d[0][1]=2;
//          }
        }
        if ((x>=321) && (x<=479))  // Button: 3
        {
          if(turn%2==0 &&!touched[2])
          {
            cross_3();
            turn++;
            touched[2]=true;
            arr2d[0][2]=1;
            if(player_1)comp_move(turn);
          }
          else if(!touched[2]&&!player_1){
            circle_3();
            turn++;
            touched[2]=true;
            arr2d[0][2]=2;
          }
//          else if(!touched[2])
//          {
//            comp_move(turn);
//            turn++;
//            touched[2]=true;
//            arr2d[0][2]=2;
//          }
        }
      }
      //2nd row
      if ((y>=108) && (y<=214))  
      {
        if ((x>=10) && (x<=160))  // Button: 4
        {
           if(turn%2==0 &&!touched[3])
          {
            cross_4();
            turn++;
            touched[3]=true;
            arr2d[1][0]=1;
            if(player_1)comp_move(turn);
          }
          else if(!touched[3]&&!player_1){
            circle_4();
            turn++;
            touched[3]=true;
            arr2d[1][0]=2;
          }
//          else if(!touched[3])
//          {
//            comp_move(turn);
//            turn++;
//            touched[3]=true;
//            arr2d[1][0]=2;
//          }
        }
        if ((x>=161) && (x<=320))  // Button: 5
        {
            if(turn%2==0 &&!touched[4])
          {
            cross_5();
            turn++;
            touched[4]=true;
            arr2d[1][1]=1;
            if(player_1)comp_move(turn);
          }
          else if(!touched[4]&&!player_1){
            circle_5();
            turn++;
            touched[4]=true;
            arr2d[1][1]=2;
          }
//          else if(!touched[4])
//          {
//            comp_move(turn);
//            turn++;
//            touched[4]=true;
//            arr2d[1][1]=2;
//          }
        }
        if ((x>=321) && (x<=479))  // Button: 6
        {
           if(turn%2==0 &&!touched[5])
          {
            cross_6();
            turn++;
            touched[5]=true;
            arr2d[1][2]=1;
            if(player_1)comp_move(turn);
          }
          else if(!touched[5]&&!player_1){
            circle_6();
            turn++;
            touched[5]=true;
            arr2d[1][2]=2;
          }
//          else if(!touched[5])
//          {
//            comp_move(turn);
//            turn++;
//            touched[5]=true;
//            arr2d[1][2]=2;
//          }
        }
      }
       //3rd row
      if ((y>=215) && (y<=320))  
      {
        if ((x>=10) && (x<=160))  // Button: 7
        {
           if(turn%2==0&&!touched[6])
          {
            cross_7();
            turn++;
            touched[6]=true;
            arr2d[2][0]=1;
            if(player_1)comp_move(turn);
          }
          else if(!touched[6]&&!player_1){
            circle_7();
            turn++;
            touched[6]=true;
            arr2d[2][0]=2;
          }
//          else if(!touched[6])
//          {
//            comp_move(turn);
//            turn++;
//            touched[6]=true;
//            arr2d[2][0]=2;
//          }
        }
        if ((x>=161) && (x<=320))  // Button: 8
        {
            if(turn%2==0&&!touched[7])
          {
            cross_8();
            turn++;
            touched[7]=true;
            arr2d[2][1]=1;
            if(player_1)comp_move(turn);
          }
          else if(!touched[7]&&!player_1){
            circle_8();
            turn++;
            touched[7]=true;
            arr2d[2][1]=2;
          }
//          else if(!touched[7])
//          {
//            comp_move(turn);
//            turn++;
//            touched[7]=true;
//            arr2d[2][1]=2;
//          }
        }
        if ((x>=321) && (x<=479))  // Button: 9
        {
          if(turn%2==0&&!touched[8])
          {
            cross_9();
            turn++;
            touched[8]=true;
            arr2d[2][2]=1;
            if(player_1)comp_move(turn);
          }
          else if(!touched[8]&&!player_1){
            circle_9();
            turn++;
            touched[8]=true;
            arr2d[2][2]=2;
          }
        }
      }
    }
    check_win();
    if(win==true)break;
  }
     setup();
}
