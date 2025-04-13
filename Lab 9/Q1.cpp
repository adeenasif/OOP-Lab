#include <iostream>
using namespace std;

class Wallet {
	private:
		double balance;
		double dailyDepositTotal;
	    double dailyWithdrawTotal;
	    static const double maxDeposit;
	    static const double maxWithdraw;

	public:
		Wallet () {
			balance = 0.0;
			dailyDepositTotal = 0.0;
			dailyWithdrawTotal = 0.0;
		}
		bool deposit(double amount) {
			if (dailyDepositTotal + amount > maxDeposit){
				cout << "Today's MAX limit reached for deposit" << endl;
				return false;
			} else {
				balance += amount;
				dailyDepositTotal += amount;
				cout << "Money deposited successfully! Total Balance: $" << balance << endl;
				return true;
			}
			
		}
		bool withdraw(double amount) {
			if (dailyWithdrawTotal + amount > maxWithdraw) {
				cout << "Today's MAX limit reached for withdraw" << endl;
				return false;
			}
			if (amount >= balance) {
				cout << "INSUFFICIENT BALANCE" << endl;
				return false;
			} else {
				balance -= amount;
				cout << "Money withdrawn successfully! Total Balance: $" << balance << endl;
				return true;
			}
		}

	    double getBalance() const {
	        return balance;
		}
};

const double Wallet::maxDeposit = 1000.0;
const double Wallet::maxWithdraw = 500.0;

class User {
	private:
		int userID;
		string name;
		Wallet wallet;
		
	public:
		User(int id, string n) {
			userID = id;
			name = n;
		}
		void deposit(double amount){
			cout << name << " attempting to deposit $" << amount << endl;
			wallet.deposit(amount);
		}
		void withdraw(double amount){
			cout << name << " attempting to withdraw $" << amount << endl;
			wallet.withdraw(amount);
		}
		void showBalance() const {
			cout << " ---- Account Details ---- " << endl;
			cout << "Name: " << name << endl;
			cout << "Current Balance: $" << wallet.getBalance() << endl;
		}
};

int main() {
    User user1(12, "Ali");
    User user2(13, "Amna");

    user1.deposit(300);
    cout << endl;
    user1.withdraw(100);
    cout << endl;
	user1.showBalance();
	cout << endl;
    
	user1.deposit(1000);  
    cout << endl;
	user1.withdraw(450); 
    cout << endl;
	user1.withdraw(450); 

    cout << endl;

    user2.deposit(200);
    cout << endl;
	user2.withdraw(50);
    cout << endl;
	user2.showBalance();

    return 0;
}
