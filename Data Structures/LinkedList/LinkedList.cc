#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(){
  head = NULL;
  tail = NULL;
  count = 0;
}

void LinkedList::push(int data) {
  Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;

  if(head == NULL) {
    head = temp;
    tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
  count++;
}

int LinkedList::pop() {
  if(!isEmpty()){
    Node* prev = new Node;
    Node* curr = head;
    while(curr->next != NULL) {
      prev = curr;
      curr = curr->next;
    }
      int data = curr->data;
      delete curr;
      prev->next = NULL;
      count--;
      return data;
   }
   return -1;
  }

bool LinkedList::isEmpty(){
  return head == NULL && count == 0;
}

int LinkedList::size() {
  return count;
}

void LinkedList::print() {
  Node* curr = head;
  while(curr != NULL){
    std::cout<<curr->data<<" ";
    curr = curr->next;
  }
}

void LinkedList::push_front(int data) {
  Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;
  if(head == NULL)
    push(data);
  else {
    temp->next = head;
    head = temp;
  }
  count++;
}

int LinkedList::pop_front() {
  if(!isEmpty()) {
    int data = head->data;
    Node *delNode = head;
    head = head->next;
    delete delNode;
    count--;
    return data;
  }
  return -1;
}

void LinkedList::insert(int index, int data) {
  Node *curr = head;
  Node *prev = new Node;
  while(curr->next != NULL && index >= 0){
    prev = curr;
    curr = curr->next;
    index--;
  }
  if(curr == NULL) return;
  Node *temp = new Node;
  temp->data = data;
  prev->next = temp;
  temp->next = curr;
  count++;
}

int LinkedList::value_at(int index) {
  Node *curr = head;
  Node *prev = new Node;
  while(curr != NULL && index > 0){
    prev = curr;
    curr = curr->next;
    index--;
  }
  if(curr == NULL || index >= size()) return -1;
  return curr->data;
}

int LinkedList::front() {
  if(!isEmpty()){
    return head->data;
  }
  return -1;
}

int LinkedList::back() {
  if(!isEmpty()){
    Node* curr = head;
    while(curr->next != NULL){
      curr = curr->next;
    }
    return curr->data;
  }
  return -1;
}

void LinkedList::reverse() {
  Node *current = head;
  Node *prev = NULL;
  Node *next = NULL;
  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

void LinkedList::remove_value(int data) {
  Node *curr = head;
  Node *prev = new Node;
  if(head->data == data){
    Node *delNode = head;
    head = head->next;
    delete delNode;
    count--;
    return;
  }
  while(curr->next != NULL) {
    prev = curr;
    curr = curr->next;
    if(curr->data == data) {
      Node *delNode = curr;
      prev->next = curr->next;
      delete delNode;
      count--;
      return;
    }
  }
}
