#include<iostream>
using namespace std;

class Engine{
		bool isRunning;
		
	public:
		Engine() : isRunning(false){ // default constructor
			cout<<"Engine constructor"<<endl;
		}  
		
		void start(){
			if (!isRunning){
				cout << "Engine started" << endl;
				isRunning = true;	
			} else {
				cout << "Engine already running" << endl;
			}
		}
		
		void stop(){
			if (isRunning){
				cout << "Engine stopped" << endl;
			} else {
				cout << "Engine already stopped" << endl;
			}
		}
		
		~Engine(){
			cout << "Engine destructor called!" << endl;
		}
};

class Car{
	Engine engine;
	
	public:
		Car(){
			cout << "Car constructor called!" << endl;
		}
		
		void startCar(){
			engine.start();
		}
		void stopCar(){
			engine.stop();
		}
		
		~Car(){
			cout << "Car destructor called!" << endl;
		}
};

int main(){
	Car car;
	car.startCar();
	car.stopCar();
	
	return 0;
}
