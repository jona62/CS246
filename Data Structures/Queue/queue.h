#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

class Queue{
  private:
    struct Node{
      int data;
      Node *next;
    };
    Node *front;
    Node *rear;

  public:
    Queue();
    void enqueue(int);
    void dequeue(int);
    void front();
    void print();
    bool isEmpty();

};

#endif //QUEUE_H
