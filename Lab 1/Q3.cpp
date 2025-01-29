#include<iostream>
#include<strings.h>
using namespace std;

int main(int argc, char* argv[]){
	int amount;
	int surcharge = 0;
	if(argc < 3){
		cout<<"Data missing!! Please enter ID, name and units consumed!";
	}
	float unit;
	float newAmount =0;
	int id = stoi(argv[1]);
	string name = argv[2];
	int units = stoi(argv[3]);
	
	if (units <= 199){
		unit = 16.20;
		amount =  unit * units;
	} else if (units >= 200 && units < 300){
		unit = 20.10;
		amount =  unit * units;
	} else if (units >= 300 && units < 500){
		unit = 27.10;
		amount = unit * units;
	} else {
		unit = 35.90;
		amount = unit * units;
	}
	
	if (amount > 18000){
		surcharge = amount*0.15;
		newAmount = amount + surcharge;
	}
	
	cout << "Customer ID : " << id << endl;
	cout << "Customer Name : " << name << endl;
	cout << "Units Consumed : " << units << endl;
	printf("Amount Charges @Rs. %.2f per unit: %d\n", unit,  amount);
	cout << "Surcharge Amount = " << surcharge << endl; 
	printf("Net Amount Paid by the Customer: %.2f", newAmount);
	return 0;
}





