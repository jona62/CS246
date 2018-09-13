#include "Dynamic_stacks.h"

int main(){
  Stack<string> s;
  Stack<string> st;
  s.push("1");
  s.push("2");
  s.push("3");
  s.push("4");
  s.push("5");
  s.push("6");

  s .reverse();
  /*
  s => 123456
  */
  st.push(s.pop());
  st.push(s.pop());
  st.push(s.pop());
  st.push(s.pop());
  st.push(s.pop());
  st.push(s.pop());
  /*
  st=> 654321
  */

  cout<<"First Stack"<<endl;
  s.print();  // s=> (empty)
  cout<<"Second Stack"<<endl;
  st.print(); //st=> 123456
  return 0;
}
