#include<iostream>
using namespace std;

class Fraction {
	int numerator;
	int denominator;
	
	int findGCD(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
        
		void reducedFraction() {
            int g = findGCD((numerator),(denominator));
            numerator /= g;
            denominator /= g; 
            
            if (denominator < 0) {
                numerator = -numerator;
                denominator = -denominator;
            }
		}
		
	public:
		Fraction(int num = 0, int den = 1) {
            numerator = num;
            denominator = den;
            reducedFraction();
		}
		
		Fraction operator+(Fraction const& obj) {
			return Fraction((numerator*obj.denominator + obj.numerator*denominator), denominator*obj.denominator);
		}
		Fraction operator-(Fraction const& obj) {
			return Fraction((numerator*obj.denominator - obj.numerator*denominator), denominator*obj.denominator);
		}
		Fraction operator*(Fraction const& obj) {
			return Fraction((numerator*obj.numerator), (denominator*obj.denominator));
		}
		Fraction operator/(Fraction const& obj) {
			return Fraction(numerator*obj.denominator, denominator*obj.numerator);
		}
		bool operator==(const Fraction& obj) const {
			return numerator == obj.numerator && denominator == obj.denominator;
		}
		bool operator!=(const Fraction& obj) const {
			return numerator != obj.numerator && denominator != obj.denominator;
		}
		bool operator<(const Fraction& obj) const {
			return numerator * obj.denominator < obj.numerator * denominator;
        }
		bool operator>(const Fraction& obj) const {
			return numerator * obj.denominator > obj.numerator * denominator;
        }
		bool operator>=(const Fraction& obj) const {
			return numerator * obj.denominator >= obj.numerator * denominator;
        }
		bool operator<=(const Fraction& obj) const {
			return numerator * obj.denominator <= obj.numerator * denominator;
        }
        
        friend ostream& operator<<(ostream& os, const Fraction& f) {
        	os << f.numerator;
        	if (f.denominator != 1) {
        		os << "/" << f.denominator;
			}
			return os;
		}
		
		friend istream& operator>>(istream& is, Fraction& f) {
        	char symbol;
            is >> f.numerator >> symbol >> f.denominator;
            f.reducedFraction();
            return is;
		}
};

int main() {
    Fraction f1, f2;
    cout << "Enter two fractions (a/b): ";
    cin >> f1 >> f2;

    cout << "\nSimplified Fraction 1: " << f1 << endl;
    cout << "Simplified Fraction 2: " << f2 << endl;
    
    cout << "\nArithmetic Operations : " << endl << endl;
    cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
    cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
    cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
    cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;
    
    cout << "\nRelational Operators : " << endl << endl;
    cout << f1 << " == " << f2 << " ? " << (f1 == f2 ? "True" : "False") << endl;
    cout << f1 << " != " << f2 << " ? " << (f1 != f2 ? "True" : "False") << endl;
    cout << f1 << " < " << f2 << " ? " << (f1 < f2 ? "True" : "False") << endl;
    cout << f1 << " > " << f2 << " ? " << (f1 > f2 ? "True" : "False") << endl;
    cout << f1 << " <= " << f2 << " ? " << (f1 <= f2 ? "True" : "False") << endl;
    cout << f1 << " >= " << f2 << " ? " << (f1 >= f2 ? "True" : "False") << endl;

    return 0;
}
