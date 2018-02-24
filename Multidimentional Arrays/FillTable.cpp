#include <iostream>
#include <assert.h>
using namespace std;

int main(){
  int table[3][4];
  int x =1;

  for(int row = 0; row<3; row++){
    for(int col = 0; col<4; col++){
      table[row][col] = x;
      x++;
    }
  }

int count = 0;
  for(int row = 0; row<3; row++){
    for(int col = 0; col<4; col++){
      cout<<"|"<<table[row][col]<<"| ";
      count++;
      if(count % 4 == 0){
        cout<<"\n------------------\n";
      }
    }
  }
  
  return 0;
}
