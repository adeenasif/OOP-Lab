#include <iostream>
#include <vector>
using namespace std;

class Media {
protected:
    string title, publicationDate, uniqueID, publisher;
    bool isAvailable;

public:
    Media(string t, string date, string id, string pub) : title(t), publicationDate(date), uniqueID(id), publisher(pub), isAvailable(true) {}

    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
        cout << "Publication Date: " << publicationDate << endl;
        cout << "Unique ID: " << uniqueID << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Checked Out") << endl;
    }

    void checkOut() {
        if (isAvailable) {
            isAvailable = false;
            cout << title << " has been checked out." << endl;
        } else {
            cout << title << " is currently unavailable." << endl;
        }
    }

    void returnItem() {
        if (!isAvailable) {
            isAvailable = true;
            cout << title << " has been returned." << endl;
        } else {
            cout << title << " was not checked out." << endl;
        }
    }

    string getTitle() const { return title; }
    string getPublicationDate() const { return publicationDate; }
    
    virtual ~Media() {}
};

class Book : public Media {
private:
    string author, isbn;
    int numberOfPages;

public:
    Book(string t, string date, string id, string pub, string a, string i, int pages)
        : Media(t, date, id, pub), author(a), isbn(i), numberOfPages(pages) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Number of Pages: " << numberOfPages << endl;
    }

    string getAuthor() const { return author; }
};

class DVD : public Media {
private:
    string director;
    int duration;  
    string rating;

public:
    DVD(string t, string date, string id, string pub, string dir, int dur, string rate)
        : Media(t, date, id, pub), director(dir), duration(dur), rating(rate) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Director: " << director << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "Rating: " << rating << endl;
    }
};

class CD : public Media {
private:
    string artist;
    int numberOfTracks;
    string genre;

public:
    CD(string t, string date, string id, string pub, string art, int tracks, string gen)
        : Media(t, date, id, pub), artist(art), numberOfTracks(tracks), genre(gen) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Artist: " << artist << endl;
        cout << "Number of Tracks: " << numberOfTracks << endl;
        cout << "Genre: " << genre << endl;
    }
};

class Magazine : public Media {
private:
    int issueNumber;
    string frequency;

public:
    Magazine(string t, string date, string id, string pub, int issue, string freq)
        : Media(t, date, id, pub), issueNumber(issue), frequency(freq) {}

    void displayInfo() const override {
        Media::displayInfo();
        cout << "Issue Number: " << issueNumber << endl;
        cout << "Frequency: " << frequency << endl;
    }
};

class Library {
private:
    vector<Media*> collection;

public:
    void addMedia(Media* media) {
        collection.push_back(media);
    }

    void searchByTitle(const string& searchTitle) {
        cout << "\nSearching for media with title: " << searchTitle << endl;
        bool found = false;
        for (const auto& item : collection) {
            if (item->getTitle() == searchTitle) {
                item->displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "No media found with title: " << searchTitle << endl;
        }
    }

    void searchByPublicationYear(const string& year) {
        cout << "\nSearching for media published in: " << year << endl;
        bool found = false;
        for (const auto& item : collection) {
            if (item->getPublicationDate() == year) {
                item->displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "No media found from year: " << year << endl;
        }
    }

    void searchByAuthor(const string& author) {
        cout << "\nSearching for books by: " << author << endl;
        bool found = false;
        for (const auto& item : collection) {
            Book* book = dynamic_cast<Book*>(item);
            if (book && book->getAuthor() == author) {
                book->displayInfo();
                found = true;
            }
        }
        if (!found) {
            cout << "No books found by author: " << author << endl;
        }
    }
};

int main() {
    Library library;
    
    Book book("The Great Gatsby", "1925-04-10", "B001", "Scribner", "F. Scott Fitzgerald", "9780743273565", 180);
    DVD dvd("Inception", "2010-07-16", "D001", "Warner Bros", "Christopher Nolan", 148, "PG-13");
    CD cd("Abbey Road", "1969-09-26", "C001", "Apple Records", "The Beatles", 17, "Rock");
    Magazine mag("Time", "2022-12-15", "M001", "Time Inc.", 100, "Weekly");

    library.addMedia(&book);
    library.addMedia(&dvd);
    library.addMedia(&cd);
    library.addMedia(&mag);

    for (auto& item : {&book, &dvd, &cd, &mag}) {
        item->displayInfo();
        cout << endl;
    }

    book.checkOut();
    book.returnItem();

    library.searchByTitle("Inception");
    library.searchByPublicationYear("1969");
    library.searchByAuthor("F. Scott Fitzgerald");

    return 0;
}

