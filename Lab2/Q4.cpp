#include<iostream>
using namespace std;

struct Employee{
	int employee_id;
	string employee_name;
	int employee_salary;
};

struct Organisation{
	string organisation_name;
	string organisation_number;
	Employee emp; 
};

int main(int argc, char* argv[]){
	struct Organisation org;
	if (argc < 6){
		cout << "MISSING DATA!! Enter Organisation name/num, Emplyee id/full name/salary!!";
		return 1;
	}
	
	org.organisation_name = argv[1];
	org.organisation_number = argv[2];
	org.emp.employee_id = stoi(argv[3]);
	string firstName = argv[4];
	string lastName = argv[5];
	org.emp.employee_name= firstName + " " + lastName;
	org.emp.employee_salary = stoi(argv[6]);
	
	cout << "The size of structure organisation: " << sizeof(Organisation) << endl;
	cout << "Organisation Name: " << org.organisation_name << endl;
	cout << "Organisation Number: " << org.organisation_number << endl;
	cout << "Employee ID: " << org.emp.employee_id << endl;
	cout << "Employee Name: " << org.emp.employee_name << endl;
	cout << "Employee Salary: " << org.emp.employee_salary << endl;
	
	return 0;
}


