#include<iostream>

using namespace std;

class Book{
	private:
		string name;
		int ISBN;
		string authorName;
		string publisher;
	
	public: 
		void setName(string name){
			this->name = name;
		}
		string getName(){
			return name;
		}
		
		void setISBN(int ISBN){
			this->ISBN = ISBN;
		}
		int getISBN (){
			return ISBN;
		}

		void setAuthor(string authorName){
			this->authorName = authorName;
		}
		string getAuthor(){
			return authorName;
		}
		
		void setPublisher(string publisher){
			this->publisher = publisher;
		}
		string getPublisher(){
			return publisher;
		}
		
		string getBookInfo(){
			return "Book Name: " + name + "\n" +
               "Author Name: " + authorName + "\n" +
               "Publisher: " + publisher + "\n" +
               "ISBN: " + to_string(ISBN) + "\n";
		}
		
};

int main(int agrc, char* argv[]){
	Book BookTest[5];
	
	for (int i = 0; i < 5; i++) {
		string bookName = "", author = "", publisherName = "";
		int isbn = 0;
		
		cout << "Enter Book name: ";
		getline(cin, bookName);
		BookTest[i].setName(bookName);
		
		cout << "Enter Author Name: ";
		getline(cin, author);
		BookTest[i].setAuthor(author);
	
		cout << "Enter Publisher Name: ";
		getline(cin, publisherName);
		BookTest[i].setAuthor(publisherName);	
		
		
		cout << "Enter ISBN Number: ";
		cin >> isbn;
		BookTest[i].setISBN(isbn);
		
		cin.ignore();
		cout<<endl;
	}
	
	for (int i = 0; i < 5; i++) {
        cout << "Info of Book " << i + 1 << ":" << endl;
        cout << BookTest[i].getBookInfo() << endl;
    }
    
	return 0;
}
