#include<iostream>
using namespace std;

class Books{
	string author;
	string title;
	double price;
	string publisher;
	int stock;
	
	public:
		Books(){  // default constructor
			author = "";
			title = "";
			price = 0.0;
			publisher = "";
			stock = 0;
		}
		Books(string author, string title, double price, string publisher, int stock){ // parametrized
			this->author = author;
			this->title = title;
			this->price = price;
			this->publisher = publisher;
			this->stock = stock;
		}
		
		string getAuthor() const {
			return author;
		}
		string getTitle() const {
			return title;
		}
		string getPublisher() const {
			return publisher;
		}
		double getPrice() const {
			return price;
		}
		int getStock() const {
			return stock;
		}
		
		void search(int req) const{
			if (req <= stock){
				double TotalCost = price * req;
				cout << "\nRequired copies are available!" << endl;
				cout << "Total cost for " << req << " copies: $" << TotalCost << endl;
			} else {
				cout << "Required copies not in stock." << endl;
			}
		}
		
		~Books(){
			
		}
};

int main(){
	Books inventory[] = {
		Books("Harper Lee", "To Kill a Mockingbird", 7.99, "J.B. Lippincott", 15),
		Books("J.K Rowling", "Harry Potter and the goblet of fire", 10.0, "Bloomsbury", 10),
		Books("J.R.R. Tolkien", "The Hobbit", 14.95,  "Allen & Unwin", 5)
	};
	
    int numOfBooks = sizeof(inventory) / sizeof(inventory[0]);
	
	char choice;
	do{
		string bookName, authorName;
		cout << "Enter book name: ";
		getline(cin, bookName);
		cout << "Enter author name: ";
	    getline(cin, authorName);
		
		bool found = false;
		for (int i = 0; i < numOfBooks; i++){
			if(inventory[i].getTitle() == bookName && inventory[i].getAuthor() == authorName){
				found = true;
				cout << "Book Author: " << inventory[i].getAuthor() << endl;
				cout << "Book Title: " << inventory[i].getTitle() << endl;
				cout << "Price: " << inventory[i].getPrice() << endl;
				cout << "Publisher: " << inventory[i].getPublisher() << endl;	
			
				int req;
				cout << "Enter required copies: ";
				cin >> req;
				inventory[i].search(req);
				break;
			} 
		}
		if (!found){
			cout << "Book not available!" << endl;
		}
		
		cout << "Do you want another book? (y for yes or n for no): ";
		cin >> choice;
		cin.ignore();
		
	} while (choice == 'y' || choice == 'Y');
	
	cout << "\nBye Bye!\n";
	
	return 0;
}
