/*

Pong game for a 16x16 adressabel RGB LED matrix.
Uses two encoders as inputs.

My first attempt at using classes for Arduino

Documentation at
https://github.com/Jaknil/LED_games/blob/master/README.md
*/

#include "encoder.h"
#include "timer.h"
#include <FastLED.h>

//Create our encoders, name(leftpin, rightpin)
  Encoder ENC1(3,6);   //player one
    Encoder ENC2(2,5);  //player 2

//Create timer
Timer drawInterval(50);
Timer flash(100);
//Matrix
// Params for width and height
const uint8_t kMatrixWidth = 16;
const uint8_t kMatrixHeight = 16;
const bool    kMatrixSerpentineLayout = true;
// Define the array of leds
#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds_plus_safety_pixel[ NUM_LEDS + 1];
CRGB* const leds( leds_plus_safety_pixel + 1);
#define BRIGHTNESS 15
//OUTPUTS
#define DATA_PIN 12 //for the leds

//GAME STARTS HERE

class Line{
private:
public:
int x = 1;
int oldX = x;
int y = 2;
int leng = 5;
 
};


class Ball{
private:
const int initialBallSpeed = 250;
const int minBallSpeed = 100;
const int acc = -25; //how much time to reduce the increment with
int xFrac = 0;
int yFrac = 0;
int moveXnow = 1; //1 = move every time step, 3 = move every third
int moveYnow = 1;
//Update a value while keeping it inside bounds
int applyBounds(int value, int change, int lowLimit, int highLimit){
 //apply change
 value = value + change;
 //check bounds
       if(value < lowLimit){
    value = lowLimit;
  }
     if(value > highLimit){
    value = highLimit;
  }
  return value;
}
public:
int x = 5;
int y = 7;
int veloX = 16; //1 = move every time step, 3 = move every third
int veloY = 1;
int veloXdir = 1; //direction 
int veloYdir = 1; //direction
int oldX = x;
int oldY = y;
bool player1Lost = 0;
bool player2Lost = 0;
//timer
Timer ballSpeed; //increases for each bounce, could not use variable?
void restart(){
  x=5;
  y=7;
  veloX = 16; //1 = move every time step, 3 = move every third
  veloY = 1;
  //bounceY();
  ballSpeed.interval = 500;
}
void updateBallspeed(){
ballSpeed.interval = applyBounds(ballSpeed.interval,acc,minBallSpeed,initialBallSpeed); 
}

void bounceY(){ //Straight
    veloYdir = veloYdir*(-1);
}

/*
bool checkMoveNow(int Frac,int velo){
    if(Frac>=velo){
  return = 1; //ok to move in x dir
  } else
 {
  return = 0;
 }
}
*/

void storeOldCoord(){
  //write old positions for deletion later
  oldX=x;
   oldY=y;
}
void restoreOldCoord(){
  //write old positions for deletion later
   x=oldX;
   y=oldY;
  // xFrac--;
  // yFrac--;
}


void inc(){
//Check which axis we move next step
xFrac++;
yFrac++;
  if(xFrac>=veloX){
  moveXnow = 1; //ok to move in x dir
  //Serial.println("ok to move in x dir");
  xFrac=0;
  } else
 {
   moveXnow=0;
 }
if(yFrac>=veloY){
  moveYnow = 1; //ok to move in y dir
   // Serial.println("ok to move in y dir");
  yFrac=0;
  } else {
       moveYnow=0;
  }

  
 /*
 Serial.print("veloXdir ");
Serial.print(veloXdir);
Serial.print(" veloYdir ");
Serial.println(veloYdir);
*/

//Check paddles for collide here?

//Increment position
  
  x=x+veloXdir*moveXnow;
  y=y+veloYdir*moveYnow;
  Serial.print(x);
Serial.print(" ");
Serial.println(y);

  //leave collide wall in, easier for now? split out win lose
  if(x>=15){
    veloXdir = -1;
    x=15;
Serial.println("x max");
      }
if(x<=0){
    veloXdir = 1;
    x=0;
Serial.println("x min");
      }
      
  if(y>=15){
    veloYdir = -1;
    y=15;
Serial.println("Y max, player 1 loses");
player1Lost = 1;
  } 
  
if(y<=0){
    veloYdir =1;
    y=0;
Serial.println("Y min, player 2 loses");
player2Lost = 1;
  }

  
}

//Check if ball overlap line 
void collideWithPaddle(Line paddle){
  //move the ball one step forward (I THINK THIS MISSES sometimes now due to movenow...)
       for(int i = 0; i < 5; i++){
    if(x==paddle.x+i && y == paddle.y){
      switch(i){
        case 0:
        veloX = 1;
        veloY = 1;
        veloXdir = -1;
        break;
        case 1:
        veloX = 2;
        veloY = 1;
        veloXdir = -1;
        break;
        case 2:
        veloX = 16;
        veloY = 1;
        break;
        case 3:
        veloX = 2;
        veloY = 1;
        veloXdir = 1;
        break;
        case 4:
        veloX = 1;
        veloY = 1;
        veloXdir = 1;
        break;
      }
      
  restoreOldCoord(); //move ball back to the surfase of the paddle
  //bounceY(); //changes y dir
  veloYdir = veloYdir*(-1); //Bounce y always
  Serial.println("bounce 1");
  inc(); //move it in new direction, it will bounce!
  updateBallspeed(); //increases speed to next bounce
   
    }
 }
 return 0;
}
}
;

