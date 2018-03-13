#include <iostream>
#include <assert.h>
using namespace std;

int main(){
  int students[5][3] = {{78,83,82}, {90,88,94}, {71,73,78}, {97,96,95}, {89,93,90}};
  int students1[5][3] = {{78,83,82}, {90,88,94}, {71,73,78}, {97,96,95}, {89,93,90}};
  int count = 0;
  for(int row = 0; row<5; row++){
    for(int col = 0; col<3; col++){
      cout<<"|"<<students[row][col]<<"| ";
      count++;
      if(count % 3 == 0){
        cout<<"\n--------------\n";
      }
    }
  }

  for(int row = 0; row<5; row++){
    int average = 0, sum = 0;
    for(int col = 0; col<3; col++){
      sum += students[row][col];
      }
        average += sum/3;
        cout<<"average = "<<average<<endl;
    }

  return 0;
}
