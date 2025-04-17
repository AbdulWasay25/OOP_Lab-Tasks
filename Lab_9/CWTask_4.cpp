#include<iostream>
using namespace std;

class Passenger;

class Flight{
    string fn;
    string departure;
    string arrival;
    int capacity; int seatsbooked;
    public:
    void setvalues(string f , string d , string a , int c){
        fn=f; departure=d; arrival=a; capacity=c; seatsbooked=0;
    }
    string getfn(){return fn;}
    string getdeparture(){return departure;}
    string getarrival(){return arrival;}
    bool bookseat(){
        if(seatsbooked>=capacity){
            cout<<"No Seats Available !"<<endl;
            return false;
        }else{
            capacity--;
            seatsbooked++;
            cout<<"Seat Booked For Flight Number "<<fn<<" Successfully !"<<endl;
            return true;
        }
    }
    bool Cancelseat(){
        if(seatsbooked==0){
            cout<<"No Seats Booked !"<<endl;
            return false;
        }else{
            capacity++;
            seatsbooked--;
            cout<<"Seat Cancelled For Flight Number "<<fn<<" Successfully !"<<endl;
            return true;
        }
    }
    void Upgradeseat(Passenger& p){
        if(p.getstatus()==1){
            cout<<"Upgrading Seat To Highier Tier "<<endl;
        }else{
            cout<<"No Seats Booked By This Passenger"<<endl ;
        }
    }
};

class Passenger{
    string name;
    string ID;
    int status;
    public:
    void setvalues(string n , string id){
        name=n ; ID=id; status=0;
    }
    int getstatus(){return status;}
    void requestbooking(Flight& f1){
        f1.bookseat();
    }
    void cancelseat(Flight& f1){
        f1.Cancelseat();
    }
};

int main(){
    Flight f1;
    Passenger p1;
    f1.setvalues("k2fn1001", "Karachi" , "Islamabad", 2);
    p1.setvalues("ABC" , "k23564");
    p1.cancelseat(f1);
}