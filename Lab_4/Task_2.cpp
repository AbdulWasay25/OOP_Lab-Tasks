#include<iostream>

using namespace std ;

class Account {
	double balance ;
	public :
		Account(double b) : balance(b) {}
		
		double credit(double amount){
			balance += amount ;
			return balance ;
		}
		double debit(double damount){
			if(damount>balance){
				cout<<"No Enough Credit"<<endl ;
				return 0 ;
			}else{
				balance -= damount ;
				return balance ;
			}
		}
		double getBalance(){
			return balance ;
		}
};

int main(int argc , char* argv[]){
	Account acc1(stod(*(argv + 1))) ;
	cout<<"New Balance : "<<acc1.credit(stod(*(argv + 2)))<<endl;
	cout<<"New Balance : "<<acc1.debit(stod(*(argv + 3)))<<endl;
	cout<<"Current Balance : "<<acc1.getBalance()<<endl;
	return 0;
}