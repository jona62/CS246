#ifndef STACKPROB_H
#define STACKPROB_H
#include <string>

bool isOperand(char s){
  return (s>'a' && s<'z' || s>'A' && s<'Z');
}

void convert(string exp){
  Stack <string> s;
  for(int i=0; i!='\0'; i++){
    if(isOperand(exp[i])){
      s.push(exp[i]);
    }
    else{
      string next = s.pop();
      string prev = s.pop();
      s.push("(" + prev + exp[i] + next + ")");
    }
  }
  s.print();
  s.pop();
}

#endif //STACKPROB_H
