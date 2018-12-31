#include <ctime>

class Clock {
  private:
    static tm* time_seed() {
      time_t curr_time;
      curr_time = time(NULL);
      tm *tm_local = localtime(&curr_time);  
      return tm_local;
    }

  public:
    int current_hour();
    int current_minute();
    int current_sec();
    void set_interval(int);
};
