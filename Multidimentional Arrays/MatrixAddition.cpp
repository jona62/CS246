#include <iostream>
#include <assert.h>
using namespace std;

int main(){
  int matrix[2][3] = {{2,15,7}, {3,4,9}};
  int matrix1[2][3] ={{1,5,12},{7,8,2}};

  int newArr[2][3];
  for(int row = 0; row<2; row++){
      for(int col = 0; col<3; col++){
      newArr[row][col] = matrix[row][col] + matrix1[row][col];
    }
    }

  int count = 0;
  for(int row = 0; row<2; row++){
    for(int col = 0; col<3; col++){
      cout<<"|"<<newArr[row][col]<<"| ";
        count++;
      if(count % 3 == 0){
        cout<<"\n--------------\n";
      }
    }
  }

  return 0;
  }
