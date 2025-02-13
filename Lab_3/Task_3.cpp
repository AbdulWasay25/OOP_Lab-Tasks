#include<iostream>
#include<string>

using namespace std ;

class Glass{
	public:
		int liquidlevel ;

	void Drink(int mm){
		liquidlevel -= mm ;
		cout<<"Remaining Liquid = "<< liquidlevel << endl ;
	}
	
	void refill(){
		if(liquidlevel < 100){
			liquidlevel = 200 ;
			cout<<"Glass Refilled"<< endl ;
		}else{
			liquidlevel = liquidlevel ;
			cout << "No Refilling Required" << endl ;
		}
	}
};

int main(int argc , char* argv[]){
	int array[argc-1] ;
	int *ptr = array ;

	for(int i=0 , j=2 ; i<argc-1 , j<argc; i++ , j++){
		*(ptr + i) = stoi(*(argv + j)) ;
	}

	Glass paani ;
	paani.liquidlevel = stoi(*(argv + 1)) ;
	int i=0 ;
	bool exit=1 ;
	int count=0 ;
	while(exit){
		if(count==argc-1){ return 0;}
		paani.Drink(*(ptr + i)) ;
		paani.refill() ;
		i++ ;
		cout<<"Press 0 To Exit Else 1" << endl ;
		cin >> exit ;
		count++ ;
	}
}