#include<iostream>
using namespace std;

class Decrement{
    int num;
    public:
    Decrement(int n) : num(n){}

    Decrement operator--(){
        num *= 4 ;
        return *this;
    }
    Decrement operator--(int){
        Decrement temp = *this;
        num /= 4 ;
        return temp;
    }
    void display(){
        cout<<"Value of Number = "<<num<<endl;
    }
};

int main(){
    Decrement d1(16) ;
    cout<<"Initial Value = " ;
    d1.display();
    cout<<"Pre Decremented Value = ";
    --d1;d1.display();
    cout<<"Post Decremented Value = ";
    d1-- ;d1.display();
}