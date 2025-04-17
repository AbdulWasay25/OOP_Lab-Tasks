#include<iostream>
using namespace std;

class Shape{
    public:
    virtual double getArea() = 0;
};

class Rectangle : public Shape{
    double length;
    double width;
    public:
    void setvalues(double l , double w){
        length = l;
        width = w;
    }
    double getArea() override {
        return length * width ;
    }
};

class Triangle : public Shape{
    double base;
    double height;
    public:
    Triangle(double b , double h):base(b), height(h) {}
    double getArea() override{
        return 0.5 * base * height ;
    }
};

int main(){
    Rectangle r1;
    r1.setvalues(5.6 , 7.4);

    Triangle t1(12.921 , 7.123);

    cout<<"Area For Rectangle = "<<r1.getArea()<<endl;
    cout<<"Area For Triangle = "<<t1.getArea()<<endl;

}