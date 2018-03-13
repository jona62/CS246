#ifndef BAG_H
#define BAG_H
#define SIZE 20

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Bag{
  public:
    Bag();
    void insert(int);
    void remove(int);
    void print();
    bool isFull();
    bool isEmpty();
    void shift(int);
    void swap(int&,int&);

  private:
    int arr[SIZE];
    int count;
};


#endif //BAG_H
