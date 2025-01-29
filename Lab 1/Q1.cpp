#include<iostream>
using namespace std;

int main(int argc, char* argv[]){
	float highest = stof(argv[1]);
	float SecHighest = 0;
		
	if(argc != 21){
		cout << "Enter 20 elements!!";
		return 1;
	} 
	for(int i = 2; i < argc; i++){
		if(stof(argv[i]) > highest){
			SecHighest = highest;
			highest = stof(argv[i]);
		}
		if (stof(argv[i]) != highest && stof(argv[i]) > SecHighest){
			SecHighest = stof(argv[i]);
		}
	}
	cout<<"Second Highest = "<<SecHighest;
		
	return 0;
}
