#include "bag.h"

Bag::Bag(){
  count = 0;
  for(int i=0; i<SIZE; i++){
    arr[i] = 0;
  }
}

void Bag::insert(int elem){
  if(!isFull()){
    arr[count] = elem;
    if(count < SIZE){
      count++;
    }
  }
}

void Bag::remove(int index){
  if(!isEmpty() ){
    count --;
    shift(index);
    arr[SIZE-1] = 0;
  }
}

void Bag::print(){
  int curren_size = sizeof(arr)/sizeof(arr[0]);
  for(int i=0; i<curren_size; i++){
    cout<<arr[i]<<" ";
  }
}

bool Bag::isFull(){
  return (count == SIZE);
}

bool Bag::isEmpty(){
  return (count == 0);
}

void Bag::swap(int &x, int &y){
  int temp;
  temp = x;
  x = y;
  y = temp;
}

void Bag::shift(int index){
  while(index < SIZE -1){
    swap(arr[index], arr[index + 1]);
    index++;
  }
}
