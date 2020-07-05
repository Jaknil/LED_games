
/*
Test program for the display for the LED games project

Documentation at 
https://github.com/Jaknil/LED_games/blob/master/README.md
*/
#include <FastLED.h>
#define NUM_LEDS 256
//OUTPUTS
#define DATA_PIN 12

// Define the array of leds
CRGB leds[NUM_LEDS];


// Params for width and height
const uint8_t kMatrixWidth = 16;
const uint8_t kMatrixHeight = 16;
const bool    kMatrixSerpentineLayout = true;
// Bonus vocabulary word: anything that goes one way 
// in one row, and then backwards in the next row, and so on
// is call "boustrophedon", meaning "as the ox plows."

void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   FastLED.setMaxPowerInVoltsAndMilliamps(5,500); //500mA max
  
}
void loop() {

 //X-y test
 
leds[XY(8,8)]=CRGB::Blue;
 
 // Move a single led 
   for(int ourLed = 0; ourLed < NUM_LEDS; ourLed = ourLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[ourLed].setRGB( 20, 20, 20);
      // Show the leds (only one of which is set to white, from above)
      FastLED.show();
      // Wait a little bit
      delay(100);
      // Turn our current led back to black for the next loop around
      leds[ourLed] = CRGB::Black;
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
