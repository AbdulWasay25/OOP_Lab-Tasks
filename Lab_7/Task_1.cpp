#include<iostream>
using namespace std;

class Account{
    double accnum;
    double balance;
    string holdername;
    public:
    Account(double an , double b , string n):accnum(an) , balance(b) , holdername(n) {}
    double getbalance(){return balance ;}
    void setbalance(double newb){balance = newb ;}
    void deposit(double am){balance += am ; cout<<"Rs . "<<am<<" Deposited . "<<endl;printstatement(am);cout<<" being Deposited ."<<endl;}
    virtual void withdraw(double am){
        if(balance>=am){
            balance -= am ; 
            cout<<"Rs . "<<am<<" Withdrawn . "<<endl;
            printstatement(am);
            cout<<" being Deposited ."<<endl;}
        else{
            cout<<"Not Enough Balance ."<<endl ;
        }}
    virtual void calcinterest(float ir){
        float interest = (balance * ir)/100 ;
        cout<<"Interest is Rs. "<<interest<<endl;
        }
    virtual void printstatement(double am){
        cout<<"Print Statement For Rs. "<<am<<endl;
    }    
    void getaccinfo(){
        cout<<"Account Holder : "<<holdername<<"\nAccount Number : "<<accnum<<"\nBalance : "<<balance<<endl;
    }
};

class SavingAcc : public Account{
    float interestrate;
    double minbalance;
    public: 
    SavingAcc(double acn , double b , string n , float ir , double mb):Account(acn , b , n) , interestrate(ir) , minbalance(mb) {}
    void calcinterest(float ir) override{
        float interest = (getbalance() * ir) / 100 ;
        cout<<"Interest is Rs. "<<interest<<" @ "<<ir<<endl;
    }
    void printstatement(double ) override {
        cout<<"Print Statement For Rs. "<<getbalance()<<" : Savings Acoount ."<<endl;
    }
    void withdraw(double am) override {
        if(getbalance() >= am){
            if((getbalance() - am) > minbalance){
                double a = getbalance() - am ;
                setbalance(a) ; 
            cout<<"Rs . "<<am<<" Withdrawn . "<<endl;
            printstatement(am);
            cout<<" being Deposited ."<<endl;}
            else{cout<<"Minimum Balance Limit Warning"<<endl;}}
        else{
            cout<<"Not Enough Balance ."<<endl ;
        }
    }
};

class CheckingAcc : public Account{};

class FDAcc : public Account{
    float fir; 
    string maturitydate;
    public:
    FDAcc(double a , double b , string n , float f , string md) : Account(a , b , n) , fir(f) , maturitydate(md) {}
    void calcinterest(float) override{
        float interest = (getbalance() * fir) / 100 ;
        cout<<"Interest is Rs. "<<interest<<" @ "<<fir<<endl;
    }
    void printstatement(double) override{
        cout<<"Print Statement For Rs. "<<getbalance()<<" : Fixed Deposit Acoount ."<<endl;       
    }
};

int main(){
    SavingAcc SA1(2401 , 25000 , "Someone" , 18 , 15000) ;
    FDAcc Fd1(24005 , 300000 , "Thatone" , 14 , "24-5-25");

    SA1.withdraw(2000);
    Fd1.calcinterest(0.00);
}