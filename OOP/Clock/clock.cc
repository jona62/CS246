#include "clock.h"

Clock::Clock(){
  hour = 0;
  minute = 0;
  sec = 0;
}

int Clock::current_hour(){
  return hour;
}

int Clock::current_minute(){
  return minute;
}

int Clock::current_sec(){
  return sec;
}

void Clock::set_hour(int x){
  hour = x;
}

void Clock::set_minute(int x){
  minute = x;
}

void Clock::set_sec(int x){
  sec = x;
}
