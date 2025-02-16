#include<iostream>
using namespace std;

class Invoice{
	string partNum;
	string partDesc;
	int quantity;
	double price; // price per item
	
	public:
		Invoice(string partNum, string partDesc, int quantity, double price){
			this->partNum = partNum;
			this->partDesc = partDesc;
			this->quantity = quantity;
			this->price = price;
		}
		
		double getInvoiceAmount(){
			if (quantity < 0 && price < 0){
				quantity = 0;
				price = 0.0;
			}
			return quantity*price;
		}
};

int main(int argc, char *argv[]){
	if (argc < 5){
		cout << "MISSING DATA!! Please enter Number, Description, Quantity and Price of Part! ";
		return 1;
	}
	
	Invoice in(argv[1], argv[2], stoi(argv[3]), stod(argv[4]));
	
	double amount = in.getInvoiceAmount();
	cout << "Invoice Amount = " << amount << endl;
	
	return 0;
}
