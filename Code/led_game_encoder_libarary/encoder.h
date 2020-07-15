#include "Arduino.h"

//Class deklaration for the encoder
//used this guide https://www.arduino.cc/en/Hacking/libraryTutorial

class Encoder
{
private:
  int state = 0;
  int _leftPin;
  int _rightPin;
  int oldCount = 0;
  public:
  int count = 0;
  int inc();
  bool checkTrigger();
   Encoder(int leftPin,int rightPin);
}; //end class header

bool Encoder::checkTrigger(){ //checking this trigger resets it!
    bool result = 0;
    if(count%4==0){ //We are at full step 
        if (count!=oldCount){ //it's a new step
        result = 1; //set flag
        oldCount = count; //resetting trigger
              }
    }
    return result;
}

//Construtor for Encoder, runs once when created. No return type
  Encoder::Encoder(int leftPin,int rightPin){
    // initialize the encoder pins as inputs:
    pinMode(leftPin, INPUT);
    pinMode(rightPin, INPUT);
      //save as private variables for later use.
      _leftPin = leftPin;
      _rightPin = rightPin;
  }
   
 int Encoder::inc(){//Incerement method, returns count
    // Read pins, correct inverted logic
    bool ENread[2]; //Saves time in the loop?
    ENread[0] = !digitalRead(_leftPin) ; //Store state of left pin, positive logic
    ENread[1] = !digitalRead(_rightPin) ; //Store state of right pin, positive logic
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
 //Possible improvement, set a flag when full step has changed
} 
