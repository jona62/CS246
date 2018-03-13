#include <iostream>
#include <cstdlib>
#include "point.h"

int main(){
  Point p1(1.0, 1.9);
  std::cout<<"\nPoint : ("<<p1.get_x()<<", "<<p1.get_y()<<")\n";

   p1.shift(1.0,1.0);
   std::cout<<"Point after a shift : ("<<p1.get_x()<<", "<<p1.get_y()<<")\n";

  Circle cir(11,23);

  std::cout<<"Circle center : ("<<cir.get_x()<<", "<<cir.get_y()<<") \n";
  std::cout<<"Radius : "<<cir.get_radius()<<"\n";

 return 0;
}
