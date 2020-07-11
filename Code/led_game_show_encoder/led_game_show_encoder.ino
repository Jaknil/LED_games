
/*
Test program for the display for the LED games project.
Adding in the encoder function

16x16 matrix

Single pixel is controlled like an etch a sketch
Reset to clear screen
Left encoder is X, horizontal axis. Clockwice (CW) is positive X, to the right
Right encoder is y, vertical axis. Clockwice (CW) is positive Y, to the top


Further documentation at 
https://github.com/Jaknil/LED_games/blob/master/README.md
*/

//MATRIX STUFF
#include <FastLED.h>
// Params for width and height
const uint8_t kMatrixWidth = 16;
const uint8_t kMatrixHeight = 16;
const bool    kMatrixSerpentineLayout = true;
// Bonus vocabulary word: anything that goes one way 
// in one row, and then backwards in the next row, and so on
// is call "boustrophedon", meaning "as the ox plows."

// Define the array of leds
#define NUM_LEDS (kMatrixWidth * kMatrixHeight)
CRGB leds_plus_safety_pixel[ NUM_LEDS + 1];
CRGB* const leds( leds_plus_safety_pixel + 1);
#define BRIGHTNESS 25
//OUTPUTS
#define DATA_PIN 12
//END MATRIX STUFF

//ETCH A SKETCH STUFF
//Start in the middle
#define Start_X 7
#define Start_Y 7


//ENCODER STUFF
const String encoders[] = {"ENC1.L", "ENC1.R","ENC1.S","ENC2.L","ENC2.R","ENC2.S"};
const int InputPinsEncoders[] = {3,6,4,2,5,7}; // 1K Hardware pull up and inverted logic
int ENC1[] = {3,6,0,Start_X*4}; //Left pin, right pin, state,counter; //Start counters in the middle
int ENC2[] = {2,5,0,Start_Y*4}; //Left pin, right pin, state,counter;
unsigned long timer = 0; 
int holdTime = 50; //in millis
//END ENCODER STUFF


void setup() {
//ENCODER STUFF
// initialize the encoder pins as inputs:
  for (int i = 0; i < (sizeof(InputPinsEncoders) / sizeof(InputPinsEncoders[0])); i++) {
      pinMode(InputPinsEncoders[i], INPUT);
  }
//END ENCODER STUFF


 //Matrix stuff
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   FastLED.setBrightness( BRIGHTNESS );
   FastLED.setMaxPowerInVoltsAndMilliamps(5,500); //500mA max
 //clear all
for( uint8_t x = 0; x < kMatrixWidth; x++) {
      for( uint8_t y = 0; y < kMatrixHeight; y++) {
     leds[ XYsafe( x, y) ] = CRGB::Black;
          }
        }
          FastLED.show(); //Send clear all 
//END Matrix stuff
        }
void loop() {

//increment the encoders, as fast as possible
ENCinc(ENC1[0],ENC1[1],&ENC1[2],&ENC1[3]);//Left pin, right pin, state,counter; //X
ENCinc(ENC2[0],ENC2[1],&ENC2[2],&ENC2[3]);  //Left pin, right pin, state,counter; //Y
//if enough time since read, refresh screen. Less sending = betting listening to encoders
if (millis() > (timer + holdTime)){
//blue cursor
leds[XYsafe(ENC2[3]/4,15-ENC1[3]/4)]=CRGB::Blue; //Encoder controlled-pixel  first coorrdinate y, second x (my screen is flipped)
  FastLED.show();
  //Paint with yellow
leds[XYsafe(ENC2[3]/4,15-ENC1[3]/4)]=CRGB::Yellow; //Encoder controlled-pixel  first coorrdinate y, second x (my screen is flipped)
  timer = millis(); // reset clock

//ideas, change color with click one stick, remove with other stick.
  
}


/*
//Testing a coordinate fill pattern the "XY" function like this:
    for( uint8_t x = 0; x < kMatrixWidth; x++) {
      for( uint8_t y = 0; y < kMatrixHeight; y++) {
     
       // Here's the x, y to 'led index' in action: 
     leds[ XYsafe( x, y) ] = CHSV( random8(), 255, 255);
     FastLED.show();
     delay(100);  //fills Y axis fast
     }
     delay(400); //waits half a sec between X steps
   }
 */
 
}
//FUNCTIONS

uint16_t XY( uint8_t x, uint8_t y)
{
  uint16_t i;
  
  if( kMatrixSerpentineLayout == false) {
    i = (y * kMatrixWidth) + x;
  }

  if( kMatrixSerpentineLayout == true) {
    if( y & 0x01) {
      // Odd rows run backwards
      uint8_t reverseX = (kMatrixWidth - 1) - x;
      i = (y * kMatrixWidth) + reverseX;
    } else {
      // Even rows run forwards
      i = (y * kMatrixWidth) + x;
    }
  }
  
  return i;
}

uint16_t XYsafe( uint8_t x, uint8_t y)
{
  if( x >= kMatrixWidth) return -1;
  if( y >= kMatrixHeight) return -1;
  return XY(x,y);
}

//Increment encoder function
int ENCinc(int ENC_L, int ENC_R, int *state, int *count_adress){
bool ENread[2]; //Saves time in the loop?
int count = *count_adress;
// Read pins, correct inverted logic
ENread[0] = !digitalRead(ENC_L) ; //Store state of left pin, positive logic
ENread[1] = !digitalRead(ENC_R) ; //Store state of right pin, positive logic
//Track state and increment / decrement conter for the direction the signal moved, there are 4 states per step
switch (*state) {
    case 0: //both low
if(ENread[0] && !ENread[1]){
  *state = 1;
  //CCW
 count--;
  }
  if(!ENread[0] && ENread[1]){
  *state = 3;
  //CW
  count++;
  }
  //Serial.println(count/4); //only print when we have a full step
  break;
        case 1: //L high
if(ENread[0] && ENread[1]){
  *state = 2;
   //CCW
   count--;
  }
    if(!ENread[0] && !ENread[1]){
  *state = 0;
  //CW
  count++;
  }
  break;
    case 2: //both high
if(!ENread[0] && ENread[1]){
  *state = 3;
     //CCW
     count--;
  }
  if(ENread[0] && !ENread[1]){
  *state = 1;
  //CW
  count++;
  }
  break;
    case 3: //R high
if(!ENread[0] && !ENread[1]){
  *state = 0;
  //CCW
  count--;
  }
    if(ENread[0] && ENread[1]){
  *state = 2;
  //CW
  count++;
  }
  break;
}
*count_adress = count;
}
