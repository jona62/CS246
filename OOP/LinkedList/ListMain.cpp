#include "List.h"

int main(){
  List LinkedList;

  LinkedList.addNode(30);
  LinkedList.addNode(81);
  LinkedList.addNode(29);
  LinkedList.addNode(51);
  LinkedList.addNode(23);
  LinkedList.addNode(43);
  LinkedList.addNode(6);
  LinkedList.printList();

  LinkedList.deleteNode(30);
  LinkedList.deleteNode(81);
  LinkedList.deleteNode(29);
  LinkedList.deleteNode(51);
  LinkedList.deleteNode(23);
  LinkedList.deleteNode(43);
  LinkedList.deleteNode(6);
  LinkedList.printList();

  return 0;
}
