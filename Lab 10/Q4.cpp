#include<iostream>
#include<fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

const string logger = "log.txt";
int count = 1;  

void checkSize() {
	if (fs::exists(logger)) {
		auto size = fs::file_size(logger);
		if (size > 1048576) { // 1MB = 1024 * 1024 bytes
	    	string newFile;
		    do {
		        newFile = "log" + to_string(count++) + ".txt";
	        } while (fs::exists(newFile));
	
	        fs::rename(logger, newFile);
    	}
	}

}
// Write a single log line
void writeLog(const string& message) {
    checkSize();

    ofstream outFile(logger, ios::app);
    if (!outFile) {
        cerr << "Failed to open log file.\n";
        return;
    }

    outFile << message << endl;
    outFile.close();
}

int main() {
   	for (int i = 0; i < 100000; ++i) {
        writeLog("Log entry number: " + to_string(i));
    }
    return 0;
}
