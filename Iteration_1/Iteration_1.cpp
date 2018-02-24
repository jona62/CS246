#include <iostream>
using namespace std;

void thePromise(){
  int money = 10;
  int age = 12;
  int sum = money;

  while(money <= 1000){
    // cout<<"age "<<age<<endl;
    // cout<<"money "<<money<<endl;
    // cout<<"sum "<<sum<<endl<<endl;

    money = (money * 2);
    sum += money;
    age++;
  }
    cout<<"Age = "<<age<<endl;
    cout<<"Sum = "<<sum<<endl;

}

void factorsOf(int n){
 int i = 1;
  while(i <= n){
   if(n % i == 0){
     cout<<i<<" ";
   }
   i++;
  }
}

void divisibleBy3(int arr[], int size){
  int limit = 20;
  int iter=0;
  int ceiling;

  if(size > 50){
    ceiling = 50;
  }
  else{
    ceiling = size;
  }
  while(ceiling > 0 && limit > 0){
    if(arr[iter] % 3 == 0){
      cout<<arr[iter]<<" ";
      limit--;
    }
    iter++;
    ceiling--;
  }
}

void absVal(int &x, int &y){
if(x < 0) x = x * (-1);
if(y < 0) y = y * (-1);

}

//3. Multiplies two integers without using the '*' operator, works for negative numbers as well
int multiply(int x, int y){
  int answer = 0;
if((x < 0) && (y < 0)){
  absVal(x,y);
  while(y != 0){
      y--;
      answer += x;
    }
    return answer;
}
if(x < 0){
  absVal(x,y);
  while(y != 0){
    y--;
    answer += x;
  }
  return answer * -1;
}
if(y < 0){
  absVal(x,y);
  while(y != 0){
    y--;
    answer += x;
  }
  return answer * -1;
}

}

int multiplyExample(int x, int y){
  int answer = 0;
  while(y != 0){
    y--;
    answer += x;
  }
  return answer;
}




//I decrement the length of the variable by dividing it by 10, then increment the value of the count variable by one
int count(int x){
  int count = 0;
  while(x != 0){
    x = x / 10;
    count++;
  }
  return count;
}

int main() {
    int array[] ={3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,63,66,69,72,75,78,81,84,87,90,93,96,99,102,105,108,111,114,117,120,123,126,129,132,135,138,141,144,147,150};

  thePromise();
  divisbleBy3();
  factorsOf(59);
  
  cout<< multiply(-2,-2);
  cout<<count(11221);
return 0;
}
