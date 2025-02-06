#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

struct Info{
	int ID ;
	string name ;
};

int main(int argc , char* argv[]){
	int n = (argc / 2)   ;
	Info inform[n] ;
	for(int i=0 , j=1 ; i < n , j<argc ; i++ , j++){
		inform[i].ID = stoi(*(argv + j));
		j += 1 ;
		inform[i].name = *(argv + j);
	}

	cout<<"\t Order By ID" << endl ;
		for(int i=0 ; i<n-1 ; i++){
		for(int j=1 ; j<n ; j++){
		if(inform[i].ID > inform[j].ID){
			int temp = inform[i].ID ;
			inform[i].ID  = inform[j].ID ;
			inform[j].ID = temp;
		}}	}
	for(int i=0 ; i<n;i++){
		cout<<inform[i].ID<<endl<<inform[i].name<<endl ;
	}

	for(int i=0 ; i<n-1 ; i++){
		for(int j=1 ; j<n ; j++){
		if(inform[i].name > inform[j].name){
			string temp1 = inform[i].name ;
			inform[i].name  = inform[j].name ;
			inform[j].name = temp1 ;
		}}	}
	cout<<"\t Order By Name" << endl ;	
	for(int i=0 ; i<n;i++){
		cout<<inform[i].ID<<endl<<inform[i].name<<endl ;
	}
}
