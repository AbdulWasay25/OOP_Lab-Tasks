#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main(){
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string encrypted;
    for (int i = 0; i < input.length(); i++) {
        encrypted += char(input[i] + (i + 1));
    }

    ofstream outfile("Task1.txt");
    if (outfile.is_open()) {
        outfile << encrypted;
        outfile.close();
        cout << "\nEncrypted text inserted into file." << endl;
    }

    string d;
    ifstream infile("Task1.txt");
    if (infile.is_open()) {
        getline(infile, d);
        infile.close();
    }

    string decrypted;
    for (int i = 0; i < d.length(); i++) {
        decrypted += char(d[i] - (i + 1));
    }

    cout << "\nNormal Text: " << input << endl;
    cout << "Encrypted Text: " << encrypted << endl;
    cout << "Decrypted Text from file: " << decrypted << endl;

    return 0;
}