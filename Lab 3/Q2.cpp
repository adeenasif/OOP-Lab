#include<iostream>

using namespace std;

class Date{
	int month;
	int day;
	int year;
	
	public:
		void setMonth(int Month){
			month = Month;
		}
		void setDay(int Day){
			day = Day;
		}
		void setYear(int Year){
			year = Year;
		}
		
		void displayDate(){
			cout << month << "/" << day << "/" << year;
		}
};

int main(int argc, char* argv[]){
	if (argc != 4){
		cout << "MISSING DATA!! Enter month, day, year";
		return 1;
	}
	Date DateTest;
	DateTest.setMonth(stoi(argv[1]));
	DateTest.setDay(stoi(argv[2]));
	DateTest.setYear(stoi(argv[3]));
	DateTest.displayDate();
	
	return 0;
	
}
