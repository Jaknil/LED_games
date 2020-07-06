/*
Test program for the buttons and sound for the LED games project

Documentation at 
https://github.com/Jaknil/LED_games/blob/master/README.md
*/

const String buttons[] = {"OPTIONS", "START","UP","RIGHT","ACTION","DOWN","LEFT","ENC1S","ENC2S"};
const int InputPins[] = {8,9,10,11,A0,A4,A5,4,7}; // 1K Hardware pull down and positive logic for most, encoders are inverted
int buttonStatus[sizeof(buttons) / sizeof(buttons[0])];

//OUTPUTS
#define LEDPin 13      // the number of the onboard LED OUTPUT pin 
#define SPKbuttonPin A3     // the number of the SPK speaker OUTPUT pin (active with 150Ohm series resistor)

void setup() {
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the outputs:
  pinMode(LEDPin, OUTPUT);
  pinMode(SPKbuttonPin, OUTPUT);
  
  // initialize the button pins as inputs:
  for (int i = 0; i < (sizeof(InputPins) / sizeof(InputPins[0])); i++) {
      pinMode(InputPins[i], INPUT);
  }
}

void loop() {

//Step through and read all button pins
for (int i = 0; i < (sizeof(buttons) / sizeof(buttons[0])); i++) {
buttonStatus[i] = digitalRead(InputPins[i]);

//invert the encoder pins
buttonStatus[7] = !buttonStatus[7];
buttonStatus[8] = !buttonStatus[8];
//do something with the data
if (buttonStatus[i] == HIGH){
  Serial.println(buttons[i]); //print the pressed button to serial
}
}

//test LED
 if(buttonStatus[4] == HIGH){
  digitalWrite(LEDPin, HIGH);
  delay(10);
}  else {
    digitalWrite(LEDPin, LOW);
  }
//test speaker

  if(buttonStatus[0]==HIGH && buttonStatus[1]==HIGH){ //test speaker when both small buttons are pressed
  digitalWrite(SPKbuttonPin, HIGH); 
  delay(10); //short since the speaker is loud
    }else {
        // turn speaker off:
                            digitalWrite(SPKbuttonPin, LOW);
  }
}
