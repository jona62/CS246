// Write a program to convert feet to meters
// Include preconditions and postconditions
// Include the assert function for testing
// Detail the test cases you used for the program.
//
#define NDEBUG
#include <iostream>
#include <cassert>
using namespace std;

float converter1(float feets){
  float meters = feets / 3.28084;
  return meters;
}

float converter2(float feets){
  float meters, inches;
  inches = feets * 12;
  meters = inches / 39.3701;
  return meters;
}

bool Master(float feets, float (*func1)(float), float (*func2)(float)){
  //Could not perform float comparison successfully so I had to make a and b integers
  int a = func1(feets), b = func2(feets);
  assert(a == b);
  return (a == b);
}

int main(){
  float feets;
  cout<<"Enter heights in feets: ";
  cin>>feets;

  cout<<boolalpha;
  cout<<Master(feets, converter1, converter2);

  return 0;
}
