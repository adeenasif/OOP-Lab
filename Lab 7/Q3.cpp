#include <iostream>
#include <iomanip>  // for precise currency output
using namespace std;

class Currency {
protected:
    double amount;
    int currencyCode;
    char symbol;  // Currency symbol
    double rate;  // exchange rate 

public:
    Currency(double a, int code, char s, double r) : amount(a), currencyCode(code), symbol(s), rate(r) {}

    virtual void convertToBase() = 0;

    void convertTo(Currency* targetCurrency) {
        // convert to base first
        convertToBase();

        // then convert to target currency
        double convertedAmount = amount / targetCurrency->rate;
        cout << "\nConverted Amount: " << targetCurrency->symbol << " " << fixed << setprecision(2) << convertedAmount << endl;
    }

    virtual void displayCurrency() const {
        cout << "\nAmount: " << fixed << setprecision(2) << amount << endl;
        cout << "Currency Code: " << currencyCode << endl;
        cout << "Symbol: " << symbol << endl;
        cout << "Exchange Rate: " << rate << endl;
    }

    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(double a, int code, double r) : Currency(a, code, '$', r) {}

    void convertToBase() override {
        // dollar is the base currency, so no conversion needed
        cout << "\nAmount in USD : " << fixed << setprecision(2) << amount << endl;
    }

    void displayCurrency() const override {
        cout << "\nCurrency: Dollar" << endl;
        Currency::displayCurrency();
        cout << "--------------------" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double a, int code, double r) : Currency(a, code, '€', r) {}

    void convertToBase() override {
        amount = amount * rate;
        cout << "\nConverted to Base (USD): " << fixed << setprecision(2) << amount << endl;
    }

    void displayCurrency() const override {
        cout << "\nCurrency: Euro" << endl;
        Currency::displayCurrency();
        cout << "--------------------" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double a, int code, double r) : Currency(a, code, '₹', r) {}

    void convertToBase() override {
        amount = amount * rate;
        cout << "\nConverted to Base (USD): " << fixed << setprecision(2) << amount << endl;
    }

    void displayCurrency() const override {
        cout << "\nCurrency: Rupee" << endl;
        Currency::displayCurrency();
        cout << "--------------------" << endl;
    }
};

int main() {
    Dollar dollar(100, 840, 1.0);  
    Euro euro(85, 978, 1.18);      
    Rupee rupee(7000, 356, 0.013); 

    dollar.displayCurrency();
    euro.displayCurrency();
    rupee.displayCurrency();

    cout << endl;

    cout << "\nConverting Dollar to Euro:" << endl;
    dollar.convertTo(&euro);
	cout << "--------------------" << endl;
	
    cout << "\nConverting Euro to Dollar:" << endl;
    euro.convertTo(&dollar);
	cout << "--------------------" << endl;
    
	cout << "\nConverting Rupee to Dollar:" << endl;
    rupee.convertTo(&dollar);
	cout << "--------------------" << endl;
	
    return 0;
}

