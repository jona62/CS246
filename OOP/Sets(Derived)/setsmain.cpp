#include "sets.h"

int main(){
  //Inherited Sets Class
  // Set A(20);
  // Set B(5);

  Set A;
  Set B;

  for(int i=1; i< 40; i+=1){
    if(i%2!=0)
      A.insert(i);
  }

  for(int i=1; i<40; i+=1){
    if(i%2==0)
      B.insert(i);
  }

  A.print();
  B.print();
  cout<<endl;
  Union(A, B);
  cout<<endl;

  A.deleteArray();
  B.deleteArray();

  for(int i=1; i< 40; i+=1){
    if(i%3==0)
      A.insert(i);
  }

  for(int i=1; i<40; i+=1){
    if(i%6==0)
      B.insert(i);
  }

  A.print();
  B.print();
  cout<<endl;
  Intersection(A, B);
  cout<<endl;

  return 0;
}
