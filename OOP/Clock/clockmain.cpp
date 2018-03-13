#include <iostream>
#include <ctime>
#include "clock.h"
using namespace std;

int main(){
  time_t curr_time;
  curr_time = time(NULL);
  tm *tm_local = localtime(&curr_time);
  int hour = tm_local->tm_hour;
  int min = tm_local->tm_min;
  int sec = tm_local->tm_sec;

  Clock time;
  time.set_hour(hour);
  time.set_minute(min);
  time.set_sec(sec);

  cout<<time.current_hour()<<":"<<time.current_minute()<<":"<<time.current_sec()<<endl;
  
  return 0;
}
