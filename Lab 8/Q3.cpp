#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class BigInteger {
private:
    vector<int> digits; // least significant digit first
    bool isNegative;

    void removeLeadingZeros() {
        while (digits.size() > 1 && digits.back() == 0) {
            digits.pop_back();
        }
        if (digits.size() == 1 && digits[0] == 0) {
            isNegative = false;
        }
    }

public:
    BigInteger() : isNegative(false) { digits.push_back(0); }
    BigInteger(string num) {
        
        isNegative = (num[0] == '-');
        for (int i = num.length() - 1; i >= (isNegative ? 1 : 0); --i) {
            digits.push_back(num[i] - '0');
        }
        removeLeadingZeros();
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
        	
            BigInteger result;
            result.isNegative = isNegative;
            
            result.digits.clear();
            int carry = 0, sum;
            
            int maxSize = max(digits.size(), other.digits.size());
            
			for (int i = 0; i < maxSize || carry; ++i) {
                int d1 = (i < digits.size()) ? digits[i] : 0;
                int d2 = (i < other.digits.size()) ? other.digits[i] : 0;
                
                sum = d1 + d2 + carry;
                carry = sum / 10;
                result.digits.push_back(sum % 10);
            }
            result.removeLeadingZeros();
            return result;
        }
        return *this - (-other);
    }
    
    BigInteger operator-() const {
        BigInteger result = *this;
        if (!(digits.size() == 1 && digits[0] == 0)) {
            result.isNegative = !isNegative;
        }
        return result;
    }

    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return *this + (-other);
        }
        
        bool negResult = *this < other;
        const BigInteger& larger = negResult ? other : *this;
        const BigInteger& smaller = negResult ? *this : other;
        
		BigInteger result;
        result.isNegative = negResult;
        result.digits.clear();
        
        int borrow = 0, diff;
        
		for (int i = 0; i < larger.digits.size(); ++i) {
            int d1 = larger.digits[i];
            int d2 = (i < smaller.digits.size()) ? smaller.digits[i] : 0;

            diff = d1 - d2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }

            result.digits.push_back(diff);
        }
        result.removeLeadingZeros();
        return result;
    }
    
    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return isNegative;
        }
        if (digits.size() != other.digits.size()) {
            return isNegative ? digits.size() > other.digits.size() : digits.size() < other.digits.size();
        }
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i]) {
                return isNegative ? digits[i] > other.digits[i] : digits[i] < other.digits[i];
            }
        }
        return false;
    }
    
    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && digits == other.digits;
    }
    
    bool operator!=(const BigInteger& other) const { 
		return !(*this == other); 
	}
    
	bool operator>(const BigInteger& other) const { 
		return other < *this; 
	}
    
	bool operator<=(const BigInteger& other) const { 
		return !(other < *this); 
	}
    
	bool operator>=(const BigInteger& other) const { 
		return !(*this < other); 
	}
	
	friend ostream& operator<<(ostream& out, const BigInteger& num) {
	    if (num.isNegative) out << '-';
	    for (int i = num.digits.size() - 1; i >= 0; --i) {
	        out << num.digits[i];
	    }
	    return out;
	}
	friend istream& operator>>(istream& in, BigInteger& num) {
	    string input;
	    in >> input;
	    num = BigInteger(input);
	    return in;
	}
};


int main() {
    BigInteger a, b;
    cout << "Enter large number (1): ";
    cin >> a;
    cout << "Enter large number (2): ";
	cin >> b;
	
	cout << "Sum: " << (a + b) << endl;
    cout << "Difference: " << (a - b) << endl;
    cout << "Comparison: " << (a > b ? "number 1 is greater" : "numer 2 is greater or equal to number 1") << endl;
    return 0;
}

