#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	string firstName = argv[1];
	string lastName = argv[2];
	float sum = 0.0;
	int count = 0;
	
	cout << "Student Name: " << firstName << " "<< lastName << endl;
	
	cout << "Test Scores: ";
	for(int i = 3; i < argc; i++){
		count++;
		sum += stof(argv[i]);
		printf("%.2f ", stof(argv[i]));
	}
	printf("COUNT: %d", count);
	
	float avgScore = sum/count;
	printf("\nAverage test score: %.2f", avgScore);

	return 0;
}
