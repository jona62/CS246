#include <iostream>
using namespace std;

class List{
  private:
    Struct node{
      int data;
      node *next;
    };

    typedef Struct node* nodePtr;

    nodePtr head;
    nodePtr curr;
    nodePtr temp;

  public:
    List();
    void addNode(int addData);
    void deleteNode(int delData);
    void printList();
};

List::List():head(NULL),curr(NULL),temp(NULL){}

void List::addNode(int addData){
  nodePtr n = new node;
  n->next = NULL;
  n->data = addData

  if(head != NULL){
    curr = head;
    while(curr-> != NULL){
      curr = curr-> next;
    }
    curr->next = n;
  }
  else{
    head = n;
  }
}

void List::deleteNode(int delData){
  nodePtr delPtr = NULL;
}
