#ifndef TRIE_H
#define TRIE_H
#include <iostream>

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

    int getCharIndex(char key) {
      return (isupper(key)) ? key - 'A' : key - 'a';
    }

    TrieNode *getTrieNode(int index, TrieNode *_this) {
      return _this->children[index];
    }

    TrieNode *getRoot() {
      return this->root;
    }

    private:
      TrieNode *root;
      // Instantiates a new TrieNode and sets its members to NULL
      TrieNode *createTrieNode() {
        TrieNode *pNode = new TrieNode;
        pNode->isEndOfWord = false;
        for (int i=0; i<ALPHA_SIZE; i++)
          pNode->children[i] = NULL;
        return pNode;
      }
};

Trie::Trie(){
  root = createTrieNode();
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just
// marks leaf node
void Trie::insert(std::string key) {
  TrieNode *pCrawl = root;
  for(int i=0; i<key.length(); i++) {
    int index = getCharIndex(key[i]);
    if(getTrieNode(index, pCrawl) == NULL)
      pCrawl->children[index] = createTrieNode();

    pCrawl = pCrawl->children[index];
  }
  // Mark last node as leaf
  pCrawl->isEndOfWord = true;
}

// Returns true if key presents in trie, else
// false
bool Trie::find(std::string key) {
  TrieNode *pCrawl = root;
  for(int i=0; i<key.length(); i++) {
    int index = getCharIndex(key[i]);
    if(getTrieNode(index, pCrawl) == NULL)
      return false;

    pCrawl = pCrawl->children[index];
  }
  return (pCrawl != NULL && pCrawl->isEndOfWord);
}

bool Trie::findPartial(std::string key) {
  TrieNode *pCrawl = root;
  for(int i=0; i<key.length(); i++) {
    int index = getCharIndex(key[i]);
    if(getTrieNode(index, pCrawl) == NULL)
      return false;

    pCrawl = pCrawl->children[index];
  }
  return (pCrawl != NULL);
}

#endif //TRIE_H
