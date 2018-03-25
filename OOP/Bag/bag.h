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
    void sort();
    void insert(int);
    void remove(int);
    int size();
    void print();
    void shift(int);
    void fillinArray();
    void deleteArray();
  protected:
    int *arr;
    int count;
};

class Set:public Bag{
  public:
    friend void Union(Set, Set);
    friend void InterSection(Set, Set);
};


 // void InterSection(Set bag1, Set bag2){
 //
 // }

#endif //BAG_H
