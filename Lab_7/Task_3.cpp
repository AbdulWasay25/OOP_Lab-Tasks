#include<iostream>
using namespace std;

class Currency{
    protected:
    double amount;
    int currecycode;
    string symbol;
    public:
    Currency(double am , int cc , string s) : amount(am) , currecycode(cc) , symbol(s) {}
    virtual void convertobase(){}
    virtual void converto(string currencyname , float rate){}
    virtual void display(){}
};

class Dollar : public Currency{
    string country;
    public:
    Dollar(double am , string country) : Currency(am , 1001 , "$") , country(country){}
    void convertobase() override {
        float b = amount * 280 ;
        cout<<"$ "<<amount<<"= Rs. "<<b<<endl;
    }
    void converto(string cn , float rate)override{
        float b = amount * rate ;
        cout<<"$ "<<amount <<"= "<<cn<<" "<<b<<endl;
    }
    void display()override{
        cout<<"Currency Code : "<<currecycode<<"\nSymbol : "<<symbol<<"\nCountry : "<<country<<"\nAmount : "<<amount<<endl;
    }
};

class Euro : public Currency{
    string country;
    public:
    Euro(double am , string country) : Currency(am , 1002 , "€") , country(country){}
    void convertobase() override {
        float b = amount * 310 ;
        cout<<"$ "<<amount<<"= Rs. "<<b<<endl;
    }
    void converto(string cn , float rate)override{
        float b = amount * rate ;
        cout<<"€ "<<amount <<"= "<<cn<<" "<<b<<endl;
    }
    void display()override{
        cout<<"Currency Code : "<<currecycode<<"\nSymbol : "<<symbol<<"\nCountry : "<<country<<"\nAmount : "<<amount<<endl;
    }
};

class PakRupee : public Currency{
    string country;
    public:
    PakRupee(double am) : Currency(am , 1003 , "R") , country("Pakistan"){}
    void convertobase() override {
        cout<<"Rs. "<<amount<<"(already in Base Currency)";
    }
    void converto(string cn , float rate)override{
        float b = amount * rate ;
        cout<<"Rs. "<<amount <<"= "<<cn<<" "<<b<<endl;
    }
    void display()override{
        cout<<"Currency Code : "<<currecycode<<"\nSymbol : "<<symbol<<"\nCountry : "<<country<<"\nAmount : "<<amount<<endl;
    }
};

int main(){
    Dollar d(500 , "USA");
    d.converto("Euro" , 0.92);
}