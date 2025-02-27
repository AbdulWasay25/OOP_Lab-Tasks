#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Catalog {
    vector<string> ISBN;      
    vector<string> locations; 
    
public:
    void addISBN(string s, string l) {
        ISBN.push_back(s);         
        locations.push_back(l);    
        cout << "\nISBN Added: " << s << " At Location " << l;
    }

    string getLocation(string isbn) {
        for (size_t i = 0; i < ISBN.size(); ++i) {
            if (isbn == ISBN[i]) {
                return locations[i];
            }
        }
        return "ISBN not found"; 
    }
};

class Book {
    string title;
    string author;
    string isbn;

public:
    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    string getISBN() const {
        return isbn;
    }
};

class Library {
    Catalog catalog; 
    vector<Book> books; 

public:
    void addBook(const Book& book, string location) {
        catalog.addISBN(book.getISBN(), location); 
        books.push_back(book); 
    }

    void searchBookByISBN(string isbn) {
        string location = catalog.getLocation(isbn);
        if (location != "ISBN not found") {
            cout << "Book found at location: " << location << endl;
        } else {
            cout << "Book with ISBN " << isbn << " not found in the catalog." << endl;
        }
    }

    void printLibraryBooks() {
        for (const auto& book : books) {
            cout << "Book: " << book.getTitle() << ", Author: " << book.getAuthor() << ", ISBN: " << book.getISBN() << endl;
        }
    }
};

int main(int argc , char* argv[]) {
    Library myLibrary;

    Book book1(*(argv + 1), *(argv + 2), *(argv + 3));
    Book book2(*(argv + 5), *(argv + 6), *(argv + 7));

    myLibrary.addBook(book1, *(argv + 4));
    myLibrary.addBook(book2, *(argv + 8));

    cout << "\nBooks in the library:\n";
    myLibrary.printLibraryBooks();
	cout<<"Enter ISBN for Searching Book : "<<endl;
	string searchisbn;
	cin>>searchisbn ;
    myLibrary.searchBookByISBN(searchisbn);


    return 0;
}