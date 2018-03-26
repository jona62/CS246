#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cstdlib>
#include <cmath>
#define PI 3.14159265359
using namespace std;


class Point{
  public:
    Point(double x = 0, double y = 0);
    void shift(double dx, double dy);
    void reset(double dx, double dy);
    void setYtoX();
    void setXtoY();
    void set_x(double);
    void set_y(double);
    double get_x() const;
    double get_y() const;

  protected:
      double x, y;
};

class Circle: public Point{
  private:
    double radius;
  public:
      Circle();
      Circle(double, double);
      Circle(double, double, double);
      void set_radius(double);
      double get_radius();
      double area();
      double perimeter();
      double diameter();
};

#endif // POINT_H
