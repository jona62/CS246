#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

class MaxHeap{
  private:
    int capacity;
    int size;
    int *heapArr;

    int parent(int i) {
      return (i - 1) / 2;
    }
    int left(int i) {
      return (2 * i) + 1;
    }
    int right(int i) {
      return (2 * i) + 2;
    }

  public:
    MaxHeap(int);
    int extractMax();
    int getMax() {
      return heapArr[0];
    }
    int heapSize() {
      return size;
    }
    void insert(int);
    void remove(int);
    void heapifyUp(int);
    void heapifyDown(int);
};

MaxHeap::MaxHeap(int cap) {
  capacity = cap;
  size = 0;
  heapArr = new int[cap];
}

void MaxHeap::heapifyUp(int i) {
  while(i != 0 && heapArr[parent(i)] < heapArr[i]) {
    swap(heapArr[parent(i)], heapArr[i]);
    i = parent(i);
  }
}

void MaxHeap::heapifyDown(int i) {
  int left_child = left(i);
  int right_child = right(i);
  int largest = i;
  if(left_child < size && heapArr[left_child] > heapArr[i]) {
    largest = left_child;
  }
  if(right_child < size && heapArr[right_child] > heapArr[largest]) {
    largest = right_child;
  }
  if(largest != i) {
    swap(heapArr[i], heapArr[largest]);
    heapifyDown(largest);
  }
}

void MaxHeap::insert(int element) {
    try {
        if(size >= capacity) {
            throw "Heap is full";
        }
        size++;
        int i = size - 1;
        heapArr[i] = element;
        heapifyUp(i); 
    } catch(const char *err) {
        cerr << "Exception: " << err << "\n";
  }
}

int MaxHeap::extractMax() {
  if(size <= 0) {
    return -1;
  }
  if(size == 1) {
    size--;
    return heapArr[0];
  }
  int temp = heapArr[0];
  heapArr[0] = heapArr[size - 1];
  size--;
  heapifyDown(0);
  return temp;
}


#endif // HEAP_H