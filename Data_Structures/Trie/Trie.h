#ifndef TRIE_H
#define TRIE_H
#include <iostream>
#include <cstring> // memset()

// Adjust the size for other Alphabets
const int ALPHA_SIZE = 26;

class Trie {
  public:
    struct TrieNode {
      TrieNode *children[ALPHA_SIZE];
      bool isEndOfWord;
    };
    // Default constructor initializes @param root
    Trie();
    void insert(std::string);
    bool find(std::string);
    bool findPartial(std::string);

    private:
      TrieNode *root;
      // Instantiates a new TrieNode and sets its members to NULL
      TrieNode *createTrieNode() {
        TrieNode *pNode = new TrieNode;
        pNode->isEndOfWord = false;
        memset(pNode->children, 0, sizeof(pNode->children));
        return pNode;
      }

      int getCharIndex(char key) {
        return (isupper(key)) ? key - 'A' : key - 'a';
      }

      TrieNode *getTrieNode(int index, TrieNode *_this) {
        return _this->children[index];
      }
};

Trie::Trie(){
  root = createTrieNode();
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// Marks leaf node as end of word
void Trie::insert(std::string key) {
  TrieNode *temp = root;
  for(int i=0; i<key.length(); i++) {
    int index = getCharIndex(key[i]);
    if(getTrieNode(index, temp) == NULL)
      temp->children[index] = createTrieNode();
    temp = temp->children[index];
  }
  // Mark last node as leaf
  temp->isEndOfWord = true;
}

// Returns true if key presents in trie,
// Else false
bool Trie::find(std::string key) {
  TrieNode *temp = root;
  for(int i=0; i<key.length(); i++) {
    int index = getCharIndex(key[i]);
    if(getTrieNode(index, temp) == NULL)
      return false;

    temp = temp->children[index];
  }
  return (temp != NULL && temp->isEndOfWord);
}

bool Trie::findPartial(std::string key) {
  TrieNode *temp = root;
  for(int i=0; i<key.length(); i++) {
    int index = getCharIndex(key[i]);
    if(getTrieNode(index, temp) == NULL)
      return false;

    temp = temp->children[index];
  }
  return (temp != NULL);
}

#endif //TRIE_H
