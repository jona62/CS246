#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
// #include "bank.cc"
using namespace std;
#include "bank.h"

int main(){
	string name;
	cout<<"Enter Your Fullname: ";
	getline(cin, name);

	cout<<endl;

	Bank customer;
	customer.set_name(name);

 	cout<<"Welcome "<<customer.get_name()<<"\n Your Account Number is: "<<customer.get_acct_No()<<", and you have $"<<customer.get_balance()<<" in your account. \n";

	

	return 0;
}
