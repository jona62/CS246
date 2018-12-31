#include "Stack.h"
#include <cstring>

int main() {
  Stack<int> st;

  for(int i = 1; i <= 10; i++) 
    st.push(i);

  while(!st.empty()) {
    cout << st.pop() << "\n";
  }

  cout << endl; 

  Stack<char> stack;
  char str1[] = "madam";

  for(int i = 0; i < strlen(str1); i++)
      stack.push(str1[i]);

  char str2[strlen(str1)]; int i = 0;
  while(!stack.empty()) 
    str2[i++] = stack.pop();
  str2[i] = '\0';

  if( !strcmp(str1, str2)) 
    cout << str1 << " is a palindrome\n";
  return 0;
}