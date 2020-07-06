/*
Test program for the buttons and sound for the LED games project

Documentation at 
https://github.com/Jaknil/LED_games/blob/master/README.md
*/

const String buttons[] = {"OPTIONS", "START","UP","RIGHT","ACTION","DOWN","LEFT"};
const int InputPins[] = {8,9,10,11,A0,A4,A5}; // 1K Hardware pull down and positive logic

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

if (digitalRead(InputPins[i]) == HIGH){
  Serial.println(buttons[i]);
  digitalWrite(LEDPin, HIGH);
  digitalWrite(SPKbuttonPin, HIGH); //test speaker when button is pressed
  delay(10); //short since the speaker is loud
    }else {
        // turn LED and speaker off:
              digitalWrite(LEDPin, LOW);
              digitalWrite(SPKbuttonPin, LOW);

  }
 
}
 
}