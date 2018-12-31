#ifndef LINKED_H
#define LINKED_H
#include <iostream>
using namespace std;


template<class T>
class LinkedList {
  private:
    struct Node {
      T data;
      Node *next;
    };

  Node *head;
  Node *tail;
  int count;

  void reverseRecur(Node *node) {
    if(node == NULL)
      return;
    else {
      reverseRecur(node->next);
      cout << node->data << " ";
    }
  }

  public:
    LinkedList();
    void push(T);
    T pop();
    void push_front(T);
    T pop_front();
    void insert(int, T);
    T value_at(int);
    T front();
    T back();
    void reverse();
    void remove_value(T);
    bool empty();
    int size();
    void print();
    void swap_head_tail();
    void reverse_print();

};

template<class T>
LinkedList<T>::LinkedList(){
  head = NULL;
  tail = NULL;
  count = 0;
}

template<class T>
void LinkedList<T>::push(T data) {
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

template<class T>
T LinkedList<T>::pop() {
  if(!empty()) {
    Node *curr = head;
    Node *prev = NULL;
    while(curr->next != NULL) {
      prev = curr;
      curr = curr->next;
    }
    int data = curr->data;
    delete curr;
    curr = NULL;
    prev->next = NULL;
    tail = prev;
    count--;
    return data;
  }
   return -1;
 }

template<class T>
bool LinkedList<T>::empty(){
  return head == NULL && count == 0;
}

template<class T>
int LinkedList<T>::size() {
  return count;
}

template<class T>
void LinkedList<T>::print() {
  if(!empty()) {
    Node *curr = head;
    while(curr != NULL){
      cout << curr->data << " ";
      curr = curr->next;
    }
    cout << endl;
  }
}

template<class T>
void LinkedList<T>::push_front(T data) {
  if(head == NULL) { 
    push(data);
    return;
  }
  Node *temp = new Node;
  temp->data = data;
  temp->next = NULL;
  temp->next = head;
  head = temp;
  count++;
}

template<class T>
T LinkedList<T>::pop_front() {
  if(!empty()) {
    T data = head->data;
    Node *delNode = head;
    head = head->next;
    delete delNode;
    delNode = NULL;
    count--;
    return data;
  }
  return T();
}

template<class T>
void LinkedList<T>::insert(int index, T data) {
  Node *curr = head;
  Node *prev = NULL;
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

// Zero based indexing
template<class T> 
T LinkedList<T>::value_at(int index) {
  if(head == NULL || index >= size()) 
    return -1;
  Node *curr = head;
  Node *prev = NULL;
  while(curr != NULL && index > 0){
    prev = curr;
    curr = curr->next;
    index--;
  }
  return curr->data;
}

template<class T>
T LinkedList<T>::front() {
  if(!empty()){
    return head->data;
  }
  return T();
}

template<class T>
T LinkedList<T>::back() {
  if(!empty()){
    Node *curr = head;
    while(curr->next != NULL){
      curr = curr->next;
    }
    return curr->data;
  }
  return -1;
}

template<class T>
void LinkedList<T>::reverse() {
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

template<class T>
void LinkedList<T>::remove_value(T data) {
  try {
    if(head == NULL) {
      throw "Empty List";
    }
  }catch (const char *err) {
    cerr << "Exception: " << err << '\n';
    return;
  }
  Node *curr = head;
  Node *prev = NULL;
  if(head->data == data) {
    pop_front();
    return;
  }
  while(curr->next != NULL) {
    prev = curr;
    curr = curr->next;
    if(curr->data == data) {
      Node *delNode = curr;
      prev->next = curr->next;
      delete delNode;
      delNode = NULL;
      count--;
      // If we remove the last element, make tail-pointer point to prev
      if(prev->next == NULL) {
        tail = prev;
      }
      break;
    }
  }
}

template<class T>
void LinkedList<T>::swap_head_tail() {
  if(head == NULL || head == tail)
    return;
  Node *curr = head;
  Node *prev = NULL;
  while(curr->next != NULL) {
    prev = curr;
    curr = curr->next;
  }
  Node *head_nxt = head->next;
  head->next = NULL;
  prev->next = head;
  curr->next = head_nxt;
  head = curr;
  tail = prev->next;
}

template<class T>
void LinkedList<T>::reverse_print() {
  if(!empty()) {
    reverseRecur(head);
    cout << endl;
  }
}


#endif //LINKED_H
