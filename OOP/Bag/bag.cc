#include "bag.h"
// #include "sets.h"

// Default Constructor that sets count to zero and Every element in the array to zero
Bag::Bag(){
  count = 0;
  for(int i=0; i<SIZE; i++){
    arr[i] = 0;
  }
}

//Checks if the Bag is full
bool Bag::isFull(){
  return (count == SIZE);
}

// Checks if the Bag is Empty
bool Bag::isEmpty(){
  return (count == 0);
}

// Swaps to variables
void Bag::swap(int &x, int &y){
  int temp;
  temp = x;
  x = y;
  y = temp;
}

//Inserts an element if Bag is not full and increments the value of count by one
void Bag::insert(int elem){
  if(!isFull()){
    arr[count] = elem;
      count++;
  }
}

//Removes an element at an index if Bag is not Empty and moves all the elements to the left to that index and decrements count by one
void Bag::remove(int index){
  if(!isEmpty()){
    shift(index);
    arr[SIZE-1] = 0;
    count--;
  }
}

//Returns the size of array
int Bag::size(){
  return count;
}

// Prints the array
void Bag::print(){
  for(int i=0; i<size(); i++){
    cout<<arr[i]<<" ";
  }
}


// Shifts the elements of an array to the left
void Bag::shift(int index){
  assert(index >= 0 && index < SIZE);
  while(index < SIZE-1){
    swap(arr[index], arr[index + 1]);
    index++;
  }
}


// Fills in the array with random numbers betweeen 1 and 9
void Bag::fillinArray(){
  srand(time(NULL));
  for(int i=0; i<SIZE; i++){
    int randomNum = rand() % 9 + 1;
    arr[i] = randomNum;
    count++;
  }
}

// Re-assigns all the elements to zero and count to 0
void Bag::deleteArray(){
  count = 0;
  for(int i=0; i<SIZE; i++){
    arr[i] = 0;
  }
}
