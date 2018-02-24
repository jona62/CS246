#include <iostream>
#include <ctime>
#include <cstdlib>
#include <assert.h>
using namespace std;

void minimum(int arr[], int size){
    int minimum = arr[0];
    for(int i=1; i < size - 1; i++){
        if(arr[i] < minimum){
            minimum = arr[i];
        }
    }
    cout<<"Minimum = "<<minimum;
}

void swap(int &x, int &y){
    int temp;
    temp = x;
    x = y;
    y = temp;

}

void swapN(int arr[], int n, int size){

    int i=0;
    while( i < n-i-1){
        swap(arr[i], arr[n-i-1]);
        i++;
    }
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
}

void candyCrush();

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/ sizeof(arr[0]);
//    minimum(arr,size);
//    swapN(arr, 3, size);
    candyCrush();
    return 0;
}
void candyCrush(){
  int size = 25;
  char arr[size];
  char option[] = "ORY";
  srand(time(NULL));
  for(int i=0; i< size; i++){
      int random = rand() % 2 + 0;
      arr[i] = option[random];
  }
  cout<<"Initial Array:\n";
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<"\n\n";
  int i=0;
  int count = 1;
  int check = 0;
  while(i<size-2){
    assert(i+2<size);
    if( (arr[i] == arr[i+1]) && (arr[i] == arr[i+2]) ){
      if(count == 1)  cout<<"Initial Index where there is a repetition is "<<i<<endl;
      arr[i] = 'X';
      arr[i+1] = 'X';
      arr[i+2] = 'X';
      count--;
      check++;
    }
    i++;
  }

  cout<<"Final Array:\n";
  for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
  }
}
