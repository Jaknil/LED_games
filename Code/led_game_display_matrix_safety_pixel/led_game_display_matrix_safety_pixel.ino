
/*
Test program for the display for the LED games project

Documentation at 
https://github.com/Jaknil/LED_games/blob/master/README.md
*/
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

void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   FastLED.setBrightness( BRIGHTNESS );
   FastLED.setMaxPowerInVoltsAndMilliamps(5,500); //500mA max
 
}
void loop() {
//clear all
for( uint8_t x = 0; x < kMatrixWidth; x++) {
      for( uint8_t y = 0; y < kMatrixHeight; y++) {
     leds[ XYsafe( x, y) ] = CRGB::Black;
          }
        }
   FastLED.show();
  delay(1000);
leds[XYsafe(8,8)]=CRGB::Blue; //test-pixel in the middle

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
