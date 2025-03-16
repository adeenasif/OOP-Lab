#include<iostream>
using namespace std;

class Books {
	protected:
		string genre;
	public:
		Books(string gen){
			genre = gen;
		}
		virtual void display() = 0;
		virtual ~Books(){}
};

class Horror : public Books {
	string title;
	string author;
	public:
		Horror(string genre, string t, string a) : Books(genre){
			title = t; 
			author = a;
		}
		void display() override {
			cout << "Genre: " << genre << endl;
			cout << "Title: " << title << endl;
			cout << "Author: " << author << endl;
		}
};

class Mystery : public Books {
	string title;
	string author;

	public:
		Mystery(string genre, string t, string a) : Books(genre){
			title = t; 
			author = a;
		}
		void display() override {
			cout << "Genre: " << genre << endl;
			cout << "Title: " << title << endl;
			cout << "Author: " << author << endl;
		}
};

int main() {
	Horror h("Horror", "We used to live here", "Marcus Kliewer");
	Mystery m("Mystery", "Gone Girl", "Gillian Flynn");
	
	h.display();
	cout << endl;
	m.display();
	
	return 0;
}
