#include<iostream>
using namespace std;

class Account {
	int accNum;
	double balance;
	string name;  // account holder name
	string accType;
	
	public:
		Account(int num, double bal, string n, string type) {  
			accNum = num;
			balance = bal;
			name = n;
			accType = type;
		}
		
		void deposit(double amount) {
			balance += amount;
		}
		
		virtual void withdraw(double amount) {
			if (amount <= balance) {
				balance -= amount;
				cout << amount << "$ withdrawn successfully!" << endl;
			} else {
				cout << "INSUFFICIENT BALANCE!!" << endl;
			}
		}
		
		virtual void calcInterest (double rate) {
			
		}
		
		void getAccInfo() {
			cout << "Account Number: " << accNum << endl;
			cout << "Balance: " << balance << endl;
			cout << "Holder Name: " << name << endl;
			cout << "Account Type: " << accType << endl;
		}
		
		void printStatement () {
			
		}
};

class SavingsAccount : public BankAccount{
	double rate;  // interest rate
	double minBalance;
	
	public:
		SavingsAccount(int num, double bal, double r, double min) : BankAccount(num, bal, r, min){
			rate = r; 
			minBalance = min;
		}
		
		void calcInterest() override {
        	double interest = balance * rate / 100;
			balance += interest;
			cout << "Interest Applied: $" << interest << " to Account " << accNum << endl;
		}
		void withdraw(double amount) override {
			if (amount >= minBalance && amount <= balance) {
				balance -= amount;
				cout << amount << "$ withdrawn successfully!" << endl;
			} else if (amount >) {
				cout << "INSUFFICIENT BALANCE!!" << endl;
			} else if ((balance - amount) <= minBalance) {
				cout << "You have reached minimum balance limit! " << endl;
			}
		}
};


class CheckingAccount : public BankAccount {
	const double limit;
	
	public:
		CheckingAccount(int num, double bal, double limit) : BankAccount(num, bal), limit(limit){
			
		}
		bool withdraw(double amount) override {
	        if (amount > balance + limit) {
	            cout << "Overdraft limit exceeded! Transaction denied." << endl;
	            return false;
	        }
	        balance -= amount;
	        cout << "Withdrawn: $" << amount << " (Overdraft Allowed) from Account " << accNum << endl;
	        return true;
	    }
};

class FixedDepositAmount : public BankAccount {
	double fixedRate;  // interest rate
	int maturityDate;
	
	public:
		void calcInterest() override {
        	double amount = balance * pow(1 + fixedRate, maturityDate);
        	double interest amount - balance;
        	balance += interest;
			cout << "Interest Applied: $" << interest << " to Account " << accNum << endl;
		}
		void withdraw () override {
			
		}
};






