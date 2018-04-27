#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

class Queue{
  private:
      struct node{
        int data;
        node* next;
      };
    node *front;
    node *rear;
  public:
    Queue();
    void enqueue(int value);
    void dequeue();
    void print();
};

#endif //QUEUE_H
