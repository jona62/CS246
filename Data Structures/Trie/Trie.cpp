#include "Trie.h"
using namespace std;

int main() {
  Trie tr;

  char word[] = "Hello";
  tr.insert(word);

  cout<< boolalpha;
  cout <<tr.find(word) << '\n';
  cout <<tr.find("Hell") << '\n';
  return 0;
}
