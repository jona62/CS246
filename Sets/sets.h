#ifndef SETS_H
#define SETS_H
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;


void writeToFile(){
  ofstream ofile;
  ofile.open("RandomNums.txt");
  if(ofile.is_open()){
    int randNum;
    srand(time(NULL));
    for(int i=0; i<50; i++){
      randNum = rand() % 100 + 1;
      ofile<<randNum<<" ";
    }
  }
  ofile.close();
}


void swap(int &a, int &b){
  int temp;
    temp = a;
    a = b;
    b = temp;
}

void sort(int arr[], int size){
  for(int i=0; i<size; i++)
    for(int j=0; j<size-i-1; j++){
    if(arr[j] > arr[j+1])
     swap(arr[j], arr[j+1]);
  }
}

int rmDuplicates(int arr[], int size){
  int temp[size], i=0;
  for(int j=0; j<size-1; j++){
    if(arr[j] != arr[j+1]){
      temp[i++] = arr[j];
    }
  }

 temp[i++] = arr[size-1];

 for(int k=0; k<i; k++){
   arr[k] = temp[k];
 }
 return i;
}

void SortAndEliminate(){
  ifstream ifile;
  ifile.open("RandomNums.txt");
  int arr[100], iter=0;
  if(ifile.is_open()){
    while(ifile>>arr[iter]){
      iter++;
    }

  }
  ifile.close();

  sort(arr, iter);
  int newSize = rmDuplicates(arr, iter);

  ofstream ofile;
  ofile.open("RandomNums.txt");
  if(ofile.is_open()){
    int i=0;
    while(i<newSize){
      ofile<<arr[i++]<<" ";
    }
  }
  ofile.close();
}

void fillArray(int arr[], int size){
  ifstream ifile;
  ifile.open("RandomNums.txt");
  int i=0;
  if(ifile.is_open()){
    while(i<size){
      ifile>>arr[i++];
    }
  }

  ifile.close();
}

void Union(int arr1[], int size1, int arr2[], int size2){
  int size = size1 + size2;
  int temp[size];

  for(int i=0; i<size1; i++){
    temp[i] = arr1[i];
  }

  for(int i=0; i<size2; i++){
    temp[size1++] = arr2[i];
  }

  sort(temp, size);
  int newSize = rmDuplicates(temp, size);

  for(int i=0; i<newSize; i++){
    cout<<temp[i]<<" ";
  }

}


void Intersection(int arr1[], int size1, int arr2[], int size2){
  int size = (size1<size2) ? size1 : size2;
  int temp[size], k=0;
  for(int i=0; i<size1; i++){
    for(int j=0; j<size2; j++){
      if(arr1[i] == arr2[j]){
        temp[k++] = arr1[i];
      }
    }
  }
   for(int i=0; i<k; i++){
    cout<<temp[i]<<" ";
  }
}

#endif //SETS_H
