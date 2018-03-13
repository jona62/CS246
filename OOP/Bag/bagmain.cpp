#include "bag.h"

int main(){
  Bag calvinKlein;

  calvinKlein.print();
  cout<<endl;

  srand(time(NULL));
  for(int i=0; i<SIZE; i++){
    int randomNum = rand() % 9 + 1;
    calvinKlein.insert(randomNum);
  }

  calvinKlein.print();
  cout<<endl;

  calvinKlein.remove(1);
  calvinKlein.remove(1);
  calvinKlein.remove(1);

  calvinKlein.print();


  return 0;
}
