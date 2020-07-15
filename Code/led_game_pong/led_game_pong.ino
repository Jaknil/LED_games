/*
Test program for the encoders for the LED games project

Reads and logs the status of the encoders and prints them to the serial line after a set interval

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
Timer ballSpeed(200);
//Matrix
// Params for width and height
const uint8_t kMatrixWidth = 16;
const uint8_t kMatrixHeight = 16;
const bool    kMatrixSerpentineLayout = true;
// Define the array of leds
#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds_plus_safety_pixel[ NUM_LEDS + 1];
CRGB* const leds( leds_plus_safety_pixel + 1);
#define BRIGHTNESS 25
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
void inc(){
  oldX=x;
  x=x+veloX;
  oldY=y;
  y=y+veloY;
  if(x>=kMatrixWidth-1 || x==0){
    veloX = veloX*(-1);
  }
  if(y>=kMatrixHeight-1 || y==0){
    veloY = veloY*(-1);
  }
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
int updateX(int value){
int minX = 1;
int maxX = kMatrixWidth-leng-1;
  x = value;
  if(value>maxX){
 /*   Serial.print("adjusted X from ");
    Serial.print(value);
    Serial.print(" to ");
    Serial.println(maxX);*/
    x=maxX;
  }
  if(x<minX){
    x=minX;
  }
}
  
};
//Create the game pieces
Paddle player1;

//IN WORK
/*player1.x=1;
player1.y=2;
Paddle player2;
player2.x=1;
player2.y=kMatrixHeight-3; //IS HEIGH WIDTH CORRECT??!
*/
Ball ball1;

void setup() {
  // initialize serial communication at 9600 bits per second:
//  Serial.begin(9600);
  
    //Matrix
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   FastLED.setBrightness( BRIGHTNESS );
   FastLED.setMaxPowerInVoltsAndMilliamps(5,500); //500mA max
  clearAllLeds(); // 
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(200);

    
}

void loop() {
  //increment the encoders, as fast as possible
  ENC1.inc();
  ENC2.inc();
if(ballSpeed.expired()){
 ball1.inc();
 fill(player1.x);
   leds[XYsafe(ball1.oldX,ball1.oldY)]=CRGB::Black; //erase old ball
 leds[XYsafe(ball1.x,ball1.y)]=CRGB::Blue; //add new ball
 }
  
      if(ENC1.checkTrigger() || ENC2.checkTrigger()){ //when there is new data any encoder
player1.updateX(ENC1.countFull); 
ENC1.count = player1.x*4;//keep it within bounds
/*IN WORK
 player2.updateX(ENC2.countFull); 
ENC2.count = player2.x*4;//keep it within bounds
*/
 
 }
    if (drawInterval.expired()){ //if enough time passed
          FastLED.show();  
 
}
}


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
void fill(int x){
  
 //delete old paddle
  for(int i = 0; i < player1.leng; i++) {
       leds[ XYsafe( i+player1.oldX, player1.y) ] = CRGB::Black;
    }
 //fill new paddle
     for(int i = 0; i < player1.leng; i++) {
       leds[ XYsafe( i+player1.x, player1.y) ] = CRGB::Red;
  //check collission
  //TODO ADD DIFFERENT COLLISSION DEPENDING ON WHERE
    if(ball1.x == i+player1.x && ball1.y == player1.y){
  ball1.veloY=ball1.veloY*(-1);
 }
         }
      player1.oldX=x;
    
}
