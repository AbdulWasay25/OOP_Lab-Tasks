#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

struct Employees{
	int empID ;
	string name ;
	float salary ;
};

struct Organisation{
	string orgname ;
	string orgnum ;
	Employees Emp;
};

int main(int argc , char* argv[]){
	Organisation Org1 ;
	Org1.orgname = *(argv + 1) ;
	Org1.orgnum = *(argv + 2) ;
	Org1.Emp.empID = stoi(*(argv + 3)) ;
	Org1.Emp.name = *(argv + 4) ;
	Org1.Emp.salary = stoi(*(argv + 5)) ;
	cout<<"Organisation Name : "<<Org1.orgname<<endl ;
	cout<<"Organisation Number : "<<Org1.orgnum<<endl ;
	cout<<"Employee ID : "<<Org1.Emp.empID<<endl ;
	cout<<"Employee Name : "<<Org1.Emp.name<<endl ;
	cout<<"Salary : "<<Org1.Emp.salary<<endl ;
}