#ifndef STACKPROB_H
#define STACKPROB_H
#include <string>

bool isOperand(char s){
  return (s>'a' && s<'z' || s>'A' && s<'Z');
}

string convert(string exp){
  Stack <string> s;
  for(int i=0; exp[i]!='\0'; i++){
    if(isOperand(exp[i])){
      string op1(1, exp[i]);
      s.push(op1);
    }
    else{
      string next = s.pop();
      string prev = s.pop();
      string top =  prev + exp[i] + next ;
      s.push(top);
    }
  }
<<<<<<< HEAD:OOP/StackProblems/stackprob.h
    return s.pop();
=======
  return s.pop();
>>>>>>> 06b102439c93d6ce8c62abd2791d17b52d9df4db:StackProblems/stackprob.h
}

#endif //STACKPROB_H
