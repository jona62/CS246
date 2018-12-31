#include <iostream>
using namespace std;

template<class T>
class BinaryTree {
    struct Node{
        T data;
        Node* left;
        Node* right;
    };

    Node* root;

      int height(Node *node) {
        return (node == NULL) ? 0 
            : 1 + max(height(node->left), height(node->right));
    }
    Node* makeEmpty(Node* node) {
        if(node == NULL)
            return NULL;
        {
            makeEmpty(node->left);
            makeEmpty(node->right);
            delete node;
        }
        return NULL;
    }

    Node* insert(Node* node, T x) {
        if(node == NULL) {
            node = new Node;
            node->data = x;
            node->left = node->right = NULL;
        }
        else if(x < node->data)
            node->left = insert(node->left, x);
        else if(x > node->data)
            node->right = insert(node->right, x);
        return node;
    }

    Node* findMin(Node* node) {
        if(node == NULL)
            return NULL;
        else if(node->left == NULL)
            return node;
        else
            return findMin(node->left);
    }

    Node* findMax(Node* node) {
        if(node == NULL)
            return NULL;
        else if(node->right == NULL)
            return node;
        else
            return findMax(node->right);
    }

    Node* remove(Node* node, T data) {
        // Base case
        if(node == NULL)
            return node;
        if(data < node->data)
            node->left = remove(node->left, data);
        else if(data > node->data)
            node->right = remove(node->right, data);
        else {
            // At this point we know that we've found the node we're looking for
            if(node->left == NULL && node->right == NULL) {
                delete node;
                node = NULL;
            }

            else if(node->left == NULL) {
                Node *deletePtr = node;
                node = node->right;
                delete deletePtr;
            }
            else if(node->right == NULL) {
                Node *deletePtr = node;
                node = node->left;
                delete deletePtr;
            }
            // At this point we know that node has both of it's children
            else {
                Node *successor = findMin(node->right);
                node->data = successor->data;
                node->right = remove(node->right, successor->data);
            }
        }
        return node;
    }

    void inorder(Node* node) {
        if(node == NULL)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    Node* find(Node* node, T x) {
        if(node == NULL)
            return NULL;
        else if(x < node->data)
            return find(node->left, x);
        else if(x > node->data)
            return find(node->right, x);
        else
            return node;
    }

public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        root = makeEmpty(root);
    }
    void insert(T x) {
        root = insert(root, x);
    }
    void remove(T x) {
        root = remove(root, x); 
    }
    int depth() { 
        return (root == NULL) ? 0 
            : height(root); 
    }
    void display() {
        inorder(root);
        cout << endl;
    }
    void search(T x) {
        root = find(root, x);
    }
    T maximum() {
        return (root == NULL) ? T() 
            : findMax(root)->data; 
    }
    T minimum() {
      return (root == NULL) ? T() 
            : findMin(root)->data; 
    }
};
