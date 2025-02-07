#include<iostream>

using namespace std;

class User{
	public:
		int Age;
		string Name;
};

int main(int argc, char* argv[]){
	if (argc != 3){
		cout << "MISSING DATA!! Enter first name and age";
		return 1;
	}
	User details;
	
	details.Name = argv[1];
	details.Age = stoi(argv[2]);
	
	cout << "My name is " << details.Name << " and I'm " << details.Age << " years old";
	return 0;
}
