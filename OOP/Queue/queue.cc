#include "queue.h"

Queue::Queue(){
  front = NULL;
  rear = NULL;
}

void Queue::enqueue(int value){
  Node *n = new Node;
  n->data = value;
  n->next = NULL;
  if(front == NULL){
    front = n;
    rear = n;
  }
  else{
    rear->next = n;
    rear = n;
  }
}

void Queue::print(){
  Node *temp = front;
  while(temp != NULL){
    cout<<temp->data<<"\t";
    temp=temp->next;
  }
}
