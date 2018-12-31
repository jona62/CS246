#include <iostream>
#include <cstdio>
#include "clock.h"
using namespace std;

int main(){
  Clock c;
  
  while(true) {
    system("clear");
    cout << c.current_hour() << ":";
    cout << c.current_minute() << ":";
    cout << c.current_sec() << "\n";
    c.set_interval(1);
  }

  return 0;
}
