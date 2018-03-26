#include "point.h"

int main(){
  Point p1(1.0, 1.9);
  cout<<"\nPoint : ("<<p1.get_x()<<", "<<p1.get_y()<<")\n";

   p1.shift(1.0,1.0);
   cout<<"Point after a shift : ("<<p1.get_x()<<", "<<p1.get_y()<<")\n";

  Circle cir(11,23);

  cout<<"Circle center : ("<<cir.get_x()<<", "<<cir.get_y()<<") \n";
  cout<<"Radius : "<<cir.get_radius()<<"\n";
  cout<<"Diameter : "<<cir.diameter()<<"\n";
  cout<<"Area : "<<cir.area()<<"\n";
  cout<<"Perimeter : "<<cir.perimeter()<<"\n";
 return 0;
}
