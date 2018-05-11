#include <iostream>
#include <string>
using namespace std;

unsigned int Hash(const string& key){
  unsigned int hash = 0;
  for(int i=0; i != key.size(); i++){
    hash += key[i];
  }
  return hash;
}

int main(){
  string sentence[] = {"Nile","Benue","Niger","Orange","Zambezin","Lippopo","Mississippi"};
  int size = sizeof(sentence)/sizeof(string);
  for(int i=0; i<size; i++)
    cout<<sentence[i]<<"'s Hash Value is "<<Hash(sentence[i])<<"\n";
  return 0;
}
