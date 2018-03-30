#include "main.h"

int main(){
  Ninja n;
  Boxer b;

  Player *ninja = &n;
  Player *boxer = &b;

  cout<<ninja->get_life()<<" ";
  cout<<ninja->get_health()<<" ";
  cout<<ninja->get_strength()<<" ";

  cout<<endl;

  cout<<boxer->get_life()<<" ";
  cout<<boxer->get_health()<<" ";
  cout<<boxer->get_strength()<<" ";

  cout<<endl;
  return 0;
}
