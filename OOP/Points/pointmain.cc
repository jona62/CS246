#include <iostream>
#include <cstdlib>
#include "point.h"
using namespace std;

int main(){
  Point p1(1.0, 0.0);
  cout<<"\n("<<p1.get_x()<<", "<<p1.get_y()<<")\n";

   p1.reset(120,120);
   cout<<"("<<p1.get_x()<<", "<<p1.get_y()<<")\n";


 return 0;
}
