//Calculates the percentage Change of Bitcoins over the period of six months and stores the values in an array
#include <iostream>
#include <assert.h>
using namespace std;

int main(){
  int array[6] = {4780, 4318, 6253, 10357, 13672, 9641};
  float BitCoin[6];
  float difference = 0;
  float absolutePercentage = 0;

  for(int i = 0; i<6; i++){
    // absolutePercentage = Absval(difference)/100;
    // assert(i<6);
    absolutePercentage = difference/100;
    BitCoin[i] = absolutePercentage;
    difference = array[i+1] - array[i];
  }

  int count =0;
  for(int i = 0; i<6; i++){
    int j = i+1;
    switch (j) {
      case 1:
        cout<<1<<"st";
        break;
      case 2:
        cout<<2<<"nd";
        break;
      case 3:
        cout<<3<<"rd";
        break;
      default:
        cout<<i+1<<"th";
    }
      cout<<" Month "<<BitCoin[i]<<"% ";
        count++;
      if(count % 1 == 0){
        cout<<"\n-----------------\n";
      }
  }

return 0;
}
