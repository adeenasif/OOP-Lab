#include<iostream>
#include<fstream>
using namespace std;

int main () {
	ofstream file("CRUD.txt");
	string id, name, des;
	int years;
		
    file << "1 Ali manager 3\n";
    file << "2 Adeena developer 1\n";
    file << "3 Sana manager 2\n";
    file << "4 Zain designer 4\n";
	    
	file.close();
		
	// open CRUD.txt to read/search
	ifstream fileIn("CRUD.txt");
	if(!fileIn){
		cerr << "FILE NOT FOUND!!" << endl;
		return 1;
	}

	ofstream tempfile("new.txt");
	while(fileIn >> id >> name >> des >> years) {
		if (des == "manager" && years >= 2) {
			tempfile << id << " " << name << " " << des << " " << years << endl;	
		}
	}
	fileIn.close();
	tempfile.close();
	
	// overwrite CRUD.txt with new.txt data
	ifstream inNew("new.txt");
	ofstream outOriginal("CRUD.txt");  // overwrites the original CRUD.txt
	
	string line;
	while (getline(inNew, line)) {
		outOriginal << line << endl;
	}
	inNew.close();
	outOriginal.close();

    // increment id and years, write to updated.txt
	ifstream inputFile("CRUD.txt");
    ofstream updatedFile("CRUD_updated.txt", ios::app);

    if (!updatedFile) {
        cerr << "Error creating updated.txt.\n";
        return 1;
    }
	string na, iD, de;
	int yers;
	
    while (inputFile >> iD >> na >> de >> yers) {
        int newID = stoi(iD) + 1;
        int newYears = yers + 1;
        updatedFile << newID << " " << na << " " << de << " " << newYears << endl;
    }

    inputFile.close();
    updatedFile.close();
	return 0;
}
