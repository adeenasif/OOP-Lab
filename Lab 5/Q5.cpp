#include<iostream>
using namespace std;

class Car{
	public:	
		mutable int horsePower;
		mutable int capacity;  //  seating_capacity
		mutable int num;  // num of speakers
/*	
using mutable as the values of public non-constant attributes 
can't directly be changed within a constant function.
the setters can also not update as they are not constant
*/
		Car(int power, int cap, int no) : horsePower(power), capacity(cap), num(no){}
		
		void update(int power, int cap, int number) const {
            horsePower = power;
            capacity = cap;
            num = number;
        }
        
		void display() const {
			cout << "Car horsepower: " << horsePower << endl;
			cout << "Car Capacity: " << capacity << endl;
			cout << "Number of speakers: " << num << endl;
		}
};

int main(){
	int power, number, capacity;
	cout << "Enter horsepower : ";
	cin >> power;
	cout << "Enter car capacity : ";
	cin >> capacity;
	cout << "Enter number of speakers : ";
	cin >> number;
	
	Car car1(power, capacity, number);
	cout << endl << endl;
	cout << "Before changing values: " << endl;
	car1.display();
	
	cout << endl << endl;
	
	cout << "After updating values: " << endl;
	car1.update(12,23,2);
	car1.display();
	
	return 0;
}
