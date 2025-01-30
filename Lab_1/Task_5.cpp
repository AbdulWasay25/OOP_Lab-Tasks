#include<iostream>
#include<cmath>

using namespace std;

int main(){
    string moviename;
    float adult_tp , child_tp , grossamount , percentage , amount_donated;
    int count_adult , count_child  , total_tickets;
    cout<<"Enter Movie Name : "<<endl;
    cin>>moviename;
    cout<<"Enter Adult Ticket Price : "<<endl;
    cin>>adult_tp;
    cout<<"Enter Child Ticket Price : "<<endl;
    cin>>child_tp;
    cout<<"Number Of Adult Tickets Sold : "<<endl;
    cin>>count_adult;
    cout<<"Number Of Child Tickets Sold : "<<endl;
    cin>>count_child;
    cout<<"Enter Percentage To Be Donated : "<< endl ;
    cin>>percentage ;
    total_tickets= count_adult + count_child;
    grossamount = (adult_tp * count_adult) + (child_tp * count_child) ;
    amount_donated = (percentage/100) * grossamount ;
    float netsale = round ((grossamount - amount_donated) * 100) / 100 ;
    cout<<"Movie Name ................." << moviename << endl ;
    cout<<"Number Of Tickets Sold .........." << total_tickets << endl ;
    cout<<"Gross Amount ...................." << grossamount << endl ;
    cout<<"Percentage Donated .............." << percentage << endl ;
    cout<<"Amount Donated .................." << amount_donated << endl ;
    cout<<"Net Sale ........................" << netsale << endl ;
}