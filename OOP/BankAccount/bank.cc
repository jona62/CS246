#include "bank.h"
Bank::Bank(){
	balance = 0.0;
	set_acct_No();
	acct_No = get_acct_No();
}

void Bank::set_acct_No(){
	srand(time(NULL));
	int pass = rand()% 900000000 + 200000000;
	acct_No = pass;
}

void Bank::deposit(int amount){
	balance += amount;
}

void Bank::withdraw(int amount){
	balance -= amount;
}

void Bank::set_name(){
	string str;
	cout<<"Enter Your Fullname: ";
	getline(cin, name);
	name = str;
}

int Bank::get_balance() const{
	return balance;
}

int Bank::get_acct_No() const{
	return acct_No;
}

string Bank::get_name() const{
	return name;
}

void Bank::display_menu(){
  int choice;
  int amount;
  cout<<"\n\n";
  stringstream out;
  cout<<"******************************************************************\n";
  out<<left<<"1.Cash Deposit"<<setw(40)<<right<<"2.Cash Withdrawal\n\n";
  out<<left<<"3.Balance Enquiry"<<setw(26)<<right<<"4.Exit\n\n";
  out<<"Select your Transaction: ";
  cout<<out.str();

  cin>>choice;
  switch (choice){
    case 1:
      cout<<"Enter amount: ";
      cin>>amount;
      Bank::deposit(amount);
      Bank::display_menu();
    break;
    case 2:
      do{cout<<"Enter amount: ";
      cin>>amount;
      if(Bank::get_balance() - amount < 0) cout<<"\nYou know thats not possible bruh!\nEnter what you have";
      }while(Bank::get_balance() - amount < 0);
      Bank::withdraw(amount);
      Bank::display_menu();
    break;
    case 3:
			cout<<"\n******************************************************************\n";
      cout<<"Your Balance is $"<<Bank::get_balance();
      Bank::display_menu();
    break;
    case 4:
    break;

    default:
      cout<<"Invalid! Operation Try again ";
      Bank::display_menu();
  }

}

void Bank::display_info(){
	cout<<"Welcome "<<get_name();
	cout<<"\nYour Account Number is: "<<get_acct_No();
	cout<<", and you have $"<<get_balance()<<" in your account. \n";
}
