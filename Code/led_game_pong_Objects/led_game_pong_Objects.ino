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
//move to ball? note in ball when last updated and use timer internally there?
const int initialBallSpeed = 350;
const int minBallSpeed = 50;
Timer ballSpeed(initialBallSpeed); //increases for each bounce
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
public:
int x = 5;
int y = 7;
int veloX = 1;
int veloY = 1;
int oldX = x;
int oldY = y;
int acc = -25; //how much time to reduce the increment with
void bounceY(){
    veloY = veloY*(-1);
}
void inc(){
  oldX=x;
  x=x+veloX;
  oldY=y;
  y=y+veloY;

  //leave collide wall in, easier for now? split out win lose
  if(x>=kMatrixWidth-1 || x==0){
    veloX = veloX*(-1);
//Serial.println("game lost, unclear who");
    
  }
  if(y>=kMatrixHeight-1 || y==0){
    veloY = veloY*(-1);
//Serial.println("Y max/mined");
  }
}
//Check collission ball to an line in x direction, starting on objX, objY coord and having i length
bool collide(int objX, int objY, int objLength){
 for(int i = 0; i < objLength; i++){
    if(x==objX+i && y == objY){
      return 1;
    }
 }
 return 0;
}
//Check if ball will overlap line in N steps. Made so that you can bounce things of surfaces
bool collideWithLine(Line LineToCollide, int steps){
  //move the ball one step forward
LineToCollide.x-=veloX*steps;
LineToCollide.y-=veloY*steps;
       for(int i = 0; i < LineToCollide.leng; i++){
    if(x==LineToCollide.x+i && y == LineToCollide.y){
      return 1;
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
player1.y=13;
player2.y=2;
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
}




void loop() {
if(ballSpeed.expired()){
 ball1.inc();

//Bounce ball against players
if(ball1.collideWithLine(player1,1)){
 // Serial.println("bounce 1");
     ball1.bounceY();
     updateBallspeed();
}

if(ball1.collideWithLine(player2,1)){
  //Serial.println("bounce 2");
     ball1.bounceY();
     updateBallspeed();
}

  //update ball positon on led matrix
   leds[XYsafe(ball1.oldX,ball1.oldY)]=CRGB::Black; //erase old ball
 leds[XYsafe(ball1.x,ball1.y)]=CRGB::Blue; //add new ball
//update paddle to not "loose" leds when ball moves away from underneath the paddle
updateLineObj(player1,CRGB::Green);
updateLineObj(player2,CRGB::Red);

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

//Make this part of Ball later
void updateBallspeed(){
ballSpeed.interval = applyBounds(ballSpeed.interval, ball1.acc,minBallSpeed,initialBallSpeed);
}
