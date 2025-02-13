#include<iostream>
#include<string>

using namespace std ;

class Date{
int month ;
int date ;
int year ;
public :
int getmonth(int month){
return month ;
}
void setmonth(int month){
this->month = month ;
}
int getdate(int date){
return date ;
}
void setdate(int date){
this->date = date ;
}
int getyear(int year){
return year ;
}
void setyear(int year){
this->year = year ;
}
void displayDate(){
cout<<"\t"<<month<<" / "<<date<<" / "<<year << endl ;
}

};

int main(int argc , char* argv[]){
Date DateTest ;
DateTest.setmonth(stoi(*(argv + 1))) ;
DateTest.setdate(stoi(*(argv + 2))) ;
DateTest.setyear(stoi(*(argv + 3)));
DateTest.displayDate();
}
