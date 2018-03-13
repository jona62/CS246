class Point{
  public:
    Point(double init_x, double init_y){
      x = init_x;
      y = init_y;
    }

    void shift(double dx, double dy){
      x += dx;
      y += dy;
    }

    double get_x()const{
        return x;
    }

    double get_y()const{
        return y;
    }

    private:
      double x;
      double y;
};
