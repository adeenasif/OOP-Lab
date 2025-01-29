#include<iostream>
#include<strings.h>
using namespace std;

int main(){
	string name;
	float adultTicket, childTicket, grossAmount, donated, netSale, percentage;
	int ticketsSold, NoOfAdults, NoOfChild; 
	
	cout << "Enter movie name: ";
	getline(cin, name);
	cout << "Enter adult ticket price: ";
	cin >> adultTicket;
	cout << "Enter child ticket price: ";
	cin >> childTicket;
	cout << "Enter number of adults tickets sold: ";
	cin >> NoOfAdults;
	cout <<"Enter number of child tickets sold: ";
	cin >> NoOfChild;
	cout << "Enter percentage of gross amount to be donated to the charity: ";
	cin >> percentage;
	
	ticketsSold = childTicket + adultTicket;
	grossAmount = (NoOfAdults * adultTicket) + (NoOfChild * childTicket);
	donated = grossAmount * (percentage/100);
	netSale = grossAmount - donated;
	
	
	cout << "Movie Name: ........... " << name << endl;
	cout << "Number of tickets sold: ..........." << ticketsSold << endl;
 	printf("Gross Amount: ........... $ %.2f", grossAmount);
    printf("\nPercentage of Gross Amount Donated: %.2f %", percentage);
    printf("\nAmount Donated: ........... $ %.2f", donated);
    printf("\nNet Sale: ........... $ %.2f", netSale);

	return 0;
}
