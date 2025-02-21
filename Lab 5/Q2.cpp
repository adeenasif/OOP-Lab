#include<iostream>
#include<vector>
using namespace std;

class Car{
	string name;
	int id;
	
	public:
		Car(){  // default
			
		}
		
		Car(string name, int id){
			this->name = name;
			this->id = id;
		}
		
		void display() const{
			cout << "Car name : " << name << endl;
			cout << "Car ID : " << id << endl;
		}
		
		~Car(){  // destructor
			cout << "Car destructor called" << endl;
		}
};

class Garage{
		vector<Car*> car;
		
	public:
		Garage(){
			cout << "Garage constructor called" << endl;
		}
		
		void parkCar(Car* c){
			car.push_back(c);
		} 
		
		void listCars() const{
			for (auto info:car) {
				info->display();
			}
		}
		
		~Garage(){
        cout << "Garage destructor called" << endl;
    }
};

int main(){
	Car car1("Civic", 23);
	Car car2("City", 24);
	Car car3("Vigo", 25);
	Garage garage;
	
	garage.parkCar(&car1);
	garage.parkCar(&car2);
	garage.parkCar(&car3);
	garage.listCars();
	return 0;
}
