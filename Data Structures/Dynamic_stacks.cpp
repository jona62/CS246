#include "Dynamic_stacks.h"

int main(){
  Stack<int> s;
  Stack<int> st;
  s.push(1);
  s.push(2);
  s.push(3);
  s.push(4);
  s.push(5);
  s.push(6);
  st.push(s.pop());
  st.push(s.pop());
  st.push(s.pop());
  st.push(s.pop());
  st.push(s.pop());
  st.push(s.pop());
  cout<<"First Stack"<<endl;
  s.print();
  cout<<"Second Stack"<<endl;
  st.print();
  return 0;
}
