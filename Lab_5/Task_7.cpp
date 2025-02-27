#include <iostream>
using namespace std;

class Student {
    const int roll_no;
    string name;
public:
    Student(int roll, string n) : roll_no(roll), name(n) {}
    void display() const {
        cout << "\nStudent Name: " << name;
        cout << "\nRoll Number: " << roll_no << endl;
    }
};

int main() {
    int rollno;
    string name;
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> rollno;
    Student student(rollno, name);
    student.display();
    return 0;
}