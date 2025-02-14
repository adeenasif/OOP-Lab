#include <iostream>
using namespace std;

class Polynomial {
private:
    double* coefficients;
    int degree;  

public:
    Polynomial() : degree(0) {
        coefficients = new double[1]{0};
    }

    Polynomial(int deg, const double* coeff) : degree(deg) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeff[i];
        }
    }

    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    // Move constructor
    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.coefficients = nullptr;
        other.degree = 0;
    }

    // Destructor
    ~Polynomial() {
        delete[] coefficients;
    }

    int getDegree() const {
        return degree;
    }

    //evaluate the polynomial
    double evaluate(double x) const {
        double result = 0;
        double xPower = 1;

        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * xPower;
            xPower *= x;
        }

        return result;
    }

    // add another polynomial to the current one
    Polynomial add(const Polynomial& other) const {
        int maxDegree = (degree > other.degree) ? degree : other.degree;
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

    // multiply another polynomial with the current one
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
            if (i < degree && coefficients[i] >= 0) {
                cout << "+";
            }
            cout << coefficients[i];
            if (i > 0) {
                cout << "x^" << i << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    double coeffs1[] = {3, -3, 2, 1}; 
    Polynomial p1(3, coeffs1);
    p1.display();

    double coeffs2[] = {3, 2};  
    Polynomial p2(1, coeffs2);
    p2.display();

    Polynomial sum = p1.add(p2);
    sum.display();
    
    Polynomial product = p1.multiply(p2);
    product.display(); 
    
    cout << "p1 evaluated at x=2: " << p1.evaluate(2) << endl;
    return 0;
}
