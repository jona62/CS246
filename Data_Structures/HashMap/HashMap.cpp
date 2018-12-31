#include "HashMap.h"
#include <cassert>
using namespace std;

int main() {
    HashMap<int, char> hashMap; 
    hashMap.put(1, 'A');
    hashMap.put(2, 'O');
    hashMap.put(3, 'B');

    assert(hashMap.get(1) == 'A');
    hashMap.remove(1);
    assert(hashMap.find(1) == false);
    hashMap.put(1, 'C');
    assert(hashMap.get(1) == 'C');
    assert(hashMap.find(4) == false);
    
    cout << "Test Passed\n";
    return 0;
}