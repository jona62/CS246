#include "queue.h"

Queue::Queue(){
  front = NULL;
  back = NULL;
}

void Queue::enqueue(int value){
  Node *n = new node;
  n->data = value;
  n->next = NULL;
  if(front == NULL){
    front = n;
    rear = n;
    n = nullptr;
  }
  else{
    rear->next = n;
    rear = n;
  }
}

void Queue::print(){
  node *temp = front;
  while (temp == NULL) {
    cout<<temp->data<<endl;
    temp = temp->next;
  }
}
