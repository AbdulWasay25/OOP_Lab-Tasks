#include<iostream>
using namespace std;
int main(int argc , char* argv[]) {
    int size = 5;
    int* arr = new int[size];  
    int count = 0;
    for (int i = 0 , k=1 ; count < argc-1; i++ , k++) {
        arr[count] = stoi(*(argv + k));  
        count++;
        if (count == size) {
            size *= 2;
            int* temp = new int[size];  
            for (int j = 0; j < count; j++) {
                temp[j] = arr[j]; 
                cout<<" "<<temp[j];
            }
            cout<<endl;
            delete[] arr;  
            arr = temp;  
        }
    }
	cout << "Program For Memory Allocation Succesfull"  << endl;
    cout << "Array size: " << size << endl;
    delete[] arr;  
    return 0;
}
