#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	float weightKG, weightP = 0.0;
	cout<<"Enter weight in kilograms: ";
	cin>>weightKG;
	
	weightP = 2.2 * weightKG;
	
	printf("Weight in kilograms: %.2f\n", weightKG);
	printf("Weight in pounds: %.2f", weightP);
	return 0;
}
