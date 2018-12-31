#include "LinkedList.h"

int main() {
  LinkedList<int> list;

  for(int i = 50; i >= 0; i--)
    list.push_front(i);

  list.print();

  for(int i = 51; i <= 75; i++)
    list.push(i);

  list.print();
  
  for(int i = 0; i < 25; i++) 
    list.pop();

  list.print();

  return 0;
}
