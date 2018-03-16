#include "pointer.h"

typedef int* Intptr;

int main(){
  int size_arr;
  cout<<"Enter the size of the array: ";
  cin>> size_arr;

  Intptr array;

  array = new int [size_arr];

  fillArray(array, size_arr);

  sort(array, size_arr);

  printArray(array, size_arr);


  delete [] array;


  return 0;
}
