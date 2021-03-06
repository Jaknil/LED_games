#include "Arduino.h"

//Class deklaration for the encoder
//used this guide https://www.arduino.cc/en/Hacking/libraryTutorial

class Encoder
{
private:
  int state = 0;
  int _leftPin;
  int _rightPin;
  int oldCount = -1; //to start with a trigger
  public:
  int minCount = 1;
  int maxCount = 10;
  int count = 0;
  int countFull = 0;
  void inc();
  bool checkTrigger();
   Encoder(int leftPin,int rightPin);
   void setStart(int start);
}; //end class header

//WEAKNESS: it uses two variables to store the position. count and countfull. setting a start number is messy

void Encoder::setStart(int start){
  count = start*4; //sets the starting value to be returned
}

bool Encoder::checkTrigger(){ //checking this trigger resets it!
    bool result = 0;
    if(count%4==0){ //We are at full step 
       countFull=count/4; //update full step value
       //check bounds
       if(countFull < minCount){
    count = minCount*4;
  }
     if(countFull > maxCount){
    count = maxCount*4;
  } //out of bounds should not return new step
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
   
 void Encoder::inc(){//Incerement method, updates count and countFull
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
} 
