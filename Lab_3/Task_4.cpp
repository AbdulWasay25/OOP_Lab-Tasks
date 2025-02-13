#include<iostream>
#include<string>

using namespace std ;

class Employee{
	string first;
	string last;
	double salary ;
	public :
		string getfirst(string first){
			return first ;
		}
		void setfirst(string first){
			this->first = first ; 
		}
		string getlast(string last){
			return last ;
		}
		void setlast(string last){
			this->last = last ; 
		}
		double getsalary(double salary){
			return salary ;
		}
		void setsalary(double salary){
			if(salary<0){
				this->salary=0.00;
			}else
			this->salary = salary ; 
		}
		void increment(int percent){
			salary += (salary * percent)/100 ;
			//cout<<"Incremented Salary : " << salary<<endl ;
		}
		double yearlysalary(){
			return salary * 12 ;
		}
		void displayinfo(){
			cout<<"First Name : "<<first<<endl<<"Last Name : "<<last<<endl<<"Monthly Salary : "<<salary<<endl<<"Yearly Salary : "<<yearlysalary()<<endl ;
		}
};

int main(int argc , char* argv[]){
	Employee Emp1 ;
	Employee Emp2 ;
	Emp1.setfirst(*(argv + 1)) ;
	Emp1.setlast(*(argv + 2)) ;
	Emp1.setsalary(stod(*(argv + 3)));	//for only displaying yearly salary and no other info:
	Emp1.displayinfo(); 				//cout<<"Yearly Salary :"<<Emp1.yearlysalary()<<endl; 
	Emp1.increment(10.00);				
	cout<<"Incremented Yearly Salary :"<<Emp1.yearlysalary()<<endl; 
	Emp2.setfirst(*(argv + 4)) ;
	Emp2.setlast(*(argv + 5)) ;
	Emp2.setsalary(stod(*(argv + 6)));	//for only displaying yearly salary and no other info:
	Emp2.displayinfo(); 				//cout<<"Yearly Salary :"<<Emp2.yearlysalary()<<endl; 
	Emp2.increment(10.00);				
	cout<<"Incremented Yearly Salary :"<<Emp2.yearlysalary()<<endl; 
	return 0 ;
}