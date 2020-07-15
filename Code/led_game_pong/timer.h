#include "Arduino.h"
//Class Timer
/* function expired goes HIGH once if called when the set interval has expired, the timer is reset only when called. 
 *  Idea: change so that the timer keeps running?
 */

class Timer{
private:
int _interval = 0;
unsigned long lastTime = 0;
public:
Timer(int interval);
void interval(int interval);
bool expired();
}; //end class

Timer::Timer(int interval){
   //Timer.interval(interval);
      lastTime = millis(); // (re)start clock
      _interval = interval;
   }

void Timer::interval(int interval){ //change the interval
      lastTime = millis(); // (re)start clock
      _interval = interval;
}

bool Timer::expired(){
  bool expired = (millis() > (lastTime + _interval)); //goes high if timer has expired
if(expired){
      lastTime = millis(); // reset clock
}
  return expired; //Will return HIGH once when the timer has expired
}
