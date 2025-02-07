#include<iostream>

using namespace std;

class Employee{
	private:
		double salary;
		
	public:
		string firstName;
		string lastName;
		
		double setSalary(double sal){
			if (sal < 0){
				sal = 0;
			} else {
				salary = sal;
			}
			return salary;
		}
};


int main(int argc, char* argv[]){
	if (argc != 7){
		cout << "MISSING DATA!! please enter full name and salaray for 2 employees!";
		return 1;
	}
	Employee EmployeeTest[2];
	
	EmployeeTest[0].firstName = argv[1];
	EmployeeTest[0].lastName = argv[2];
	EmployeeTest[0].setSalary(stod(argv[3]));
	
	double salary1 = 12 * EmployeeTest[0].setSalary(stod(argv[3]));
	
	EmployeeTest[1].firstName = argv[4];
	EmployeeTest[1].lastName = argv[5];
	EmployeeTest[1].setSalary(stod(argv[6]));
	
	double salary2 = 12 * EmployeeTest[1].setSalary(stod(argv[6]));
	
	cout << "Yearly Salary of " << EmployeeTest[0].firstName << " is " << salary1 << endl;
	cout << "Yearly Salary of " << EmployeeTest[1].firstName << " is " << salary2 << endl;
	
	cout << "\nBonus: " << endl;
	
	cout << "Salary of employee 1 after adding bonus: " << salary1 + (0.1*salary1) << endl;
	cout << "Salary of employee 2 after adding bonus: " << salary2 + (0.1*salary2) << endl;
	
	return 0;
}
