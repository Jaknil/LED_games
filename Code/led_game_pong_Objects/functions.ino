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


void printStuff(){
  Serial.print("ENC1: ");
    Serial.print(ENC1.count/4);
    Serial.print(" ENC2: ");
    Serial.println(ENC2.count/4); //send line
  }

void clearAllLeds(){//clear all
for( uint8_t x = 0; x < kMatrixWidth; x++) {
      for( uint8_t y = 0; y < kMatrixHeight; y++) {
     leds[ XYsafe( x, y) ] = CRGB::Black;
          }
        }
   FastLED.show();
}
  
//FUNCTIONS
uint32_t XY( uint8_t x, uint8_t y)
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

//REMOVE AN OLD LINE AND DRAW A NEW ONE, now eats a line object and a colour
void updateLineObj(Line LineToBeUpdated,uint32_t colour){
  for(int i = 0; i < LineToBeUpdated.leng; i++) {
       leds[ XYsafe( i+LineToBeUpdated.oldX, LineToBeUpdated.y) ] = CRGB::Black;   //delete old line
  }
 for(int i = 0; i < LineToBeUpdated.leng; i++) {
       leds[ XYsafe( i+LineToBeUpdated.x,LineToBeUpdated.y) ] = colour;  //fill new paddle
    }
}
