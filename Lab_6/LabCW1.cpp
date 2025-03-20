#include<iostream>
using namespace std;

class BankAcc{
    protected:
    int accnum ;
    double balance ;
    bool frozen;
    public:
    BankAcc(int a , double b) : accnum(a) , balance(b) {frozen = false ;}
    void deposit(double amount){
        balance += amount ;
        cout<<"Rs. "<<amount<<" Deposited ... Your new Balance is : Rs. "<<balance<<endl;
    }
    double getbalance(){ return balance ;}
    void withdraw(double amount){
        if(amount>balance){cout<<"Not Enough Cash"<<endl ; return ;}
        else{
            balance -=amount ;
            cout<<"Rs. "<<amount<<"Withdrew ... Your new Balance is : "<<balance<<endl;
        }
    }
    void freeze(int a){
        if(a==1){frozen = true ; cout<<"Account Freezed"<<endl;}
        else{frozen = false; cout<<"Accont Unfreezed"<<endl ;}
    }
};

class SavingAcc : public BankAcc{
    float interest;
    public :
    SavingAcc(int a , double b ) : BankAcc(a , b)  {interest = 0.00 ;}
    void monthlyinterest(float rate){
        interest = (getbalance() * rate) / 100 ;
        cout<<"Monthly Interest is "<<interest <<" at rate of "<<rate<<"."<<endl ;
    }
};

class CheckingAcc : public BankAcc{
    public:
    int overdraft;
    CheckingAcc(int a , double Balance , int od) : BankAcc(a , Balance) , overdraft(od) {}
    void overdrafting(int rupees){
        if(rupees>getbalance()){
            if(rupees>overdraft){
                cout<<"overDraft Limit Exceeded" << endl;
            }else{
                cout<<"Amount Overdrafted"<<endl;
            }
        }else{
            BankAcc::withdraw(rupees);
            cout<<"Amount WithDrawed"<<endl;
        }
    }
};

class BusinessAcc : public BankAcc {
    float taxrate ;
    public :
    BusinessAcc(int a , double b , float tr) : BankAcc(a , b) , taxrate(tr) {}
    void deposit(double amount){
        balance += amount * (1 - taxrate) ;
        cout<<"Amount Deposted in Business Account with Corporate Tax"<<endl ;
    }
};

class Customer{
    public:
    void deposit(BankAcc &b , double amount){
        b.deposit(amount);
    }
    void withdraw(BankAcc &b , double amount){
        b.withdraw(amount);
    }
};

class Teller : public Customer{
    public :
    void freezeAcc(BankAcc &acc){
        acc.freeze(1);
        cout<<"Account Freezed"<<endl ;
    }
    void unfreezeAcc(BankAcc &acc){
        acc.freeze(0);
        cout<<"Account UnFreezed"<<endl ;
    }
};

class Manager : public Teller{
    public:
    void adjustbalance(BankAcc acc , double balance){
        cout<<"Manager Adjusting New Balance to Rs. "<<balance<<endl ;
    }
};

int main(){
    BankAcc acc(12345, 1000);
    Customer cust;
    Teller teller;
    Manager mgr;

    cust.deposit(acc, 200);
    cust.withdraw(acc, 500);
    teller.freezeAcc(acc);
    cust.deposit(acc, 100); // Should not work
    teller.unfreezeAcc(acc);
    mgr.adjustbalance(acc, 5000);
    
    return 0;
}