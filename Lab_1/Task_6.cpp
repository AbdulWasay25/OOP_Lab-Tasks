#include<iostream>
#include<cmath>

using namespace std;

int main(){
    string name;
    float sum = 0;
    float scores[5] , average;
    cout<<"Enter Student Name : " ;
    cin>>name;
    cout<< "Enter Test Scores" << endl ;
    for(int i=0 ; i<5 ; i++){
        cin >> scores[i];
        sum += scores[i] ;
    }
    average = round((sum/5)*100)/100 ;
    cout <<"Name : " << name << endl << "Average Score : " << average ;
}