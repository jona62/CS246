#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace std;

template<class T>
class Queue{
  private:
    struct Node{
      T data;
      Node *next;
    };
    Node *front;
    Node *rear;
  

  public:
    Queue();
    void enqueue(T);
    void dequeue();
    T top();
    bool empty() {
      return front == NULL;
    }

};

template<class T>
Queue<T>::Queue() {
  front = NULL;
  rear = NULL;
}

template<class T>
void Queue<T>::enqueue(T value) {
  Node *temp = new Node;
  temp->data = value;
  temp->next = NULL;
  if(front == NULL) {
    front = temp;
    rear = temp;
  }
  else {
    rear->next = temp;
    rear = temp;
  }
}

// Returns element in front of the Queue
template<class T>
void Queue<T>::dequeue() {
  try {
    if(empty()) {
      throw "Queue is empty";
    }
  } catch(const char *err) {
    cerr << "Exception: " << err << '\n';
    return;
  }
  
  Node *delPtr = front;
  front = front->next;
  delete delPtr;
  delPtr = NULL;
}
  
template<class T>
T Queue<T>::top() {
  try {
    if(!empty()) {
      return front->data;
    }
    throw "Queue is empty!";  
  } catch (const char *err) {
    cerr << "Exception: " << err << "\n";
  }
}


#endif //QUEUE_H
