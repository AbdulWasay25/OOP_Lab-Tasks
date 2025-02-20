#include <iostream>
#include <string>

using namespace std;

class Book {
    public:
        string author;
        string title;
        string publisher;
        int quantity;
        double price;
};

int main(int argc, char* argv[]) {
    int n = (argc - 1) / 5;
    Book books[n];
    int j = 1;
    for (int i = 0; i < n; i++) {
        books[i].author = *(argv + j); j++;
        books[i].title = *(argv + j); j++;
        books[i].publisher = *(argv + j); j++;
        books[i].quantity = stoi(*(argv + j)); j++;
        books[i].price = stod(*(argv + j)); j++;
    }
    
    string a, t; 
    int rc;
    cout << "Enter Book Author And Title of Book: ";
    cin >> a >> t;
    
    for (int i = 0; i < n; i++) {
        if (strcmp(a.c_str(), books[i].author.c_str()) == 0 && strcmp(t.c_str(), books[i].title.c_str()) == 0) {
            cout << "Book Available" << endl 
                 << "Published by: " << books[i].publisher << endl 
                 << "Available Copies: " << books[i].quantity << endl 
                 << "Price: " << books[i].price << endl;
            
            cout << "Enter required Copies: ";
            cin >> rc;
            
            if (rc <= books[i].quantity) {
                int total = rc * books[i].price;
                cout << "Total Bill = " << total;
            } else {
                cout << "Required Quantity Not In Stock";
            }
        }
    }
    return 0;
}
