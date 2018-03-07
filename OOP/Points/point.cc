#include "point.h"
Point::Point(double init_x, double init_y){
  x = init_x;
  y = init_y;
}

void Point::shift(double dx, double dy){
  x += dx;
  y += dy;
}

double Point::get_x()const{
    return x;
}

double Point::get_y()const{
    return y;
}

void Point::reset(double dx, double dy){
  // while(dx > 120 || dy > 120){
  //   cout<<"Enter a lesser number: ";
  //   cin>>dx>>dy;
  //   }
  x = dx;
  y = dy;
}

void Point::setYtoX(){
  y = x;
}

void Point::setXtoY(){
  x = y;
}
