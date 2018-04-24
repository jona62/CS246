class Queue{
  private:
      struct node{
        int data;
        node* next;
      };
    node *front;
    node *back;
  public:
    Queue();
    void enqueue(int value);
    void dequeue();
    void print();
};
