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
  Encoder ENC1(3,6);  
  Encoder ENC2(2,5);

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
#define DATA_PIN 12

//GAME STARTS HERE
class Ball{
private:
public:
int x = 5;
int y = 7;
int veloX = 1;
int veloY = 1;
int oldX = x;
int oldY = y;
int acc = -50; //how much time to reduce the increment with
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
}
;

class Paddle{
private:
public:
int x = 1;
int oldX = x;
int y = 2;
int leng = 5;
 
};
//Create the game pieces
Paddle player1;

Paddle player2;

Ball ball1;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
    //Matrix
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   FastLED.setBrightness( BRIGHTNESS );
   FastLED.setMaxPowerInVoltsAndMilliamps(5,500); //500mA max
  clearAllLeds(); // 
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(200);

//setup players
player1.x=1;
player1.y=13;
player2.x=1;
player2.y=2;


    
}

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



void loop() {
if(ballSpeed.expired()){
 ball1.inc();
//check collissions in next step by moving paddle towards ball
if(ball1.collide(player1.x-ball1.veloX,player1.y-ball1.veloY,player1.leng)){
   ball1.bounceY();
   ballSpeed.interval = applyBounds(ballSpeed.interval, ball1.acc,minBallSpeed,initialBallSpeed);
   }
else if(ball1.collide(player2.x-ball1.veloX,player2.y-ball1.veloY,player2.leng)){
   ball1.bounceY();
   ballSpeed.interval = applyBounds(ballSpeed.interval, ball1.acc,minBallSpeed,initialBallSpeed);
}
  //update ball positon on led matrix
   leds[XYsafe(ball1.oldX,ball1.oldY)]=CRGB::Black; //erase old ball
 leds[XYsafe(ball1.x,ball1.y)]=CRGB::Blue; //add new ball
//update paddle to not "loose" leds when paddle goes on top of ball position
  fill1(player1.x); //Update paddle pos on led matrix
  fill2(player2.x); //Update paddle pos on led matrix
  }
 //increment the encoders, as fast as possible
  ENC1.inc();
  ENC2.inc();
      if(ENC1.checkTrigger() || ENC2.checkTrigger()){ //when there is new data any encoder
// Set player positions to match encoders
player1.x= ENC1.countFull; 
player2.x= ENC2.countFull; 
//SUGGESTION: perhaps better to return diff from encoder and keep the bounds in the paddle for a more logical structure?
//make method instead? 
  fill1(player1.x); //Update paddle pos on led matrix
  fill2(player2.x); //Update paddle pos on led matrix
   }
     if (drawInterval.expired()){ //if enough time passed
          FastLED.show();  
 
}
} //END LOOP
//FUNCTIONS



//IN WORK
void drawPlayer(int x,int y, bool kill){
 if(kill){
  for(int i = 0; i < player1.leng; i++) { //fix length
       leds[ XYsafe( i+x, y) ] = CRGB::Black;
    }} else{
      for(int i = 0; i < player1.leng; i++) {
       leds[ XYsafe( i+x, player1.y) ] = CRGB::Yellow;
    }
    }

}


//Make this work better!! LOOK AT MATRIX DATA, usable or make own from bool?
void fill1(int x){
  
 //delete old paddle
  for(int i = 0; i < player1.leng; i++) {
       leds[ XYsafe( i+player1.oldX, player1.y) ] = CRGB::Black;
    }
 //fill new paddle
     for(int i = 0; i < player1.leng; i++) {
       leds[ XYsafe( i+player1.x, player1.y) ] = CRGB::Red;
         }
      player1.oldX=x;
    
}
//Make this work better!! LOOK AT MATRIX DATA, usable or make own from bool?
void fill2(int x){
  
 //delete old paddle
  for(int i = 0; i < player1.leng; i++) {
       leds[ XYsafe( i+player2.oldX, player2.y) ] = CRGB::Black;
    }
 //fill new paddle
     for(int i = 0; i < player2.leng; i++) {
       leds[ XYsafe( i+player2.x, player2.y) ] = CRGB::Red;
          }
      player2.oldX=x;
    
}
