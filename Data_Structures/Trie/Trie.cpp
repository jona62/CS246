#include "Trie.h"
using namespace std;

int main() {
  Trie tr;

  string word = "Hello";
  tr.insert(word);

  cout << boolalpha;
  cout << tr.find(word) << '\n'; // Prints true
  cout << tr.find("Hell") << '\n'; // Prints false

  cout << tr.findPartial("H") << '\n'; // Prints true
  return 0;
}
