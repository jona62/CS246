#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

class Player{
  public:
    void set_life(int);
    void set_health(int);
    void set_strength(int);
    int get_strength();
    int get_health();
    int get_life();

    // void attack(Player);
    // void defend(Player);
    // bool missed();

  protected:
    int life;
    int health;
    int strength;
};

class Ninja:public Player{
  public:
    Ninja();
};

class Boxer:public Player{
  public:
    Boxer();
};

#endif //MAIN_H
