#include <iostream>
#include <string>

using namespace std;

class Book {
    string name;
    string ISBN;
    string author;
    string publisher;

public:
    string getName() {
        return this->name;
    }

    void setName( string name) {
        this->name = name;
    }

    string getISBN()  {
        return this->ISBN;
    }

    void setISBN( string ISBN) {
        this->ISBN = ISBN;
    }

    string getAuthor()  {
        return this->author;
    }

    void setAuthor( string author) {
        this->author = author;
    }

    string getPublisher()  {
        return this->publisher;
    }

    void setPublisher( string publisher) {
        this->publisher = publisher;
    }

    string getBookInfo()  {
        return "Book Name: " + this->name + "\n" +
               "ISBN Number: " + this->ISBN + "\n" +
               "Author Name: " + this->author + "\n" +
               "Publisher: " + this->publisher;
    }
};

int main(int argc, char* argv[]) {
	int n = (argc-1)/4 ;
    const int numBooks = n;
    Book books[numBooks];
    int argIndex = 1;

    for (int i = 0; i < numBooks; ++i) {
        books[i].setName(*(argv + argIndex++));
        books[i].setISBN(*(argv + argIndex++));
        books[i].setAuthor(*(argv + argIndex++));
        books[i].setPublisher(*(argv + argIndex++));
    }

    int num = 0;
    cout << "Enter Book Number To Be Informed About (1-" << numBooks<<" ): ";
    cin >> num;
    while (num < 1 || num > numBooks) {
        cout << "Wrong Number --- Enter Number Again (1-" << numBooks<<" ): ";
        cin >> num;
    }

    cout << books[num - 1].getBookInfo() << endl;

    return 0;
}
