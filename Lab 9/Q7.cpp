#include<iostream>
using namespace std;

class Person {
	protected:
		string name;
		int id;
		float salary;
	
	public:
		virtual void getData() {
			cout << "Enter Name: ";
	        cin >> name;
	        cout << "Enter ID: ";
	        cin >> id;
	        cout << "Enter Salary: ";
	        cin >> salary;
		}
		
		virtual void displayData() {
			cout << "Name: " << name << endl; 
			cout << "ID: " << id << endl;
			cout << "Salary: " << salary << endl;
		}
		
		virtual void bonus() {
	        float b = salary * 0.10f; // 10% bonus
	        cout << "Bonus: " << b << endl;
    	}
    	virtual ~Person() {}
};

class Admin : virtual public Person {
	public:
		void getData() override {
			cout << "Enter Data For Admin: " << endl;
			Person::getData();
		}
		void displayData() override {
			cout << " ---- ADMIN DETAILS ---- "<< endl;
			Person::displayData();
		}
		void bonus() override {
	        cout << "[Admin Bonus]\n";
	        float b = salary * 0.15f; // admin gets 15%
	        cout << "Bonus: " << b << endl;
	    }
};

class Account : virtual public Person {
	public:
		void getData() override {
			cout << "Enter Data For Account: " << endl;
			Person::getData();
		}
		
		void displayData() override {
			cout << " ----ACCOUNT DETAILS ---- " << endl;
			Person::displayData();
		}
		void bonus() override {
	        cout << "[Account Bonus]\n";
	        float b = salary * 0.12f; // account gets 12%
	        cout << "Bonus: " << b << endl;
	    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "\n Enter Data for Master" << endl;
        Person::getData(); 
    }

    void displayData() override {
    	cout << " ----MASTER DETAILS ---- " << endl;
        Person::displayData();
    }

    void bonus() override {
        cout << "[Master Bonus]\n";
        float b = salary * 0.20f; // Master gets 20%
        cout << "Bonus: " << b << endl;
    }
};

int main() {
    Person* emp = nullptr;
    int choice;

    cout << "Select Employee Type:\n";
    cout << "1. Admin\n";
    cout << "2. Account\n";
    cout << "3. Master\n";
    cout << "Enter choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        emp = new Admin();
    } else if (choice == 2) {
        emp = new Account();
    } else if (choice == 3) {
        emp = new Master();
    } else {
        cout << "Invalid choice!" << endl;
        return 0;
    }

    emp->getData();
    emp->displayData();
    emp->bonus();

    delete emp; // Free memory
    return 0;
}



