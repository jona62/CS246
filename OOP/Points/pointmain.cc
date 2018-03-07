#include <iostream>
#include <cstdlib>
#include "point.h"

int main(){
  Point p1(1.0, 1.9);
  std::cout<<"\n("<<p1.get_x()<<", "<<p1.get_y()<<")\n";

   p1.shift(1.0,1.0);
   std::cout<<"("<<p1.get_x()<<", "<<p1.get_y()<<")\n";

 return 0;
}
