#include "Dynamic_stacks.h"

template <class T>
bool Stack<T>::isEmpty(){
  return (top == NULL);
}

template <class T>
void Stack<T>::push(T value){
  node* temp = new node;
  temp->data = value;

  if(isEmpty()){
    temp->next = NULL;
    top = temp;
  }
  else{
    temp->next = top;
    top = temp;
  }
}

template <class T>
T Stack<T>::pop(){
  T value;
  node* temp = new node;
  if(isEmpty()){
    cout<<"Stack is Empty ";
  }
  else{
    value = top->data;
    temp = top->next;
    delete top;
    top = temp;
  }
  return value;
}

template <class T>
void Stack<T>::print(){
  node* temp = top;
  while(temp != NULL){
    cout<<temp->data;
    temp = temp->next;
  }
}
