#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class List{
  private:
    typedef struct node{
      int data;
      node *next;
    } *nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr tail;
    nodePtr temp;

  public:
    List();
    void addNode(int addData);
    void deleteNode(int delData);
    void printList();
    void insertRandom(int);
};

List::List():head(NULL),curr(NULL),temp(NULL), tail(NULL){
  /*
  head = NULL;
  curr = NULL;
  temp = NULL;
  */
}

void List::addNode(int addData){
  nodePtr n = new node;
  n->data=addData;
  n->next=NULL;
  if(head==NULL){
    head=n;
    tail=n;
    temp=NULL;
   }
   else{
    tail->next=n;
    tail=n;
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
