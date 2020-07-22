#include "Arduino.h"
//Class Timer
/* function expired goes HIGH once if called when the set interval has expired, the timer is reset only when called. 
 *  Idea: change so that the timer keeps running?
 */

class Timer{
private:
unsigned long lastTime = 0;
public:
int interval = 0;
Timer(int setInterval);
bool expired();
}; //end class

Timer::Timer(int setInterval){
       lastTime = millis(); // (re)start clock
      interval = setInterval;
   }


bool Timer::expired(){
  bool expired = (millis() > (lastTime + interval)); //goes high if timer has expired
if(expired){
      lastTime = millis(); // reset clock
}
  return expired; //Will return HIGH once when the timer has expired
}
