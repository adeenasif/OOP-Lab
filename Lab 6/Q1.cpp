#include<iostream>
using namespace std;

class BankAccount{
	protected:
		int accNum;
		double balance;
	
	public:
		BankAccount() {  // default constructor
			accNum = 0;
			balance = 0.0;
		}
		BankAccount(int num, double bal) {  // parameterized
			accNum = num;
			balance = bal;
		}
		
		void deposit(double amount) {
			balance += amount;
			cout << amount << "$ deposited successfully!" << endl;
		}
		
		void withdraw(double amount) {
			if (amount <= balance) {
				balance -= amount;
				cout << amount << "$ withdrawn successfully!" << endl;
			} else {
				cout << "Insufficient Balance!" << endl;
			}
		}
};

class SavingsAccount : public BankAccount{
	public:
		SavingsAccount(int num, double bal) : BankAccount(accNum, balance){ }
		
		void monthlyInterest(double rate) {
			balance += (balance * (rate/100));
		}
};

class CheckingAccount : protected BankAccount {
	public:
		void overdraft(){
			
		}
	
};

int main(){
	SavingsAccount acc1(123, 123456.78);
	cout << "Savings Account:" << endl;
	acc1.deposit(12);
	acc1.withdraw(5);
	cout << endl << endl;
	
	
}



