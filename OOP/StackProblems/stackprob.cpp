#include "stackprob.h"

int main(){
  char expression[100];
  // expression = new char[100];
  cout<<"Enter a Postfix expression: ";
  cin.getline(expression, 100);

  cout<<"The Equivalent in Infix is: ";
  cout<<convert(expression);
  cout<<endl;
  return 0;
}
