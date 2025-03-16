#include<iostream>
using namespace std;

class Vehicles {
	protected:
		double price;
	public:
		Vehicles(double p) {
			price = p;
		}
		virtual void display() = 0;
		virtual ~Vehicles(){}
};

class Car : public Vehicles {
	int capacity; // seating capacity
	int doorCount;
	string fuelType; // diesel or petrol
	
	public:
		Car(double p, int c, int dc, string ft) : Vehicles(p) {
			capacity = c;
			doorCount = dc;
			fuelType = ft;
		}
		void displayCar() {
			cout << "Price: " << price << endl;		
			cout << "Seating Capacity: " << capacity << endl;		
			cout << "Number of doors: " << doorCount << endl;		
			cout << "Fuel Type: " << fuelType << endl;		
		}
};

class Motorcycle : public Vehicles {
	int cylinderCount;
	int gearCount;
	int wheelCount;
	
	public:
		Motorcycle(double p, int c, int g, int w) : Vehicles(p) {
			cylinderCount = c;
			gearCount = g;
			wheelCount = w;
		}
		void displayBike() {
			cout << "Price: " << price << endl;		
			cout << "Number of Cylinders: " << cylinderCount << endl;		
			cout << "Number of Gears: " << gearCount << endl;		
			cout << "Number of Wheels: " << wheelCount << endl;		
		}
};

class Audi : public Car {
	string modelType;
	public:
		Audi(double p, int c, int dc, string ft, string m) : Car(p, c, dc, ft) {
			modelType = m;
		}
		void display() override {
			Car::displayCar();
			cout << "Model Type: " << modelType << endl;
		}
};

class Yamaha : public Motorcycle {
	string makeType;
	public:
		Yamaha(double p, int c, int g, int w, string m) : Motorcycle(p, c, g, w){
			makeType = m;
		}
		void display() override {
			Motorcycle::displayBike();
			cout << "Model Type: " << makeType << endl;
		}
};

int main() {
	Audi audi(123467.23, 5, 4, "petrol", "23da");
	cout << "---- Audi Details ----" << endl;
	audi.display();
	
	cout << "\n\n---- Yamaha Details -----" << endl;
	Yamaha yamaha(9876, 1, 2, 2, "23d");
	yamaha.display();
	return 0;
}
