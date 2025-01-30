#include <iostream>
using namespace std;

int main(int argc , char *argv[]) {
    float arr[5];
    float *ptr = arr;
for(int i=0 ; i<5 ; i++){
    cin>>*(ptr + i);
}
    float max = *ptr, smax = *ptr;
    for (int i = 1; i < 5; i++) {
        if (*(ptr + i) > max) {
            smax = max;
            max = *(ptr + i);
        } else if (*(ptr + i) > smax && *(ptr + i) != max) {
            smax = *(ptr + i);
        }
    }

    cout << "Second Highiest = " << smax << endl;
    return 0;
}
