
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


void setup() {
    // sanity check delay - allows reprogramming if accidently blowing power w/leds
    delay(2000);
   FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
   FastLED.setMaxPowerInVoltsAndMilliamps(5,500); //500mA max
}
void loop() {
 // Move a single white led 
   for(int whiteLed = 0; whiteLed < NUM_LEDS; whiteLed = whiteLed + 1) {
      // Turn our current led on to white, then show the leds
      leds[whiteLed].setRGB( 20, 20, 20);

      // Show the leds (only one of which is set to white, from above)
      FastLED.show();

      // Wait a little bit
      delay(100);

      // Turn our current led back to black for the next loop around
      leds[whiteLed] = CRGB::Black;
   }
 
}