//Create the game pieces
Line player1;
Line player2;
Line player1score;
Line player2score;
Line player1points;
Line player2points;



Ball ball1;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
    //Matrix
   FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);  // GRB ordering is typical (said RGB)
   FastLED.setBrightness( BRIGHTNESS );
   FastLED.setMaxPowerInVoltsAndMilliamps(5,500); //500mA max
  clearAllLeds(); // 
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(200);

//setup players
player1.y=14;
player2.y=1;
 //sets starting x position
ENC1.setStart(4);
ENC2.setStart(5);



//setup score lines
player1score.x = 0;
player1score.y = 15;
player2score.x = 0;
player2score.y = 0;
player1score.leng = 16;
player2score.leng = 16;

player1points.x = 0;
player1points.y = 15;
player2points.x = 0;
player2points.y = 0;
player1points.leng = 0;
player2points.leng = 0;
}




void loop() {
if(ball1.ballSpeed.expired()){
  ball1.storeOldCoord(); 
   ball1.inc(); //generate new coord
//Bounce ball against players
ball1.collideWithPaddle(player1);
ball1.collideWithPaddle(player2);
  //update ball positon on led matrix
   leds[XYsafe(ball1.oldX,ball1.oldY)]=CRGB::Black; //erase old ball
 leds[XYsafe(ball1.x,ball1.y)]=CRGB::Blue; //add new ball
//update paddle to not "loose" leds when ball moves away from underneath the paddle
updateLineObj(player1,CRGB::Green);
updateLineObj(player2,CRGB::Red);

//Victory?

  if (ball1.player1Lost){
  //flash target?
  //updateLineObj(player1score,CRGB::Gray);
  //ball1.ballSpeed.interval=100;
  //move ball to base line
  //ball1.veloXdir = -1; //change so it moves to the tip!
  //ball1.veloY = 10000;//keep it in line, easy trick
  //if(ball1.x==0){
    player1points.leng++;
    ball1.player1Lost = 0;
    updateLineObj(player1score,CRGB::Black);
updateLineObj(player2score,CRGB::Black);
updateLineObj(player1points,CRGB::Red);
updateLineObj(player2points,CRGB::Green);
    ball1.restart();

  //}
}
if(ball1.player2Lost){
    //flash target?
  //updateLineObj(player1score,CRGB::Gray);
  //ball1.ballSpeed.interval=100;
  //move ball to base line
  //ball1.veloXdir = -1;
  //ball1.veloY = 10000;//keep it in line, easy trick
  //if(ball1.x==0){
    player2points.leng++;
    ball1.player2Lost = 0;
        updateLineObj(player1score,CRGB::Black);
updateLineObj(player2score,CRGB::Black);
updateLineObj(player1points,CRGB::Red);
updateLineObj(player2points,CRGB::Green);
    ball1.restart();
//}
} 



  } //ballspeed
  
 //scan the encoders, as fast as possible
  ENC1.inc();
  ENC2.inc();
      if(ENC1.checkTrigger() || ENC2.checkTrigger()){ //when there is new data any encoder
// Set player positions to match encoders
player1.x= ENC1.countFull; 
player2.x= ENC2.countFull; 

//Update paddles
updateLineObj(player1,CRGB::Green);
updateLineObj(player2,CRGB::Red);
    

//store positions for deletion next time around
player1.oldX= player1.x; 
player2.oldX= player2.x; 


//SUGGESTION: perhaps better to return diff from encoder and keep the bounds in the paddle for a more logical structure?
//Use new applyBounds function
//make method instead? 


   }
     if (drawInterval.expired()){ //if enough time passed
          FastLED.show();  
 
}
} //END LOOP
//FUNCTIONS
