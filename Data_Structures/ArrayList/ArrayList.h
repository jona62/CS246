#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <cstring>
#include <iostream>
using namespace std;

template <class T>
class ArrayList {
  private:
    T *collection;
    int index;
    int capacity;

    // Resizes collection by power of 2 
    // Increases it when collection is full and
    // Decreases it when collection's size is less than one fourth it's capacity
    void resize(double x) {
      int newSize = capacity / x;
      T *newArr = new T[newSize];
      // Copies everything from collection into newArr
      memcpy(newArr, collection, newSize * sizeof(T));
      delete [] collection;
      collection = newArr;
      capacity = newSize;
    }

    // Shifts the contents of the array towards the right
    void shift(int index) {
      for(int i = index; i < size() - 1; i++) {
        *(collection + i) = *(collection + i + 1);
      }
    }

    // Shifts the contents of the array towards the left
    void reverse_shift(int idx) {
      for(int i = index + 1; i > idx; i--) {
        *(collection + i) = *(collection + i - 1);
      }
    }

    bool isFull(){
      return capacity == index;
    }

  public:
    ArrayList();
    ArrayList(int);
    ~ArrayList();
    int size() const;
    void push(T);
    T pop();
    int at(int) const;
    void prepend(T);
    void insert(int, T);
    void remove(T);
    void deleteElem(int);
    bool find(T);
    int getCapacity() const;
    bool isEmpty() const;
    void print() const;
    void addAll(const ArrayList<T>&);
};

template <class T>
ArrayList<T>::ArrayList() {
  index = -1;
  capacity = 16;
  collection = new T[16];
}


template <class T>
ArrayList<T>::ArrayList(int x) {
  index = -1;
  capacity = x;
  collection = new T[x];
}


template <class T>
ArrayList<T>::~ArrayList() {
  delete [] collection;
}


template <class T>
int ArrayList<T>::size() const{
  return index + 1;
}

template <class T>
void ArrayList<T>::push(T elem) {
  if(isFull()) {
    resize(0.5);
  }
  index++;
  *(collection + index) = elem;
}


template <class T>
int ArrayList<T>::at(int index) const{
  try {
    if(index <= index && index >= 0)
      return *(collection + index);
   else
      throw "Index out of bounds";
  } catch (const char *err) {
    cerr << "Exception: " << err << '\n';
  }
  return -1;
}

template <class T>
void ArrayList<T>::prepend(T elem) {
  if(isFull()){
    resize(0.5);
  }
  reverse_shift(0);
  *collection = elem;
  index++;
}

template <class T>
void ArrayList<T>::insert(int idx, T elem) {
  if(isFull()){
    resize(0.5);
  }
  try {
    if(idx >= 0 && idx - 1 <= index) {
      reverse_shift(idx);
      *(collection + idx) = elem;
      index++;
    }
    else
        throw "Index out of bounds";
    } catch (const char *err) {
      cerr << "Exception: " << err << '\n';
    }
}

template <class T>
T ArrayList<T>::pop() {
  if(size() <= capacity/4) {
    resize(2);
  }
  if(!isEmpty()){
    int temp = *(collection + index);
    index--;
    return temp;
  }
  return T();
}


template <class T>// Removes the first occurrence of an element 
void ArrayList<T>::remove(T elem) {
  if(size() <= this->capacity/4) {
    resize(2);
  }
  try {
    if(!isEmpty()) {
      bool found = false; 
      for(int i = 0; i < size(); i++) {
        if(*(collection + i) == elem) {
          shift(i); index--;
          found = true;
          break;
        }
      }
      if(!found)
        throw "Element not in array";
    } else
        throw "ArrayList is empty";
  } catch(const char *err) {
      cerr << "Exception: " << err << '\n';
  }
}

template <class T>
void ArrayList<T>::deleteElem(int idx) {
  if(size() <= this->capacity/4) {
    resize(2);
  }
  try {
    if(!isEmpty()) {
      if(idx >= 0 && idx < index) {
        shift(idx); index--;
      }
      else {
        throw "Index out of bounds";
      }
    } else {
      throw "ArrayList is empty";
    }
  } catch(const char *err) {
      cerr << "Exception: " << err << '\n';
  }
}

template <class T>
bool ArrayList<T>::find(T elem) {
  if(!isEmpty()){
    for(int i = 0; i < size(); i++) {
      if(elem == *(collection + i)){
        return true;
      }
    }
  }
  return false;
}

template <class T>
int ArrayList<T>::getCapacity() const{
  return capacity;
}

template <class T>
bool ArrayList<T>::isEmpty() const {
  return index == -1;
}

template <class T>
void ArrayList<T>::print() const{
  for(int i = 0; i < size(); i++) {
    cout << *(collection + i) << " ";
  }
  cout << endl;
}

template <class T>
void ArrayList<T>::addAll(const ArrayList &list) {
  if(!list.isEmpty()){
    for(int i = 0; i < list.size(); i++){
      if(isFull()) {
        resize(0.5);
      }
      push(list.at(i));
    }
  }
}

#endif //ARRAYLIST_H 
