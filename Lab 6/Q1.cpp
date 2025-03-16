#include<iostream>
using namespace std;

class BankAccount{
	protected:
		int accNum;
		double balance;
	
	public:
		BankAccount(int num, double bal) {  
			accNum = num;
			balance = bal;
		}
		virtual ~BankAccount() {}
		
		virtual void deposit(double amount) {
			balance += amount;
			cout << amount << "$ deposited successfully!" << endl;
		}
		
		virtual bool withdraw(double amount) {
			if (amount <= balance) {
				balance -= amount;
				cout << amount << "$ withdrawn successfully!" << endl;
				return true;
			} else {
				cout << "Insufficient Balance!" << endl;
				return false;
			}
		}
		virtual void monthlyInterest() {}  // interest/tax
    
	    void displayBal() const {
	        cout << "Account: " << accNum << " | Balance: $" << balance << endl;
	    }
};

class SavingsAccount : public BankAccount{
	double rate;  // monthly interest rate
	public:
		SavingsAccount(int num, double bal, double r) : BankAccount(num, bal){
			rate = r; 
		}
		
		void monthlyInterest() override {
        	double interest = balance * rate;
			balance += interest;
			cout << "Interest Applied: $" << interest << " to Account " << accNum << endl;
		}
};

class CheckingAccount : public BankAccount {
	protected:
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

class BusinessAccount : public BankAccount {
	protected:
		double taxRate;
	public:
		BusinessAccount(int num, double bal, double rate) : BankAccount(num, bal){
			taxRate = rate;
		}
		void deposit(double amount) override {
			double tax = amount * taxRate;
			balance += (amount-tax);
			cout << amount << "$ deposited successfully!" << " after Tax Deduction: $" << tax << " in Account " << accNum << endl;
		}
};

class User {
	protected:
	    string name;
	
	public:
	    User(string n) : name(n) {}
   	 	virtual ~User() {}
};

class Employee : public User {
	public:
		Employee(string n) : User(n) { }
};

class Customer : public User {
	BankAccount* account;
	public:
    Customer(string n, BankAccount* acc) : User(n), account(acc) {}
    
    void deposit(double amount)   { account->deposit(amount); }
    void withdraw(double amount)  { account->withdraw(amount); }
    void checkBalance() { account->displayBal(); }
};

class Teller : public Employee {
	public:
    Teller(string n) : Employee(n) {}
    
    void depositT(BankAccount* acc, double amount) { acc->deposit(amount); }
    void withdrawT(BankAccount* acc, double amount) { acc->withdraw(amount); }
    void freezeAccount(BankAccount* acc) {
        cout << "Account frozen by Teller." << endl;
		acc->displayBal();
    }
};

class Manager : public Teller {
	public:
	    Manager(string n) : Teller(n) {}
	    
	    void adjustLimit(CheckingAccount* acc, double newLimit) {
	        cout << "Manager has adjusted overdraft limit." << endl;
	    }
};

int main(){
	SavingsAccount* sAcc = new SavingsAccount(123, 5000, 0.02);
	CheckingAccount* cAcc = new CheckingAccount(456, 2000, 500);
	BusinessAccount* bAcc = new BusinessAccount(789, 10000, 0.05);


    Customer cust("Alice", sAcc);
    Teller tell("Bob");
    Manager mgr("Charlie");
    
    cout << "\n---- Customer Transactions ----" << endl;
    cust.deposit(1000);
    cust.withdraw(200);
    cust.checkBalance();

    cout << "\n---- Teller Transactions ----" << endl;
    tell.depositT(cAcc, 1500);
    tell.withdrawT(cAcc, 3000);
    tell.freezeAccount(bAcc);

    cout << "\n---- Manager Transactions ----" << endl;
    mgr.adjustLimit(cAcc, 1000);
    
    cout << "\n---- Applying Monthly Interest ----" << endl;
    sAcc->monthlyInterest();
	bAcc->monthlyInterest();
	
	
	cout << "\n---- Account Details ---- "<< endl;
    sAcc->displayBal();
    cAcc->displayBal();
    bAcc->displayBal();
    
    delete sAcc;
    delete cAcc;
    delete bAcc;
    
    return 0;
}
