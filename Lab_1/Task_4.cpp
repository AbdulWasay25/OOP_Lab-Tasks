#include<iostream>
#include<cmath>
using namespace std;

int main(){
    float weight , w_pound;
    cout<<"Enter Your Weight In KG : "<<endl;
    cin>>weight;
    w_pound = weight * 2.2 ;
    weight = round(weight *100) /100;
    w_pound = round(w_pound*100)/100 ;
    cout<<"Your Weight In KG = " << weight<< endl <<"Your Weight In POUND = "<< w_pound ;
}