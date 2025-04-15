#include<iostream>
using namespace std;

class Shape {
	public:
		virtual double getArea() = 0;
		virtual ~Shape () {}
};

class Rectangle : public Shape {
	private:
		double width, length;
	public:
		Rectangle(double w, double l) {
			width = w;
			length = l;
		}
		double getArea() override {
			return width * length;
		} 
};

class Triangle : public Shape {
	private:
		double base, height;
	public:
		Triangle(double b, double h) {
			base = b;
			height = h;
		}
		double getArea() override {
			return 0.5 * base * height;
		}
};

int main() {
	Rectangle r(12.5, 10.0);
	Triangle t(5.0, 10.0);
	
	cout << "Area of Rectangle: " << r.getArea() << endl;
	cout << "Area of Triangle: " << t.getArea();
	return 0;
}
