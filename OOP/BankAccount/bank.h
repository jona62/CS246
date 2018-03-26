#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

class Bank{
	private:
		double balance;
		int acct_No;
		string name;

	public:
		Bank();
		void set_acct_No();
		void deposit(int amount);
		void withdraw(int amount);
		void set_name();
		void display_info();
		void display_menu();
		int get_balance() const;
		int get_acct_No() const;
		string get_name() const;
};
