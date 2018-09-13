#include "Arraylist.h"
#include <iostream>

ArrayList::ArrayList() {
  this->index = -1;
  this->collection = new int[16];
  this->capacity = 16;
}

ArrayList::~ArrayList(){
  delete [] collection;
}

int ArrayList::size() const{
  return this->index+1;
}

void ArrayList::push(int elem) {
  if(isFull()){
    resize();
  }
  this->index++;
  *(this->collection+this->index) = elem;
}

int ArrayList::at(int index) const{
  if(index <= this->index && index >= 0){
    return *(this->collection+index);
  }
  return -1;
}

void ArrayList::prepend(int elem){
  if(isFull()){
    resize();
  }
  reverse_shift(0);
  *collection = elem;
  this->index++;
}

void ArrayList::insert(int index, int elem){
  if(isFull()){
    resize();
  }
  if(index >= 0 && index <= this->index){
    reverse_shift(index);
    *(collection+index) = elem;
    this->index++;
  }
}

int ArrayList::pop() {
  if(size() <= this->capacity/4) {
    resize(2);
  }
  if(!isEmpty()){
    int temp = *(this->collection+this->index);
    this->index--;
    return temp;
  }
  return -1;
}

//TODO(Jonathan): Work on remove function
void ArrayList::remove(int elem) {
  if(!isEmpty()){
    for(int i=0; i<size(); i++){
      if(*(this->collection+i) == elem){
        shift(i);
        this->index--;
      }
    }
  }
}

void ArrayList::deleteElem(int index) {
  if(index < this->index && !isEmpty()){
    shift(index);
    this->index--;
  }
}

int ArrayList::find(int elem) {
  if(!isEmpty()){
    for(int i=0; i<size(); i++) {
      if(elem == *(this->collection+i)){
        return i;
      }
    }
  }
  return -1;
}

int ArrayList::getCapacity() const{
  return this->capacity;
}

bool ArrayList::isEmpty() const {
  return this->index == -1;
}

void ArrayList::print() const{
  for(int i=0; i<size(); i++) {
    std::cout<<*(this->collection+i) <<" ";
  }
  std::cout<<std::endl;
}

void ArrayList::addAll(ArrayList &list) {
  if(!list.isEmpty()){
    for(int i=0; i<list.size(); i++){
      if(isFull()){
        resize();
      }
      push(list.at(i));
    }
  }
}
