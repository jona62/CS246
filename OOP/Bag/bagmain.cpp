#include "bag.h"

int main(){
  Bag stack;

  cout<<"All zeros: \n";
  stack.print();
  cout<<endl;

  cout<<"Random Numbers: \n";
  stack.fillinArray();

  stack.print();
  cout<<endl;

  cout<<"Modified: \n";
  stack.remove(19);
  stack.remove(18);
  stack.remove(17);

  stack.print();
  stack.deleteArray();
  cout<<endl;
  stack.print();


  return 0;
}
