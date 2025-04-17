#include<iostream>
using namespace std;

class Wallet{
    double balance;
    int maxtran , maxdep;
    public:
    void setvalues(double b , int mt , int md){
        balance = b;
        maxtran = mt;
        maxdep = md;
    }
    double getbalance(){
        return balance;
    }
    void deposit(double amount){
        if(maxdep>0){
            balance += amount ;
        }else{
            cout<<"Sorry ! Deposit Limit Reached"<<endl;
        }
    }
    void transaction(double amount){
        if(amount<=balance && maxtran>0){
            balance -= amount ;
        }else{
            cout<<"Sorry ! Can't Transact"<<endl;
        }
    }
};

class User{
    string name;
    string userID;
    Wallet wallet;
    public:
    void setvalues(string n , string id , double b , int mt  ,int md ){
        name = n; userID = id ; wallet.setvalues(b,mt,md);
    }
    void deposit(double amount){
        wallet.deposit(amount);
    }
    void withdraw(double amount){
        wallet.transaction(amount);
    }
    string getname(){return name;}
    string getid(){return userID;}
    void getbalance(){
        cout<<"Current Balance = "<<wallet.getbalance()<<endl;
    }
};

int main(){
    User user1;
    user1.setvalues("Abdul Wasay" , "24K0744" , 3000 , 3 , 2);
    user1.withdraw(2000);
    cout<<user1.getname()<<endl<<user1.getid()<<endl;
    user1.getbalance();
}