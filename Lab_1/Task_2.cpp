#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Number Of Elements"<<endl;
    cin>>n;
    int array[n];
    int *ptrarr=array;
    cout<<"Enter Elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>*(ptrarr + i);
    }
    int sum=0;
    for(int i=0 ; i<n ; i++){
        sum += *(ptrarr + i );
    }
    cout<<"The Sum Of Elements Of Array is " << sum ;
}