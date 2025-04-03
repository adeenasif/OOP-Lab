#include<iostream>
#include<cmath>
using namespace std;

class Shape {
	protected:
		string color;
		double thickness;  // border Thickness 
		
	public:
		Shape(string c, double t) : color(c), thickness(t) { }
		
		virtual void draw() const = 0;
		virtual double calculateArea() const = 0;
		virtual double calculatePerimeter() const = 0;
		virtual ~Shape() {}
};

class Circle : public Shape {
	float radius;
	
	public:
		Circle (string c, double t, float r) : Shape (c, t), radius(r) { }
		
		void draw() const override {
			cout << "Drawing Circle of radius " << radius << "." << endl;
		}
		double calculateArea() const override {
			return M_PI * radius * radius;
		}
		double calculatePerimeter() const override {
			return 2 * M_PI * radius;
		}
};

class Rectangle : public Shape {
	private:
		double height;
		double width;
	
	public:
		Rectangle (string c, double t, double h, double w) : Shape (c, t), height(h), width(w) { }
		
		void draw() const override  {
			cout << "\nDrawing Rectangle of height " << height << " and width " << width << "." << endl;
		}
		double calculateArea() const override {
			return height * width;
		}
		double calculatePerimeter() const override {
			return 2 * (height + width);
		}
};

class Triangle : public Shape {
	private:
		double a, b ,c; // three sides of triangle
	
	public:
	    Triangle(string c, double t, double s1, double s2, double s3) : Shape(c, t), a(s1), b(s2), c(s3) {}
		
		void draw() const override {
			cout << "\nDrawing Triangle of side 1: " << a << ", side 2: " << b << ", and side 3: " << c << endl;
		}
		double calculateArea() const override {
			double s = (a + b + c) / 2; // semi-perimeter
        	return sqrt(s * (s - a) * (s - b) * (s - c)); 
		}
		double calculatePerimeter() const override {
			return a + b + c;
		}
};

class Polygon : public Shape {
	private:
	    int numSides;
	    double *sideLengths;
	
	public:
	    Polygon(string c, double t, int n, double *lengths) : Shape(c, t), numSides(n) {
	        sideLengths = new double[n];
	        for (int i = 0; i < n; i++) {
	            sideLengths[i] = lengths[i];
	        }
	    }
	
	    void draw() const override {
	        cout << "\nDrawing Polygon with " << numSides << " sides." << endl;
	    }
	
	    double calculateArea() const override {
	        cout << "\nArea calculation depends on the specific type of polygon." << endl;
	        return 0;
	    }
	
	    double calculatePerimeter() const override {
	        double perimeter = 0;
	        for (int i = 0; i < numSides; i++) {
	            perimeter += sideLengths[i];
	        }
	        return perimeter;
	    }
};

int main() {
    Shape *shapes[4];

	double lengths[2] = {2,6};
    shapes[0] = new Circle("Red", 2.5, 5);
    shapes[1] = new Rectangle("Blue", 1.2, 4, 6);
    shapes[2] = new Triangle("Green", 1.0, 3, 4, 5);
	shapes[3] = new Polygon("Black", 2.0, 3, lengths);
    for (int i = 0; i < 4; i++) {
        shapes[i]->draw();
        cout << "\nArea: " << shapes[i]->calculateArea() << endl;
        cout << "Perimeter: " << shapes[i]->calculatePerimeter() << endl;
        cout << "--------------------" << endl;
    }

    // Free allocated memory
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
    }

    return 0;
}
