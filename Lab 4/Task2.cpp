#include<iostream>
using namespace std;

class Account{
	double balance;
	
	public:
		void addAmount(double amount){
			balance += amount;
			cout << amount << " added successfully!" << endl;
		}
		
		void withdraw(double amount){
			if (balance >= amount){
				balance -= amount;
				cout << amount << " deducted successfully!" << endl;
			} else {
				cout << "Sorry, Not enough money in your account!" << endl;
			}
		}
		
		double currBal(){
			return balance;
		}
};

int main(int argc, char *argv[]){
	Account acc;
	
	if (argc < 3){
		cout << "MISSING DATA!! Please enter amount to add and withdraw!"; 
		return 1;
	}
		
	double curr = 0.0;
	cout << "Current Balance of your account: " << curr << endl << endl;
	acc.addAmount(stod(argv[1]));
	curr = acc.currBal();
	
	cout << "Current Balance of your account: " << curr << endl << endl;
	acc.withdraw(stod(argv[2]));
	
	curr = acc.currBal();
	cout << "Current Balance of your account: " << curr << endl << endl;


	return 0;
}
