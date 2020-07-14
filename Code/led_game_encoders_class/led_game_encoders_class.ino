/*
Test program for the encoders for the LED games project

Reads and logs the status of the encoders and prints them to the serial line after a set interval

My first attempt at using classes for Arduino

Documentation at
https://github.com/Jaknil/LED_games/blob/master/README.md
*/
class Encoder
{
private:
  int state = 0;
public:
  int leftPin = 0;
  int rightPin = 0;
  void begin();
  int count = 0;
  //Incerement method, returns count
  int inc(){
    // Read pins, correct inverted logic
    bool ENread[2]; //Saves time in the loop?
    ENread[0] = !digitalRead(leftPin) ; //Store state of left pin, positive logic
    ENread[1] = !digitalRead(rightPin) ; //Store state of right pin, positive logic
    //Track state and increment / decrement conter for the direction the signal moved, there are 4 states per step
    //they form a two bit gray code that is used to track the current position times 4.
    switch (state) {
      case 0: //both low, likely start
      if(ENread[0] && !ENread[1]){
        state = 1; //L high
        count--;//CCW
      }
      if(!ENread[0] && ENread[1]){
        state = 3;//R high
        count++;//CW
      }
      break;
      case 1: //L high
      if(ENread[0] && ENread[1]){
        state = 2;//both high
        count--;//CCW
      }
      if(!ENread[0] && !ENread[1]){
        state = 0;//both low, back to start
        count++;//CW
      }
      break;
      case 2: //both high
      if(!ENread[0] && ENread[1]){
        state = 3;//R high
        count--;  //CCW
      }
      if(ENread[0] && !ENread[1]){
        state = 1;//L high
        count++;        //CW
      }
      break;
      case 3: //R high
      if(!ENread[0] && !ENread[1]){
        state = 0;//both low, back to start
        count--;        //CCW
      }
      if(ENread[0] && ENread[1]){
        state = 2;//both high
        count++;        //CW
      }
      break;
    }
  }


}; //end encoder class

  void Encoder::begin(){ // initialize the encoder pins as inputs:
    pinMode(leftPin, INPUT);
    pinMode(rightPin, INPUT);
}


//Timer
unsigned long timer = 0;
int holdTime = 100; //in millis

//Create our encoders
  Encoder ENC1;  
  Encoder ENC2;
  
void setup() {
  //Setup our encoders
  ENC1.leftPin = 3;
  ENC1.rightPin = 6;
  ENC2.leftPin = 2;
  ENC2.rightPin = 5;
  ENC1.begin();
  ENC2.begin();

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

}

void loop() {
  //increment the encoders, as fast as possible
  ENC1.inc();
  ENC2.inc();

  //if enough time since read, send line
  if (millis() > (timer + holdTime)){
    Serial.print("ENC1: ");
    Serial.print(ENC1.count/4);
    Serial.print(" ENC2: ");
    Serial.println(ENC2.count/4); //send line
    timer = millis(); // reset clock
  }
}
