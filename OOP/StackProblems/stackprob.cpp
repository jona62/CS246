#include "Dynamic_stacks.h"
#include "stackprob.h"

int main(){
  string expression;
  // expression = new char[100];
  cout<<"Enter a Postfix expression: ";
  getline(cin, expression);

  cout<<"The Equivalent in Infix is: ";
  convert(expression);
  cout<<endl;
  return 0;
}
