#include "BST.h"

int main(){
    BST t;

    for(int i=1; i<100; i+=3){
      t.insert(i);
    }

    // t.display();
    t.minimum();
    t.maximum();
}
