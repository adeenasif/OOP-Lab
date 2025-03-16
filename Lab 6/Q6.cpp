#include<iostream>
using namespace std;

class Student{
	protected:
		int id;
		string name;
	public:
		Student(int ID, string n) {
			id = ID;
			name = n;
		}
		void getStudentDetails(){
			cout << " ID: " << id << endl;
			cout << " Name: " << name << endl;
		}
};

class Marks : public Student {
	protected:
		int marks_oop, marks_pf, marks_db, marks_ds;

	public:
		Marks(int ID, string n, int oop, int pf, int db, int ds) : Student (ID, n) {
			marks_oop = oop;
			marks_pf = pf;
			marks_db = db;
			marks_ds = ds;
		}
		void getMarks() {
			cout << " OOP: " << marks_oop << endl;
			cout << " PF: " << marks_pf << endl;
			cout << " DB: " << marks_db << endl;
			cout << " DS: " << marks_ds << endl;
		}
};

class Result : public Marks {
	protected:
		int totalMarks;
		double avg_marks;
		
		public:
			Result(int ID, string n, int oop, int pf, int db, int ds) : Marks(ID, n, oop, pf, db, ds) {
				totalMarks = 0;
				avg_marks = 0;
			}
			void calcTotal () {
				totalMarks += marks_oop + marks_pf + marks_db + marks_ds;
			}
			void calcAvg (){
				avg_marks = totalMarks/4;
			}
			void display() {
				cout << "---- Student Details ----" << endl;
				getStudentDetails();
				cout << "\n--------- Marks ---------" << endl;
				getMarks();
				cout << "\n Total Marks: " << totalMarks << endl;
				cout << " Average Marks: " << avg_marks << endl;
			}	
};

int main() {
	Result r(23, "Adeena", 18, 19, 17, 19);
	r.calcTotal();
	r.calcAvg();
	r.display();
	return 0;
}
