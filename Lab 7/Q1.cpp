#include<iostream>
#include<vector>
#include<cmath>
#include<iomanip>  // to set precision of double values
using namespace std;

class Account {
protected:
    int accNum;
    double balance;
    string name;
    string accType;
    vector<string> transactions;
    
public:
    Account(int num, double bal, string n, string type) : accNum(num), balance(bal), name(n), accType(type) {}
    
    void deposit(double amount) {
        balance += amount;
        transactions.push_back("Deposited: $" + to_string_fixed(amount));
    }
    
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactions.push_back("Withdrawn: $" + to_string_fixed(amount));
        } else {
            cout << "INSUFFICIENT BALANCE!!" << endl;
        }
    }
    
    virtual void calcInterest() {}
    
    void getAccInfo() {
        cout << fixed << setprecision(2);
        cout << "Account Number: " << accNum << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Holder Name: " << name << endl;
        cout << "Account Type: " << accType << endl;
    }
    
    void PrintStatement() {
        cout << "Transaction History for Account " << accNum << ":\n";
        for (const auto& transaction : transactions) {
            cout << transaction << endl;
        }
    }
    
    static string to_string_fixed(double value) {
        ostringstream out;
        out << fixed << setprecision(2) << value;
        return out.str();
    }
};

class SavingsAccount : public Account {
    double rate;
    double minBalance;
    
public:
    SavingsAccount(int num, double bal, string n, double r, double min) : Account(num, bal, n, "Savings"), rate(r), minBalance(min) {}
    
    void calcInterest() override {
        double interest = balance * rate / 100;
        balance += interest;
        transactions.push_back("Interest Applied: $" + to_string_fixed(interest));
    }
    
    void withdraw(double amount) override {
        if (amount > balance) {
            cout << "INSUFFICIENT BALANCE!!" << endl;
        } else if ((balance - amount) < minBalance) {
            cout << "You have reached minimum balance limit! " << endl;
        } else {
            balance -= amount;
            transactions.push_back("Withdrawn: $" + to_string_fixed(amount));
        }
    }
};

class CheckingAccount : public Account {
    double overdraftLimit;
    
public:
    CheckingAccount(int num, double bal, string n, double limit) : Account(num, bal, n, "Checking"), overdraftLimit(limit) {}
    
    void withdraw(double amount) override {
        if (amount > balance + overdraftLimit) {
            cout << "Overdraft limit exceeded! Transaction denied." << endl;
        } else {
            balance -= amount;
            transactions.push_back("Withdrawn: $" + to_string_fixed(amount) + " (Overdraft Allowed)");
        }
    }
};

class FixedDepositAccount : public Account {
    double fixedRate;
    int maturityDate;
    
public:
    FixedDepositAccount(int num, double bal, string n, double rate, int maturity) : Account(num, bal, n, "Fixed Deposit"), fixedRate(rate), maturityDate(maturity) {}
    
    void calcInterest() override {
        double interest = balance * pow(1 + fixedRate / 100, maturityDate) - balance;
        balance += interest;
        transactions.push_back("Fixed Deposit Interest Applied: $" + to_string_fixed(interest));
    }
    
    void withdraw(double amount) override {
        cout << "Withdrawals are not allowed until maturity period is over in Account " << accNum << endl;
    }
};

int main() {
    SavingsAccount sa(101, 5000, "Emma Doe", 5, 1000);
    CheckingAccount ca(102, 3000, "Johnny Depp", 500);
    FixedDepositAccount fda(103, 10000, "Tom Cruise", 6, 5);
    
    sa.deposit(2000);
    sa.calcInterest();
    sa.withdraw(1000);
    sa.getAccInfo();
    sa.PrintStatement();
    
    cout << "\n-----------------------------\n";
    
    ca.deposit(1500);
    ca.withdraw(4000);
    ca.getAccInfo();
    ca.PrintStatement();
    
    cout << "\n-----------------------------\n";
    
    fda.calcInterest();
    fda.withdraw(5000);
    fda.getAccInfo();
    fda.PrintStatement();
    
    return 0;
}
