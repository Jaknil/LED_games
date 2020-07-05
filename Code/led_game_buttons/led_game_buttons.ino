/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Button
*/

const String buttons[] = {"OPTIONS", "START","UP","RIGHT","ACTION","DOWN","LEFT"};
const int InputPins[] = {8,9,10,11,A0,A4,A5}; // 1K Hardware pull up and positive logic
/*
//INPUT PINS for the buttons
#define OPTIONSbuttonPin 8     // the number of the OPTIONS pin
#define STARTbuttonPin 9     // the number of the START pin
#define UPbuttonPin 10     // the number of the UP pin
#define RIGHTbuttonPin 11     // the number of the RIGHT pin
#define ACTIONbuttonPin A0     // the number of the ACTION pin
#define DOWNbuttonPin A4     // the number of the DOWN pin
#define LEFTbuttonPin A5     // the number of the LEFT pin
*/

//OUTPUTS
#define LED_SIGPin 12     // the number of the LED_SIG OUTPUT pin
#define LEDPin 13      // the number of the onboard LED OUTPUT pin 
#define SPKbuttonPin A7     // the number of the SPK speaker OUTPUT pin (active with 150Ohm series resistor)

void setup() {
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // initialize the outputs:
  pinMode(LED_SIGPin, OUTPUT);
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
  delay(100);
    }else {
        // turn LED off:
    digitalWrite(LEDPin, LOW);
  }
 
}
 
}
