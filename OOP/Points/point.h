class Point{
  public:
    Point(double init_x=0, double init_y=0);
    void shift(double dx, double dy);
    double get_x() const;
    double get_y() const;
    void reset(double dx, double dy);
    void setYtoX();
    void setXtoY();

    private:
      double x;
      double y;
};
