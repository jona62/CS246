#include "bag.h"

int main(){
  Bag bag1;

  cout<<"Random Numbers: \n";
  bag1.fillinArray();
  bag1.print();
  cout<<endl;

  cout<<"Modified Array: \n";
  bag1.remove(0);
  bag1.remove(0);
  bag1.remove(0);
  bag1.print();
  cout<<endl;

  cout<<"Deletes Array \n";
  bag1.deleteArray();

  return 0;
}
