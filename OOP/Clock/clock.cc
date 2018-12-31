#include "clock.h"

int Clock::current_hour(){
  return time_seed()->tm_hour;
}

int Clock::current_minute(){
  return time_seed()->tm_min;
}

int Clock::current_sec(){
  return time_seed()->tm_sec;
}

void Clock::set_interval(int wait_time) {
  int intervals = time_seed()->tm_sec;
  while(wait_time > 0) {
    tm *loc_time = time_seed();
    if(loc_time->tm_sec - intervals ==  1) {
      wait_time--;
    }
    intervals = loc_time->tm_sec;
  }
}