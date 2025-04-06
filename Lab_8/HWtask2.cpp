#include<iostream>
using namespace std;

class Shape{
    int length;
    int breadth;
    public:
    Shape(int l , int b): length(l) , breadth(b) {}
    int Area()const{
        return length * breadth ; 
    }

    float operator+(const Shape& other) {
        return this->Area() + other.Area();
    }
};

int main(){
    Shape s1(5 , 3);
    Shape s2(7 , 4);
    cout<<s1.Area()<<endl;
    cout<<s2.Area()<<endl;
    cout<<s1 + s2<<endl ;
}