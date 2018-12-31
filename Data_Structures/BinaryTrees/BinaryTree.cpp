#include "BinaryTree.h"
#include "LongInt.h"

// To use templates with custom data types, 
// You'd have to define your own comparison 
// Operators ('<' and '>') as shown in LongInt.h 
int main(){
    BinaryTree<LongInt> tree;

    // Not the best way to insert elements into a binary tree
    // Makes insertion, removal and searching the tree O(n)
    // Because every element goes to it's parent's right
    for(int i=1; i<=40; i++)
      tree.insert(LongInt(i));

    tree.display();
    
    for(int i=21; i <= 40; i++)
      tree.remove(LongInt(i));
  
    cout << endl;

    cout << "Minimum: " << tree.minimum() << "\n";
    cout << "Maximum: " << tree.maximum() << "\n";
    
    return 0;
}
