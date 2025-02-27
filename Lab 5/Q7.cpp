#include<iostream>
using namespace std;

class Student{
	string name;
	const string roll_no;
	
	public:
		Student(string num, string name) : roll_no(num){
			this->name = name;
		}
		
		void display() const {
			cout << "Name: " << name << endl;
			cout << "Roll Number: " << roll_no << endl;
		}
};

int main(){
	string rollNum;
	cout << "Enter roll number: ";
	cin >> rollNum;
	
	string name;
	cout << "Enter name: ";
	cin.ignore();
	getline(cin, name);
	
	
	Student s1(rollNum, name);
	s1.display();
	
	return 0;
}
