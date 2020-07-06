/*
Test program for the encoders for the LED games project

Reads and logs the status of the encoders and prints them to the serial line after a set interval

Documentation at 
https://github.com/Jaknil/LED_games/blob/master/README.md
*/

const String encoders[] = {"ENC1.L", "ENC1.R","ENC1.S","ENC2.L","ENC2.R","ENC2.S"};
const int InputPinsEncoders[] = {3,6,4,2,5,7}; // 1K Hardware pull up and inverted logic

#define ENC1_L 3
#define ENC1_R 6

unsigned long time = 0; 
int holdTime = 500; //in millis
int EN1state = 0;
int EN1counter = 0;
bool EN1read[] = {1,1};

void setup() {
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

// initialize the encoder pins as inputs:
  for (int i = 0; i < (sizeof(InputPinsEncoders) / sizeof(InputPinsEncoders[0])); i++) {
      pinMode(InputPinsEncoders[i], INPUT);
  }
}

void loop() {



// Read pins, correct inverted logic
EN1read[0] = !digitalRead(ENC1_L) ; //Store state of left pin, positive logic
EN1read[1] = !digitalRead(ENC1_R) ; //Store state of right pin, positive logic


//Track state and increment / decrement conter for the direction the signal moved, there are 4 states per step
switch (EN1state) {
    case 0: //both low
if(EN1read[0] && !EN1read[1]){
  EN1state = 1;
  //CCW
  EN1counter--;
  }
  if(!EN1read[0] && EN1read[1]){
  EN1state = 3;
  //CW
  EN1counter++;
  }
  Serial.println(EN1counter/4);
  break;
        case 1: //L high
if(EN1read[0] && EN1read[1]){
  EN1state = 2;
   //CCW
   EN1counter--;
  }
    if(!EN1read[0] && !EN1read[1]){
  EN1state = 0;
  //CW
  EN1counter++;
  }
  break;
    case 2: //both high
if(!EN1read[0] && EN1read[1]){
  EN1state = 3;
     //CCW
     EN1counter--;
  }
  if(EN1read[0] && !EN1read[1]){
  EN1state = 1;
  //CW
  EN1counter++;
  }
  break;
    case 3: //R high
if(!EN1read[0] && !EN1read[1]){
  EN1state = 0;
  //CCW
  EN1counter--;
  }
    if(EN1read[0] && EN1read[1]){
  EN1state = 2;
  //CW
  EN1counter++;
  }
  break;
}
}

 

/*
//if enough time since read, send line
if (millis() > (time + holdTime)){
Serial.println(EN1counter); //send line
  time = millis(); // reset clock
  */
