#include<iostream>
using namespace std;

int main(){
	int units , bill , bill_ID ; int surcharge=0; 
    string name ;
	bill =0.00 ;
	cout<<"ENTER CUSTOMER ID : " ;
	cin>>bill_ID;
	cout<<"ENTER YOUR NAME : " ;
	cin>>name;
	cout<<"ENTER YOUR ELECTRICITY UNITS : ";
	cin>>units;
	cout<<"Customer ID :"<<bill_ID<<endl<<"Name : "<<name<<endl<<"Units Consumed : "<<units<<endl;
	if(units>0 && units<=199){
		bill=units*16.20;
	}
	else if(units>199 && units<=300){
		bill=units*20.10;
	}
	else if(units>300 && units<=500){
		bill=units*27.10;
	}
	else {
		bill=units*35.90;	
	}
	if(bill>18000){
		surcharge=0.15*bill;
		bill += surcharge ;
	}
	cout<<"The Surcharge Amount Is : "<<surcharge<<endl<<"YOUR BILL IS RS : "<<bill<<endl;
	return 0;
}