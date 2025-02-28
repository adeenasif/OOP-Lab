#include<iostream>
using namespace std;

class Account{
	int accNum;
	string holderName;
	double balance;
	string accType;
	
	public:
		Account() {  // default constructor
			accNum = 0;
			holderName = "";
			balance = 0.0;
			accType = "";
		}
		
		Account(int num, string name, double bal, string type){  // parametrized constructor
			accNum = num;
			holderName = name;
			balance = bal;
			accType = type;
		}
		
		Account(const Account& obj) {  // copy constructor
			accNum = obj.accNum;
			holderName = obj.holderName;
			balance = obj.balance;
			accType = obj.accType;
		}
		
		void withdraw(double amount) {
			if (amount <= balance) {
				balance -= amount;
				cout << amount <<"$ withdrawn." << endl;
			} else {
				cout << "Insufficient Balance!" << endl;
			}
		}
		
		void deposit(double amount) {
			balance += amount;
			cout << amount <<"$ deposited successfully." << endl;
		}
		
		void checkBalance() {
			cout << "Current Balance: $" << balance << endl;
		}
		void miniStatement() {
			cout << "Account Details:" << endl;
			cout << "Holder name: " << holderName << endl;
			cout << "Account Number: " << accNum << endl;
			cout << "Balance: $" << balance << endl;
			cout << "Account Type: " << accType << endl;
		}
};

int main(){
	Account acc1(123, "Adeena Asif", 90900.78, "Savings");
	acc1.checkBalance();
	acc1.deposit(120);
	acc1.withdraw(150);
	
	cout << endl << endl; 
	acc1.miniStatement();
	cout << endl << endl; 
	
	cout << "Account 2 copied from Account 1: " << endl; 
	Account acc2(acc1);
	
	acc2.checkBalance();
	acc2.deposit(10);
	acc2.withdraw(50);
	
	cout << endl << endl; 
	acc2.miniStatement();

}




