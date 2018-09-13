#ifndef ARRAYLIST_H
#define ARRAYLIST_H
#include <cstring>

class ArrayList {
  private:
    int *collection;
    int index;
    int capacity;

    void resize() {
      int newSize = this->capacity * 2;
      int *newArr = new int[newSize];
      memcpy(newArr, collection, newSize * sizeof(int));
      delete [] collection;
      this->collection = newArr;
      this->capacity = newSize;
    }

     void resize(int half) {
      int newSize = this->capacity / half;
      int *newArr = new int[newSize];
      memcpy(newArr, collection, newSize * sizeof(int));
      delete [] collection;
      this->collection = newArr;
      this->capacity = newSize;
    }

    void swap(int &a, int &b) {
      int temp = a;
      b = a;
      a = temp;
    }

    void shift(int index){
      for(int i=index; i<size()-1; i++) {
        *(this->collection+i) = *(this->collection+i+1);
      }
    }

    void reverse_shift(int index) {
     if(isFull()){
        resize();
      }
      for(int i=this->index+1; i>index; i--) {
        *(this->collection+i) = *(this->collection+i-1);
      }
    }

    bool isFull(){
      return capacity == index;
    }

  public:
    ArrayList();
    ~ArrayList();
    int size() const;
    void push(int);
    int pop();
    int at(int) const;
    void prepend(int);
    void insert(int, int);
    void remove(int);
    void deleteElem(int);
    int find(int);
    int getCapacity() const;
    bool isEmpty() const;
    void print() const;
    void addAll(ArrayList&);
};




#endif //ARRAYLIST_H 
