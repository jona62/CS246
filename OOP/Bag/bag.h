#ifndef BAG_H
#define BAG_H
// #define SIZE 20

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
using namespace std;

class Bag{
  public:
    Bag();
    Bag(int);
    bool isFull();
    bool isEmpty();
    void swap(int&,int&);
    void sort();
    void insert(int);
    void remove(int);
    int  size();
    void print();
    void shift(int);
    void fillinArray();
    void deleteArray();
  protected:
    int *arr;
    const int SIZE;
    int count;
};

#endif //BAG_H
