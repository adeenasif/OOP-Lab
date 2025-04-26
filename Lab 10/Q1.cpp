#include<iostream>
#include<fstream>
using namespace std;

int main() {
	ofstream file("Test.txt");
	string input;
	cout << "Enter text to encrypt: ";
	getline(cin, input);
	
	file << input << endl;
	file.close();
	
	ifstream fileIn("Test.txt");
	if(!fileIn) {
		cout << "Error: File cannot be found!" << endl;
		return 1;
	}
	
	string line = "";
	int pos = 0;
	char c;
	int n;
	
	while(fileIn.get(c)) {
		n = pos + int(c);
		line += char(n);
		pos++;
	}
	
	fileIn.close();
	
	ofstream outFile("Test.txt", ios::app);
	outFile << line;
	outFile.close();
	
	return 0;
}
