#include "bag.h"
// #include "sets.h"

// Default Constructor that sets count to zero and Every element in the array to zero
Bag::Bag():SIZE(20){
  count = 0;
  arr = new int [SIZE];
  for(int i=0; i<SIZE; i++){
    arr[i] = 0;
  }
}

Bag::Bag(int size):SIZE(size){
  count = 0;
  arr = new int [SIZE];
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

void Bag::sort(){
  for(int i=0; i<SIZE; i++)
    for(int j=0; j<SIZE-i-1; j++){
    if(arr[j] > arr[j+1])
     swap(arr[j], arr[j+1]);
  }
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
  cout<<"{";
  for(int i=0; i<size(); i++){
    cout<<arr[i];
    if(i!=size()-1)cout<<", ";
    if(i==size()-1)cout<<"}";
  }
  cout<<endl;
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
  int randomNum;
  for(int i=0; i<SIZE; i++){
    randomNum = rand() % 30 + 10;
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
