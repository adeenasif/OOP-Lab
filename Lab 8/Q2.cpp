#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class PolynomialUtilityClass; // Forward declaration

class Polynomial {
	private:
	    vector<int> coeffs;
	    void trim() {
	        while (!coeffs.empty() && coeffs.back() == 0) {
	            coeffs.pop_back();
	        }
	    }
	public:
	    Polynomial() {}
	    Polynomial(const vector<int>& c) : coeffs(c) { trim(); }
	    
	    friend ostream& operator<<(ostream& os, const Polynomial& p);
	    friend class PolynomialUtilityClass;
	
	    Polynomial operator+(const Polynomial& other) const {
	        vector<int> result(max(coeffs.size(), other.coeffs.size()), 0);
	        for (size_t i = 0; i < coeffs.size(); i++) {
	            result[i] += coeffs[i];
			}
	        for (size_t i = 0; i < other.coeffs.size(); i++) {
	            result[i] += other.coeffs[i];
	        } 
			return Polynomial(result);
	    }
	
	    Polynomial operator-(const Polynomial& other) const {
	        vector<int> result(max(coeffs.size(), other.coeffs.size()), 0);
	        for (size_t i = 0; i < coeffs.size(); i++) {
	            result[i] += coeffs[i];
	        }
	        for (size_t i = 0; i < other.coeffs.size(); i++) {
	            result[i] -= other.coeffs[i];
	        }
	        return Polynomial(result);
	    }
	
	    Polynomial operator*(const Polynomial& other) const {
	        vector<int> result(coeffs.size() + other.coeffs.size() - 1, 0);
	        for (size_t i = 0; i < coeffs.size(); i++) {
	            for (size_t j = 0; j < other.coeffs.size(); j++) {
	                result[i + j] += coeffs[i] * other.coeffs[j];
	            }
	        }
	        return Polynomial(result);
	    }
	};
	
ostream& operator<<(ostream& os, const Polynomial& p) {
    if (p.coeffs.empty()) {
        os << "0";
        return os;
    }
    bool first = true;
    for (int i = p.coeffs.size() - 1; i >= 0; i--) {
        if (p.coeffs[i] != 0) {
            if (!first) {
				os << (p.coeffs[i] > 0 ? " + " : " - ");
			} else if (p.coeffs[i] < 0) {
				os << "-";
			}
			
            if (abs(p.coeffs[i]) != 1 || i == 0) {
				os << abs(p.coeffs[i]);
			}
			
            if (i > 0) {
            	os << "x";	
	            if (i > 1) {
    	        	os << "^" << i;	
				}
            }
			first = false;
        }
    }
    return os;
}

class PolynomialUtilityClass {
	public:
	    static int evaluate(const Polynomial& p, int x) {
	        int result = 0;
	        int power = 1;
	        for (size_t i = 0; i < p.coeffs.size(); i++) {
	            result += p.coeffs[i] * power;
	            power *= x;
	        }
	        return result;
	    }
	
	    static Polynomial derivative(const Polynomial& p) {
	        if (p.coeffs.size() <= 1) return Polynomial();
	        vector<int> deriv(p.coeffs.size() - 1);
	        for (size_t i = 1; i < p.coeffs.size(); i++)
	            deriv[i - 1] = p.coeffs[i] * i;
	        return Polynomial(deriv);
	    }
};

int main() {
    Polynomial p1({3, -2, 5}); // 5x^2 - 2x + 3
    Polynomial p2({1, 0, -4}); // -4x^2 + 1
    
    cout << "P1: " << p1 << endl;
    cout << "P2: " << p2 << endl;
    
    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;
    Polynomial deriv = PolynomialUtilityClass::derivative(p1);
    
    cout << "P1 + P2: " << sum << endl;
    cout << "P1 - P2: " << diff << endl;
    cout << "P1 * P2: " << prod << endl;
    cout << "Derivative of P1: " << deriv << endl;
    cout << "P1 evaluated at x = 2: " << PolynomialUtilityClass::evaluate(p1, 2) << endl;
    
    return 0;
}

