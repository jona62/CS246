// Write a program to convert feet to meters
// Include preconditions and postconditions
// Include the assert function for testing
// Detail the test cases you used for the program.
//

#include <iostream>
using namespace std;

float converter(float feets){
  float meters, inches;
  inches = feets * 12;
  meters = inches / 39.3701;
  return meters;
}

int main(){
  float feets;
  cout<<"Enter a height in feets :";
  cin>>feets;
  
  cout<<converter(feets);
  
  return 0;
}
