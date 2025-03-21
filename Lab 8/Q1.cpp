#include<iostream>
using namespace std;

class Fraction {
	int numerator;
	int denominator;
	
	public:
		Fraction(int num, int den) {
			numerator = num;
			denominator = den;
			if (denominator < 0) {
				numerator = -numerator;
				denominator = -denominator;
			}
		}
		
		void reducedFraction() {
			if (numerator < denominator) {
				min = numerator;
			} else {
				min = denominator;
			}
			while (min > 1) {
				if ( numerator % min == 0 && denominator % min == -) {
					break;
				}
				min--;
			}
			cout << "Reduced Numerator: " << numerator/min << endl;
			cout << "Reduced Denominator: " << denominator/min << endl;
		}
		
		Fraction operator+(Fraction const& obj) {
			return Fraction((numerator*obj.denominator + obj.numerator*denominator)/ denominator*obj.denominator)
		}
		Fraction operator+(Fraction const& obj) {
			return Fraction((numerator*obj.denominator + obj.numerator*denominator)/ denominator*obj.denominator)
		}
		
};

//3/2 + 2/3
//9+4/6
//13/6
