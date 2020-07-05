/*
Test program for the encoders for the LED games project

Reads and logs the status of the encoders and prints them to the serial line after a set interval

Documentation at 
https://github.com/Jaknil/LED_games/blob/master/README.md
*/

const String encoders[] = {"ENC1.L", "ENC1.R","ENC1.S","ENC2.L","ENC2.R","ENC2.S"};
const int InputPinsEncoders[] = {3,6,4,2,5,7}; // 1K Hardware pull up and inverted logic

int hitsEncoders[]={0,0,0,0,0,0}; 
unsigned long time = 0; 
int holdTime = 500; //in millis


//OUTPUTS
#define LED_SIGPin 12     // the number of the LED_SIG OUTPUT pin
#define LEDPin 13      // the number of the onboard LED OUTPUT pin 
#define SPKbuttonPin A7     // the number of the SPK speaker OUTPUT pin (active with 150Ohm series resistor)

void setup() {
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

// initialize the encoder pins as inputs:
  for (int i = 0; i < (sizeof(InputPinsEncoders) / sizeof(InputPinsEncoders[0])); i++) {
      pinMode(InputPinsEncoders[i], INPUT);
  }
}

void loop() {

//Step through and read all encoder pins
for (int i = 0; i < (sizeof(encoders) / sizeof(encoders[0])); i++) {
if (digitalRead(InputPinsEncoders[i]) == LOW){
    //hitsEncoders[i]++;
    hitsEncoders[i] = hitsEncoders[i] + 1;
  //Serial.print(encoders[i]);
  //Serial.println(hitsEncoders[i]);
  digitalWrite(LEDPin, HIGH);
    }else {
        // turn LED off:
    digitalWrite(LEDPin, LOW);
  }
}
//if enough time since read, send line
if (millis() > (time + holdTime)){
  for (int i = 0; i < (sizeof(encoders) / sizeof(encoders[0])); i++) {
Serial.print(encoders[i]);
Serial.print(" = ");
Serial.print(hitsEncoders[i]);
Serial.print(",");
hitsEncoders[i] = 0; //clear after printing
  }
Serial.println(); //send line
//hitsEncoders[] = {0,0,0,0,0,0}; //reset counters
//memset(hitsEncoders, 0, sizeof(hitsEncoders)/sizeof(hitsEncoders[0]) );
  time = millis(); // reset clock
}
}
