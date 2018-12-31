#include "Heap.h"

int main() {
  MaxHeap max(10);
  max.insert(10);
  max.insert(27);
  max.insert(46);
  max.insert(1);
  max.insert(4);
  max.insert(16);

  cout << "Max: " << max.getMax() << endl; 
  
  max.extractMax();

  cout << "After extracting Max\n";
  cout << "Max: " << max.getMax() << endl; 
}
