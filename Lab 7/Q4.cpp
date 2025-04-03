#include<iostream>
#include<vector>  
using namespace std;

class Person {
protected:
    string name, id, address, num, email;

public:
    Person(string n, string id, string add, string num, string e) : name(n), address(add), id(id), num(num), email(e) {}

    virtual void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Address: " << address << endl;
        cout << "Phone Number: " << num << endl;
        cout << "Email: " << email << endl;
    }

    virtual void updateInfo(string newAdd, string newNum, string newEmail) {
        address = newAdd;
        num = newNum;
        email = newEmail;
    }

    string getName() const {  
        return name;
    }

    virtual ~Person() {}
};

class Student : public Person {
    vector<string> coursesEnrolled;
    float gpa;
    int year; // enrollment year

public:
    Student(string n, string id, string add, string num, string e, float gpa, int year)
        : Person(n, id, add, num, e), gpa(gpa), year(year) {}

    void enrollCourse(const string& course) {
        coursesEnrolled.push_back(course);
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Enrolled: ";
        for (const auto& course : coursesEnrolled) {
            cout << course << " ";
        }
        cout << "\nGPA: " << gpa << endl;
        cout << "Enrollment Year: " << year << endl;
    }
};

class Professor : public Person {
    string department;
    vector<string> coursesTaught;
    double salary;

public:
    Professor(string n, string i, string a, string phone, string mail, string dept, double sal)
        : Person(n, i, a, phone, mail), department(dept), salary(sal) {}

    void addCourse(const string& course) {
        coursesTaught.push_back(course);
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Courses Taught: ";
        for (const auto& course : coursesTaught) {
            cout << course << " ";
        }
        cout << "\nDepartment: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Staff : public Person {
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string a, string phone, string mail, string dept, string p, double sal)
        : Person(n, i, a, phone, mail), department(dept), position(p), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Position: " << position << endl;
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

class Course {
    string courseId;
    string courseName;
    int credits;
    Professor* instructor;
    string schedule;
    vector<Student*> students;

public:
    Course(string id, string name, int credit, Professor* prof, string sched)
        : courseId(id), courseName(name), credits(credit), instructor(prof), schedule(sched) {}

    void registerStudent(Student* student) {
        students.push_back(student);
    }

    void calculateGrades() {
        cout << "Calculating grades for the course " << courseName << ":\n";
        for (auto student : students) {
            cout << student->getName() << " has a grade of A.\n";  // Assuming grade 'A' for simplicity
        }
    }

    void displayCourseInfo() const {
        cout << "Course ID: " << courseId << endl;
        cout << "Course Name: " << courseName << endl;
        cout << "Credits: " << credits << endl;
        cout << "Instructor: " << instructor->getName() << endl;
        cout << "Schedule: " << schedule << endl;
    }
};

int main() {
    Professor prof("Dr. Shahid", "P001", "Gulistan-e-Johar", "03123456661", "prof.Shahid@nu.edu.pk", "Computer Science", 70000);

    Student student1("Ali", "24K-0876", "DHA Phase 8", "03173422334", "ali@nu.edu.pk", 3.8, 2021);
    student1.enrollCourse("CS101");
    student1.enrollCourse("Math101");

    Student student2("Maira", "24K-0987", "North Nazimabad", "03124539091", "maira@nu.edu.pk", 3.5, 2020);
    student2.enrollCourse("CS102");

    Course course1("CS101", "Introduction to OOP", 3, &prof, "MWF 10:00-11:00");
    Course course2("Math101", "Multivariable Calculus", 4, &prof, "TTh 09:00-10:30");

    course1.registerStudent(&student1);
    course2.registerStudent(&student1);
    course2.registerStudent(&student2);

    prof.displayInfo();
    cout << endl;
    student1.displayInfo();
    cout << endl;
    student2.displayInfo();
    cout << endl;

    course1.displayCourseInfo();
    cout << endl;
	course2.displayCourseInfo();

    cout << endl;
	course1.calculateGrades();
    cout << endl;
	course2.calculateGrades();

    return 0;
}

