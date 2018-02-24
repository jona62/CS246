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
