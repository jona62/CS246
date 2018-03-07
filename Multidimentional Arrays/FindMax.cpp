#include <iostream>
#include <assert.h>
using namespace std;

int main(){
  int students[5][3] = {{78,83,82}, {90,88,94}, {71,73,78}, {97,96,95}, {89,93,90}};
  int max = students[0][0];
    for(int row = 0; row<5; row++){
      for(int col = 0; col<3; col++){
        if(students[row][col] > max){
          max = students[row][col];
        }
      }
    }
    cout<<max<<endl;
  return 0;
}
