#include <iostream>
#include<cmath>
using namespace std;

class Polynomial {
private:
    double* coefficients;
    int degree;  

public:
    Polynomial() : degree(0){  // default
    	degree = 0;
        coefficients = new double[1]{0};
    }

    Polynomial(int deg, const double* coeff) : degree(deg) {  // parameterized
    	this->degree = degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeff[i];
        }
    }

    Polynomial(const Polynomial& other) {  // copy
    	degree = other.degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {// Move constructor
        other.coefficients = nullptr;
        other.degree = 0;
    }

    ~Polynomial() { // Destructor 
        delete[] coefficients;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double result = 0.0;
        double xPower = 1;

        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * xPower;
            xPower *= x;
        }

        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int maxDegree = max(degree, other.degree);
        double* newCoeffs = new double[maxDegree + 1]{};

        for (int i = 0; i <= degree; ++i) {
            newCoeffs[i] += coefficients[i];
        }
        for (int i = 0; i <= other.degree; ++i) {
            newCoeffs[i] += other.coefficients[i];
        }

        Polynomial result(maxDegree, newCoeffs);
        delete[] newCoeffs;
        return result;
    }

    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* newCoeffs = new double[newDegree + 1]{};

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        Polynomial result(newDegree, newCoeffs);
        delete[] newCoeffs;
        return result;
    }
    
    void display() const {
        for (int i = degree; i >= 0; --i) {
            cout << coefficients[i];
            if (i != 0) {
                cout << "x^" << i << " + ";
            }
        }
        cout << endl;
    }
};

int main() {
    double coeffs1[] = {3, -3, 2, 1}; 
    Polynomial p1(3, coeffs1);
    cout << "Polynomial 1: " << endl;
    p1.display();

	cout << endl << endl;
	
	Polynomial p2 = p1;
	cout << "Polynomial 2 copied from Polynomial 1: " << endl;
    p2.display();
    cout << endl << endl;
    
    Polynomial p3 = move(p1);
    cout << "Polynomial 3 moved from Polynomial 1: " << endl;
    p3.display();
    
    cout << endl << endl;
    cout << "p3 evaluated at x=2: " << p3.evaluate(2) << endl;
    
    cout << endl << endl;
    
    Polynomial product = p2.multiply(p3);
    cout << "Polynomial after multiplying p2 and p3: " << endl;
    product.display(); 
    
    cout << endl << endl;
    
    Polynomial added = p3.add(p2);
    cout << "Polynomial after adding p2 and p3: " << endl;
    added.display();
	
	return 0;
}
