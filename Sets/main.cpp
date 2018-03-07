#include "sets.h"

int main(){
  int A[15], B[20];

  writeToFile();
  SortAndEliminate();
  fillArray(A, 15);

  cout<<"Array A :\n";
  for(int i=0; i<15; i++){
      cout<<A[i]<<" ";
  }


  cout<<"\n\n";
  writeToFile();
  fillArray(B, 20);
  sort(B, 20);
  SortAndEliminate();

  cout<<"Array B :\n";
  for(int i=0; i<20; i++){
      cout<<B[i]<<" ";
  }

  cout<<"\n\n";
  cout<<"Union of Array A & Array B :\n";
  Union(A,15,B,20);

  cout<<"\n\n";
  cout<<"Intersection of Array A & Array B :\n";
  Intersection(A,15,B,20);
  cout<<"\n";
  return 0;
}
