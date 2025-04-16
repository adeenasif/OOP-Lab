#include<iostream>
using namespace std;

class Car {
	private:
		string model;
		double price;
		
	public:
		Car(string m, double p) : model(m), price(p) { }
		
		void setModel (string m) {
			model = m;
		}
		virtual void setPrice (double p) = 0;
		
		string getModel () {
			return model;
		}
		double getPrice () {
			return price;
		}
		virtual void displayInfo () {
			cout << " Car Model: " << model << endl;
			cout << " Price: $" << price << endl;
		}
		
		virtual ~Car() { }
	
	protected:
    	void updatePrice(double p) {
        	price = p;
    	}
};

class Color : public Car {
	private:
		string color;
		
	public:
		Color(string m, double p, string c) : Car(m, p){
			color = c;
		}
		
		void setPrice(double p) override {
			updatePrice(p);
		}
		
		void displayInfo () override {
			Car::displayInfo();
			cout << " Color: " << color << endl;
		}
};

class Company : public Car {
	private:
		string company;
		
	public:
		Company(string m, double p, string c) : Car(m, p){
			company = c;
		}
		void setPrice(double p) override {
			updatePrice(p);
		}
		void displayInfo () override {
			Car::displayInfo();
			cout << " Company: " << company << endl;
		}
};

int main() {
    Color car1("Civic", 25000, "White");
    Company car2("Model S", 80000, "Tesla");

    car1.setPrice(26000);   
    car2.setPrice(82000);   

    cout << " ----- Color Car Info ----- " << endl;
    car1.displayInfo();
    cout << endl;

    cout << "\n ----- Company Car Info ----- " << endl;
    car2.displayInfo();
    
    return 0;
}
