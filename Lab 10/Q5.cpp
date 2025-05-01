#include<iostream>
#include<fstream>
using namespace std;

void addText(){
	ofstream file("list.txt", ios::app);
	string text;
	
	cout << "enter text to add in file: ";
	getline(cin, text);
	
	file << "[ ]" << text << endl;
	file.close();
}

void viewTasks() {
	string line;
	int index = 1;
	
	ifstream file("list.txt");
	
	cout << "---- TASKS -----" << endl;
	while (getline(file, line)) {
		cout << index++ << ". " << line << endl;
	}
	file.close();
}

void markDone () {
    ifstream inFile("list.txt");
    ofstream tempFile("temp.txt");
    string line;
    int lineNum = 1, target;

    // First, show tasks to the user
    viewTasks();

    cout << "Enter task number to mark as done: ";
    cin >> target;

    // Reset file read position to start
    inFile.clear();
    inFile.seekg(0);

    while (getline(inFile, line)) {
        if (lineNum == target) {
            if (line.substr(0, 3) == "[ ]") {
                line.replace(0, 3, "[x]");
                cout << "Task marked as done.\n";
            } else {
                cout << "Task is already marked as done.\n";
            }
        }
        tempFile << line << endl;
        lineNum++;
	}

    inFile.close();
    tempFile.close();

    // Replace original file with updated file
    remove("list.txt");
    rename("temp.txt", "list.txt");
}

int main() {
	int choice;
	do {
		cout << "\n1. Add Tasks" << endl;
		cout << "2. View Tasks" << endl;
		cout << "3. Mark as done Tasks" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		if (choice == 1){
			addText();
		} else if (choice == 2) {
			viewTasks();
		} else if (choice == 3) {
			markDone();
		} else if (choice == 4) {
			cout << "Exiting" << endl;
		} else {
			cout << "INVALID CHOICE!!" << endl;
		}
	} while (choice != 4);
	
	return 0;
}
