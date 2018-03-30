#include "List.h"

int main(){
  List list;

  list.addNode(30);
  list.addNode(81);
  list.addNode(29);
  list.addNode(51);
  list.addNode(23);
  list.addNode(43);
  list.addNode(6);

  list.printList();

  list.deleteNode(30);
  list.deleteNode(81);
  list.deleteNode(29);
  list.deleteNode(51);
  list.deleteNode(23);
  list.deleteNode(43);
  list.deleteNode(6);
  list.printList();

  return 0;
}
