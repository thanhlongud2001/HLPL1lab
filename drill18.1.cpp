#include "std_lib_facilities.h"

//ex 1
int ga[10] ={1,2,4,8,16,32,64,128,256,512};

//ex 2
void f(int a[], int n) {
    //ex 3a
    int la[10];

    //ex 3b + 3c
    for (int i = 0; i < 10; i++) {
        la[i] = ga[i];
        cout << la[i] << " ";
    }
    cout << endl;

    //ex 3d + 3e + 3f + 3g
    int* p = new int[n];
    for (int i = 0; i < n; i++) {
        p[i] = a[i];
        cout << p[i] << " ";
    }
    cout << endl;
    delete[] p;
}


//ex 4
int main() {
    f(ga, 10);
    int aa[10] = {1,2,6,24,120,720,5040,40320,362880,3628800};
    f(aa, 10);

    return 0;
}
