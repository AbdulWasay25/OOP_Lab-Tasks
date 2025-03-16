#include<iostream>
using namespace std;

class Vehicle{
    float price ;
    public:
    Vehicle(float p) : price(p){}
    float getprice(){return price;}
};

class Car : public Vehicle{
    int seats , doors ;
    string fueltype;
    public:
    Car(float p , int s , int d , string ft):Vehicle(p),seats(s),doors(d),fueltype(ft) {}
    void info(){
        cout<<"Price : "<<getprice()<<"\nNumber of Seats : "<<seats<<"\n Number of Doors : "<<doors<<"\nFuel Type : "<<fueltype;
    }
};

class Mototrcycle : public Vehicle{
    int cylincer , gears , wheels ;
    public:
    Mototrcycle(float p , int c , int g , int w):Vehicle(p),cylincer(c),gears(g),wheels(w) {}
    void info(){
        cout<<"Price : "<<getprice()<<"\nNumber of Cylincers : "<<cylincer<<"\n Number of Gears : "<<gears<<"\nNumber of Wheels :"<<wheels;
    }
};

class Audi : public Car{
    string model ; 
    public:
    Audi(float p , int s , int d , string ft , string m): Car(p , s , d , ft) , model(m){}
    void Displayinfo(){
        info();
        cout<<"\nModel Type : "<<model<<endl;
    }
};

class Yamaha : public Mototrcycle{
    string model ; 
    public:
    Yamaha(float p , int c , int g , int w , string m): Mototrcycle(p , c , g , w) , model(m){}
    void Displayinfo(){
        info();
        cout<<"\nModel Type : "<<model<<endl;
    }
};

int main(){
    Audi A3 = {500000.00 , 5 , 4 , "Hybrid" , "Etron Gt"};
    A3.Displayinfo();
}