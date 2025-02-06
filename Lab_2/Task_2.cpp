#include<iostream>
#include<string>
using namespace std;

void* add(void* array , int n ){
	int* intarray = (int*)array ;
    for(int i=0 ; i< n-1 ; i++){
        intarray[i]= intarray[i] + intarray[i+1] ;
    }
	return array ;
}

int main(int argc , char* argv[]){
   	int array[argc - 1];
    for (int i = 1; i < argc; i++) {
        array[i - 1] = stoi(argv[i]);
    }
    int size = sizeof(array) / sizeof(array[0]);
    void* result = add(array, size);
    int* processedarr = (int*)result ;
    for (int i = 0; i < size - 1; i++) {
        cout << processedarr[i] << " ";
    }

    return 0;
}