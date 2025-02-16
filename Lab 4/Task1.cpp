#include<iostream>
using namespace std;

class Circle{
	float radius;
	const float PI = 3.14159;
	
	public:
		Circle(float radius){
			this->radius = radius;
		}
		
		float getArea(){
			if (radius < 0){
				radius = 0;
			}
			return PI*radius*radius;
			
		}
		
		float getPerimeter(){
			if (radius < 0){
				radius = 0;
			}
			return 2*PI*radius;
		}
};

int main(int argc, char *argv[]){
	if (argc < 2){
		cout << "MISSING DATA!! Please enter radius!"; 
		return 1;
	}
	
	Circle c(stod(argv[1]));
	float area = c.getArea();
	float circum = c.getPerimeter();
	
	cout << "Area of circle: " << area << endl;
	cout << "Circumference of circle: " << circum << endl;
	
	return 0;
}
