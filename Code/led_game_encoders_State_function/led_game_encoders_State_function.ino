/*
Test program for the encoders for the LED games project

Reads and logs the status of the encoders and prints them to the serial line after a set interval

Documentation at 
https://github.com/Jaknil/LED_games/blob/master/README.md
*/

const String encoders[] = {"ENC1.L", "ENC1.R","ENC1.S","ENC2.L","ENC2.R","ENC2.S"};
const int InputPinsEncoders[] = {3,6,4,2,5,7}; // 1K Hardware pull up and inverted logic
int ENC1[] = {3,6,0,0}; //Left pin, right pin, state,counter;
int ENC2[] = {2,5,0,0}; //Left pin, right pin, state,counter;
unsigned long timer = 0; 
int holdTime = 100; //in millis

void setup() {
    // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
// initialize the encoder pins as inputs:
  for (int i = 0; i < (sizeof(InputPinsEncoders) / sizeof(InputPinsEncoders[0])); i++) {
      pinMode(InputPinsEncoders[i], INPUT);
  }
}

void loop() {
//increment the encoders, as fast as possible
ENCinc(ENC1[0],ENC1[1],&ENC1[2],&ENC1[3]);//Left pin, right pin, state,counter;
ENCinc(ENC2[0],ENC2[1],&ENC2[2],&ENC2[3]);  //Left pin, right pin, state,counter;

//if enough time since read, send line
if (millis() > (timer + holdTime)){
Serial.print("ENC1: "); 
Serial.print(ENC1[3]/4); 
Serial.print(" ENC2: "); 
Serial.println(ENC2[3]/4); //send line
  timer = millis(); // reset clock
}
}

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
 
