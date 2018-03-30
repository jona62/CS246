#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

class List{
  private:
    typedef struct node{
      int data;
      node *next;
    } *nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;

  public:
    List();
    void addNode(int addData);
    void deleteNode(int delData);
    void printList();
    void insertRandom(int);
};

List::List():head(NULL),curr(NULL),temp(NULL){
  /*
  head = NULL;
  curr = NULL;
  temp = NULL;
  */
}

void List::addNode(int addData){
  nodePtr n = new node;
  n->next = NULL;
  n->data = addData;

  if(head != NULL){
    curr = head;
    while(curr->next != NULL){
      curr = curr-> next;
    }
    curr->next = n;
  }
  else{
    head = n;
  }
}

void List::insertRandom(int addData){
  nodePtr n = new node;
  n->next = NULL;
  n->data = addData;

  if(head != NULL){
    curr = head;
    while(curr->next != NULL){
      curr = curr-> next;
    }
    if(curr->data < addData){
    curr->next = n;
    }
    if(curr->data > addData){
      temp = curr;

    }
  }
  else{
    head = n;
  }
}

void List::deleteNode(int delData){
  nodePtr delPtr = NULL;
  temp = head;
  curr = head;
  while(curr != NULL && curr->data != delData){
    temp = curr;
    curr = curr->next;
  }
  if(curr == NULL){
    cout<< delData <<" was not in the list\n";
    delete delPtr;
  }
  else{
    delPtr = curr;
    curr = curr->next;
    temp->next = curr;
    delete delPtr;
    cout<< "The value "<<delData<< " was deleted\n";
  }
}

void List::printList() {
  curr = head;
  while(curr != NULL){
    cout<< curr->data << "\n";
    curr = curr->next;
  }
}

#endif //LIST_H
