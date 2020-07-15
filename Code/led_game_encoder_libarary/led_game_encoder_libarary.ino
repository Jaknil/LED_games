/*
Test program for the encoders for the LED games project

Reads and logs the status of the encoders and prints them to the serial line after a set interval

My first attempt at using classes for Arduino

Documentation at
https://github.com/Jaknil/LED_games/blob/master/README.md
*/

#include "encoder.h"
#include "timer.h"




//Create our encoders, name(leftpin, rightpin)
  Encoder ENC1(3,6);  
  Encoder ENC2(2,5);

//Create timer
Timer printInterval(100);
  
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  //increment the encoders, as fast as possible
  ENC1.inc();
  ENC2.inc();
  
      if (printInterval.expired()){ //if enough time since last test
      if(ENC1.checkTrigger() || ENC2.checkTrigger()){ //check if there is new data on encoders (ch
      printStuff(); //if both true print stuff. if not, check again in after interval
          } 
  }
}



void printStuff(){
  Serial.print("ENC1: ");
    Serial.print(ENC1.count/4);
    Serial.print(" ENC2: ");
    Serial.println(ENC2.count/4); //send line
  }
