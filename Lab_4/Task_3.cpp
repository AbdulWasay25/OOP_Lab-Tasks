#include<iostream>

using namespace std;

class Invoice{
	string number ;
	string description ;
	int quantity ;
	double pricepi;
	public:
		Invoice(string n , string d , int q , double ppi) : number(n) , description(d) , quantity(q) , pricepi(ppi) {}
		
		double getInvoiceamount(){
			if(quantity<0){
				quantity = 0.00 ;
				cout<<"Nothing Sold"<<endl;
				return 0;
			}else if(pricepi<0){
				pricepi = 0.00 ;
				cout<<"Free Give Away"<<endl;
				return 0;
			}else{
				return quantity*pricepi ;
		}}
};

int main(int argc , char* argv[]){
	Invoice item1(*(argv + 1) , *(argv + 2) , stoi(*(argv + 3)) , stod(*(argv + 4))) ;
	cout<<"Invoice : "<<item1.getInvoiceamount()<<endl ;
	return 0;
}




