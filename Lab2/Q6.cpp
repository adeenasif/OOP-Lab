#include<iostream>
#include<vector>

using namespace std;

struct Subject{
	string subject;
};

struct Students{
	int ID;
	Subject sub[3];
};

int main(int argc, char* argv[]){
	if (argc < 2) {
        cout << "MISSING DATA!! Please enter the number of students!";
        return 1;
    }
    
	int N = stoi(argv[1]); // N is the num of students
	
	vector<Students> student(N);
	
	for(int i = 0; i < N; i++){
		student[i].ID = i+1;
		student[i].sub[0].subject = "Science";
		student[i].sub[1].subject = "Calculus";
		student[i].sub[2].subject = "OOP";
	}
	
	  for (const auto& Students : student) {
        cout << "Student ID: " << Students.ID << "\nSubjects:\n";
        for (int j = 0; j < 3; j++) {
            cout << " " << j+1 << ". " << Students.sub[j].subject << "\n";
        }
        cout << "\n";
    }
	
	return 0;
}
