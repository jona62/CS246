#include "queue.h"

int main(){
  Queue<int> q;

  for(int i = 0; i < 50; i++)
    q.enqueue(i);
  
  while(!q.empty()) {
    cout << q.top() << " ";
    q.dequeue();
  }
  cout << endl;
  
  q.dequeue();
  return 0;  
}
