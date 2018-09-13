#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cc"
using namespace std;

int main() {
  LinkedList list;
  list.push(5);
  list.push(4);
  list.push(3);
  list.push(2);
  list.push(1);

  list.push_front(6);
  list.reverse();
  // list.print();
  cout<<list.value_at(3);
  return 0;
}
