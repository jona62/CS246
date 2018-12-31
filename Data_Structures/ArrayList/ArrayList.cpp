#include "ArrayList.h"

int main() {
  ArrayList<int> arrayList;

  for(int i=1; i<20; i++) {
    arrayList.push(i);
  }

  ArrayList<int> arrayList2;
  for(int i = 20; i < 31; i++) {
    arrayList2.push(i);
  }

  cout << "ArrayList 1 : ";
  cout << "ArrayList Capacity: " << arrayList.getCapacity() << endl;

  arrayList.print();
  cout << "ArrayList 2 : ";
  arrayList2.print();
  arrayList.addAll(arrayList2);
  cout << "ArrayList 1 + ArrayList 2    : ";
  arrayList.print();

  for(int i = 30; i < 50; i++)
    arrayList.insert(i, i+1); 

  arrayList.prepend(0);
  arrayList.prepend(-1);

  cout << "ArrayList 1 after insertions : ";
  arrayList.print();


  for(int i=0; i < 30; i++)
    arrayList.deleteElem(0);

  cout << "ArrayList Capacity: " << arrayList.getCapacity() << endl;

  cout << "ArrayList after deleting elements between index 0 and 30:\n";
  arrayList.print();
  

  for(int i = 40; i <= 50; i++)
    arrayList.remove(i);

  cout << "ArrayList Capacity: " << arrayList.getCapacity() << endl;

  cout << "ArrayList after removing elements from 40 to 50:\n";
  arrayList.print();
  
  cout << "ArrayList Capacity: " << arrayList.getCapacity() << endl;


  cout << "Accessing invalid indices: \n";
  arrayList.insert(-1, 10);
  arrayList.at(-1);

  cout << "Trying to remove non-existent items:\n";
  arrayList.remove(20);

  return 0;
}
