#include "queue.h"

Queue::Queue(){
  front = NULL;
  rear = NULL;
}

void Queue::enqueue(int value){
  node *n = new node;
  n->data = value;
  if(front == NULL){
    n->next  = NULL;
    front = n;
    rear = n;
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
