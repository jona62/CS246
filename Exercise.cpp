// Write a program to convert feet to meters
// Include preconditions and postconditions
// Include the assert function for testing
// Detail the test cases you used for the program.

#include <iostream>
#include <iomanip>
#include <assert.h>
using namespace std;

float converter(float feets){
  float meters, inches;
  inches = feets * 12;
  meters = inches / 39.3701;
  return meters;
}

float converter1(float feets){
  float meters = feets / 3.28084;
  return meters;
}

int main(){
  float feets;
  cout<<"Enter a height in feets :";
  cin>>feets;
  
  assert(converter1(feets) == converter(feets));
  //Printing converted feets in two decimal places
  cout<<fixed<<setprecision(2)<<converter(feets);
  
  return 0;
}
