#ifndef DYNAMICSTACKS_H
#define DYNAMICSTACKS_H
#include <iostream>
using namespace std;

template <class T>
class Stack{
  private:
    struct node{
      T data;
      node* next;
    };
    node* top;
  public:
    Stack():top(NULL){}
    bool isEmpty();
    void push(T);
    T pop();
    void print();
    void reverse();
};

template <class T>
bool Stack<T>::isEmpty(){
  return (top == NULL);
}

template <class T>
void Stack<T>::push(T value){
  node* temp = new node;
  temp->data = value;

//If stack is empty top gets the node
  if(isEmpty()){
    temp->next = NULL;
    top = temp;
  }
  else{//else node becomes top and it's next is the address to the previous top
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
  else{ // deletes top and returns its value
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
    cout<<temp->data<<endl;
    temp = temp->next;
  }
}

template <class T>
void Stack<T>::reverse() {
  node *current = top;
  node *prev = NULL;
  node *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  top = prev;
}

#endif //DYNAMICSTACKS_H
