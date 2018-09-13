#ifndef LINKED_H
#define LINKED_H

class LinkedList {
  private:
    struct Node {
      int data;
      Node *next;
    };

  Node *head;
  Node *tail;
  int count;

  public:
    LinkedList();
    void push(int);
    int pop();
    void push_front(int);
    int pop_front();
    void insert(int, int);
    int value_at(int);
    int front();
    int back();
    void reverse();
    void remove_value(int);
    bool isEmpty();
    int size();
    void print();
};


#endif //LINKED_H
