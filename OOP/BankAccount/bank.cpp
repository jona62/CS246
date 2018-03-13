<<<<<<< HEAD
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iomanip>
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
	customer.set_acct_No();

 	cout<<"Welcome "<<customer.get_name()<<"\nYour Account Number is: "<<customer.get_acct_No()<<", and you have $"<<customer.get_balance()<<" in your account. \n";

  customer.display_info();


	return 0;
}
=======
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;
#include "bank.cc"

int main(){
	string name;
	cout<<"Enter Your Fullname: ";
	getline(cin, name);

	cout<<endl;

	Bank customer;
	customer.set_name(name);
	customer.set_acct_No();

 	cout<<"Welcome "<<customer.get_name()<<"\nYour Account Number is: "<<customer.get_acct_No()<<", and you have $"<<customer.get_balance()<<" in your account. \n";

  customer.display_info();


	return 0;
}
>>>>>>> b2346603408c95fc615123dd29f28c6ef50b61bf
