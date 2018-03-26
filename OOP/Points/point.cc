#include "point.h"

Point::Point(double x, double y){
  this->x = x;
  this->y = y;
}

void Point::shift(double dx, double dy){
  x += dx;
  y += dy;
}

void Point::set_x(double x){
  this->x = x;
}

void Point::set_y(double y){
  this->y = y;
}

double Point::get_x()const{
    return x;
}

double Point::get_y()const{
    return y;
}

void Point::reset(double dx, double dy){
  x = dx;
  y = dy;
}

void Point::setYtoX(){
  y = x;
}

void Point::setXtoY(){
  x = y;
}

//Cirle Derived Class

Circle::Circle(){
  set_radius(5);
}

Circle::Circle(double x, double y){
  this->x = x;
  this->y = y;
  set_radius(5);
}

Circle::Circle(double x, double y, double radius){
  this->radius = radius;
  this->x = x;
  this->y = y;
}

void Circle::set_radius(double radius){
  this->radius = radius;
}

double Circle::get_radius(){
  return radius;
}

double Circle::area(){
  int area = PI*pow(radius,2);
  return area;
}

double Circle::perimeter(){
  int perimeter = 2 * PI * radius;
  return perimeter;
}

double Circle::diameter(){
  int diameter = radius * 2;
  return diameter;
}
