#include "main.h"

void Player::set_life(int life){
  this->life = life;
}

void Player::set_health(int health){
  this->health += health;
}

void Player::set_strength(int strength){
  this->strength = strength;
}

int Player::get_strength(){
  return strength;
}

int Player::get_health(){
  return health;
}

int Player::get_life(){
  return life;
}

// Ninja class
Ninja::Ninja(){
  set_life(3);
  set_health(100);
  set_strength(60);
}

Boxer::Boxer(){
  set_life(1);
  set_health(100);
  set_strength(100);
}

// void attack(Player player){
//   player.set_health(-10);
//
// }
//
// void defend(Player player);
//
// bool missed();
