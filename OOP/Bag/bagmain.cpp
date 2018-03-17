#include "bag.h"

int main(){
  Bag bag1;

  cout<<"All zeros: \n";
  bag1.print();
  cout<<endl;

  cout<<"Random Numbers: \n";
  bag1.fillinArray();
  bag1.print();
  cout<<endl;

  cout<<"Modified: \n";
  bag1.remove(0);
  bag1.remove(0);
  bag1.remove(0);
  bag1.print();
  cout<<endl;

  cout<<"Deleted Array: \n";
  bag1.deleteArray();
  bag1.print();
  cout<<endl;

  return 0;
}
