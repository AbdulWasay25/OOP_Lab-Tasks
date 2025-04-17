#include<iostream>
using namespace std;

class Car{
    protected:
    string model;
    double price;
    public:
    Car(string m): model(m){}
    void setmodel(string model){
        this->model=model;
    }
    string getModel(){return model;}
    virtual void setprice(double p){
        price = 0.00;
    }
    double getprice(){return price;}
    virtual void display(){
        cout<<model<<endl<<price<<endl;
    }
};

class Color : public Car{
    string color;
    public:
    Color(string m , string cl) : Car(m) , color(cl) {}
    void setcolor(string c){
        color = c;
    }
    string getcolor(){return color;}
    void setprice(double p) override{
        price = p;
    }
    void display() override{
        Car::display();
        cout<<color<<endl;
    }
};

class Company : public Car{
    string company;
    public:
    Company(string m , string cn) : Car(m) , company(cn) {}
    void setcompany(string c){
        company = c;
    }
    string getcompany(){return company;}
    void setprice(double p) override{
        price = p;
    }
    void display() override{
        Car::display();
        cout<<company<<endl;
    }
};

int main(){
    Color c1("Alto" , "Blue");
    Company c2("Alto" , "Suzuki");
    c1.setprice(5000);
    c1.display();
    c2.display();
}