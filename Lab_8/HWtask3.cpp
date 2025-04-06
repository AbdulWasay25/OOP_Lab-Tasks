#include<iostream>
#include<string>
using namespace std;

class Person{
    protected:
    string EmpID;
    public:
    //Person(string id) : EmpID(id) {}
    virtual void getData(){
        cout<<"Enter Employee ID"<<endl;
        cin>>EmpID ;
    }
    virtual void displaydata(){cout<<"Employee ID = "<<EmpID<<endl;}
};

class Admin : public Person{
    string name;
    double income;
    public:
    void getData()override{
        Person::getData();
        cout<<"Enter Admin Name : ";
        cin.ignore();
        getline(cin , name);
        cout<<"\nEnter Salary : ";cin>>income;
        cout<<endl;
    }
    float bonus(){
        return 0.05*12*income ;
    }
    void displaydata() override{
        Person ::displaydata();
        cout<<"Name : "<<name<<"\nMonthly Income : "<<income<<"\nAnnual Bonus : "<<bonus()<<endl;
    }
};

class Account : public Person{
    string name;
    double income;
    public:
    void getData()override{
        Person::getData();
        cout<<"Enter Accountant Name : ";
        cin.ignore();
        getline(cin , name);
        cout<<"\nEnter Salary : ";cin>>income;
        cout<<endl;
    }
    float bonus(){
        return 0.05*12*income ;
    }
    void displaydata() override{
        Person ::displaydata();
        cout<<"Name : "<<name<<"\nMonthly Income : "<<income<<"\nAnnual Bonus : "<<bonus()<<endl;
    }
};

int main(){
    Admin a ;
    Account acc;
    a.getData();
    a.displaydata();
    

}