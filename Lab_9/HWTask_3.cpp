#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    int id;
    double salary;
public:
    virtual void getData() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Salary: ";
        cin >> salary;
    }
    virtual void displayData() const {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }
    virtual void bonus() const {
        cout << "Bonus: " << salary * 0.1 << endl;
    }
    virtual ~Person() {}
};

class Admin : virtual public Person {
public:
    void getData() override {
        cout << "--- Admin Data ---" << endl;
        Person::getData();
    }
    void displayData() const override {
        cout << "--- Admin Display ---" << endl;
        Person::displayData();
    }
    void bonus() const override {
        cout << "Admin Bonus: " << salary * 0.15 << endl;
    }
};

class Account : virtual public Person {
public:
    void getData() override {
        cout << "--- Account Data ---" << endl;
        Person::getData();
    }
    void displayData() const override {
        cout << "--- Account Display ---" << endl;
        Person::displayData();
    }
    void bonus() const override {
        cout << "Account Bonus: " << salary * 0.12 << endl;
    }
};

class Master : public Admin, public Account {
public:
    void getData() override {
        cout << "--- Master Data ---" << endl;
        Person::getData(); // Call once due to virtual inheritance
    }
    void displayData() const override {
        cout << "--- Master Display ---" << endl;
        Person::displayData();
    }
    void bonus() const override {
        cout << "Master Bonus: " << salary * 0.2 << endl;
    }
};

int main() {
    Person* p;
    Admin a;
    Account acc;
    Master m;

    cout << "\n--- Using Admin Object ---" << endl;
    p = &a;
    p->getData();
    p->displayData();
    p->bonus();

    cout << "\n--- Using Account Object ---" << endl;
    p = &acc;
    p->getData();
    p->displayData();
    p->bonus();

    cout << "\n--- Using Master Object ---" << endl;
    p = &m;
    p->getData();
    p->displayData();
    p->bonus();

    return 0;
}
