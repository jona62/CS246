class Clock{
  private:
    int hour;
    int minute;
    int sec;
  public:
    Clock();
    void set_hour(int x);
    void set_minute(int x);
    void set_sec(int x);
    int current_hour();
    int current_minute();
    int current_sec();
};
