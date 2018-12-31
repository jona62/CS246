#ifndef STACH_H
#define STACH_H
#include <iostream>
using namespace std;

template <class T>
class Stack {
  private:
    struct Node {
      T data;
      Node *next;
    };
    Node *head;
    Node *tail;
    int count;

  // Recursive function to print contents of a stack
  void in_order(Node *nodePtr) {
    if(nodePtr == NULL) return;
    in_order(nodePtr->next);
    cout << nodePtr->data << " ";
  } 

  public:
    Stack();
    void push(T);
    T pop();
    void print();
    bool empty();
    void reverse();

};

template <class T>
Stack<T>::Stack() {
  head = NULL;
  tail = NULL;
  count = 0;
}

template <class T>
void Stack<T>::push(T data) {
  Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;

  if(head == NULL) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
  count++;
}

template <class T>
T Stack<T>::pop() {
  if(!empty()) {
    Node* prev = new Node;
    Node* curr = head;
    while(curr->next != NULL) {
      prev = curr;
      curr = curr->next;
    }
      T data = curr->data;
      delete curr;
      curr = NULL;
      prev->next = NULL;
      tail = prev;
      count--;
      return data;
   }
   return T();
  }

template <class T>
void Stack<T>::print() {
  Node *curr = head;
  in_order(curr);
}

template <class T>
void Stack<T>::reverse() {
  Node *current = head; 
  Node *prev = NULL;
  Node *next = NULL; 
  while (current != NULL) {  
    next = current->next;   
    current->next = prev;   
    prev = current; 
    current = next; 
  } 
  head = prev; 
} 

template <class T>
bool Stack<T>::empty() {
  return head == NULL || count == 0;
}

#endif //STACH_H