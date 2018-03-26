#include "bag.h"

int main(){
  // Bag Class
  Bag bag1;

  cout<<"Random Numbers: \n";
  //Populates the array with random Numbers
  bag1.fillinArray();
  //Prints out the elements in the array
  bag1.print();
  cout<<endl;

  cout<<"Modified Array: \n";
  //Removes elements at an index
  bag1.remove(0);
  bag1.remove(0);
  bag1.remove(0);

  //Appends to the end of the array
  //Only if array is not full
  bag1.insert(12);
  bag1.insert(12);
  bag1.insert(12);
  bag1.print();
  cout<<endl;

  cout<<"Deletes Array \n";
  //Deletes all the elements in the array and resets count to 0
  bag1.deleteArray();
  cout<<endl;

  return 0;
}
