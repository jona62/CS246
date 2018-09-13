#include <iostream>
#include "Arraylist.h"
#include "Arraylist.cc"
using namespace std;
// TODO Rmember to modify Arraylist.cc #66

int main() {
  ArrayList arrayList;

  for(int i=1; i<20; i++) {
    arrayList.push(i);
  }

  ArrayList arrayList2;
  for(int i=20; i<31; i++) {
    arrayList2.push(i);
  }

  arrayList.print();
  arrayList2.print();
  arrayList.addAll(arrayList2);
  arrayList.print();
  return 0;
}
