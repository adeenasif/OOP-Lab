#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	int sum = 0;
	int *ptr;
	
	for(int i = 1; i < argc; i++){
		int Num = stof(argv[i]);
        ptr = &Num;
        sum+= *ptr;
	}
	
	cout<<"Sum of all elements: "<<sum;
	
	return 0;
}
