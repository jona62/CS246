Bank::Bank(){
	balance = 0.0;
	acct_No = get_acct_No();
}
void Bank::set_acct_No(){
	srand(time(NULL));
	int pass = rand()% 20000;
	acct_No = pass;
}

void Bank::deposit(int amount){
	balance += amount;
}

void Bank::withdraw(int amount){
	balance -= amount;
}

void Bank::set_name(string str){
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

void Bank::display_info(){
  int choice;
  cout<<customer.<<"\n\n";
  stringstream out;
  out<<left<<"1.Cash Deposit"<<setw(60)<<right<<"2.Cash Withdrawal\n\n";
  out<<left<<"3.Balance Enquiry"<<setw(59)<<right<<"4.Exit\n\n";
  out<<"Select your Transaction: ";
  cout<<out.str();

  cin>>choice;
  switch (choice){
    case 1:
    break;
    case 2:
    break;
    case 3:
    break;
    case 4:
    break;

    default:
      cout<<"Invalid! Operation Try again ";
      loggedInterface(customer);
  }

}
