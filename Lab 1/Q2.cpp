#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	int sum = 0;
	for(int i = 0; i < argc; i++){
		sum += stoi(argv[i]);
	}
	cout<<"Sum of all elements: "<<sum;
	return 0;
}
