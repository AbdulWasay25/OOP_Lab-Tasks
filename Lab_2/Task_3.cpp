#include<iostream>
#include<cstdlib>

using namespace std ;
 
int main(int argc , char* argv[]){
	int n=5 ;
	int *array[n] ;
	if(argc>n){
		*array = new int[2 * n] ;
	}
	//*array = new int[argc];
	cout<<"Program For Memory Allocation Successfull" ; 
	delete [] array;
	

}