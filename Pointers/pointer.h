#include <iostream>
#include <cstdlib>
#include <ctime>

#ifndef POINTER_H
#define POINTER_H
using namespace std;

void swap(int &a, int &b){
  int temp;
    temp = a;
    a = b;
    b = temp;
}

void sort(int *arr, int size){
  for(int i=0; i<size; i++)
    for(int j=0; j<size-i-1; j++){
    if(arr[j] > arr[j+1])
     swap(arr[j], arr[j+1]);
  }
}


void fillArray(int *arr, int size){
  int randNum;
  srand(time(NULL));
  for(int i=0; i<size; i++){
    randNum = rand() % 90 + 10;
      arr[i] = randNum;
  }
}

void printArray(int *arr, int size){
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
}

#endif //POINTER_H
