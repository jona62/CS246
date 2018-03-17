#ifndef BAG_H
#define BAG_H
#define SIZE 20

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cassert>
using namespace std;

class Bag{
  public:
    Bag();
    bool isFull();
    bool isEmpty();
    void swap(int&,int&);
    void insert(int);
    void remove(int);
    int size();
    void print();
    void shift(int);
    void fillinArray();
    void deleteArray();
  private:
    int arr[SIZE];
    int count;
};


#endif //BAG_H
