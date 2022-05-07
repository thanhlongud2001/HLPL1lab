#include "std_lib_facilities.h"

//drill 4
void print_array10(ostream& os, int* a) {
    for (int i = 0; i < 10; i++) {
        os << a[i] << " ";
        cout << endl;
    }
}

//drill 7
void print_array(ostream& os, int* a, int n) {
    for (int i = 0; i < n; i++) {
        os << a[i] << " ";
        cout << endl;
    }
}

//for drill 10
void print_vector(ostream& os, vector<int>& v) {
    for (auto i : v)
        os << i << " ";
    cout << endl;
}

int main() {
    //drill 1+2
    int* a1 = new int[10];
    for (int i = 0; i < 10; i++) {
        a1[i] = i;
        cout << a1[i] << " ";
    }
    cout << endl;
    //drill 3
    delete[] a1;

    //drill 5
    int x = 100;
    int* a5 = new int[10];
    for (int i = 0; i < 10; i++) {
        a5[i] = x;
        x++;
        cout << a5[i] << " ";
    }
    cout << endl;
    delete[] a5;

    //drill 6
    x = 100;
    int* a6 = new int[11];
    for (int i = 0; i < 11; i++) {
        a6[i] = x;
        x++;
        cout << a6[i] << " ";
    }
    cout << endl;
    delete[] a6;

    //drill 8
    x = 100;
    int* a8 = new int[20];
    for (int i = 0; i < 20; i++) {
        a8[i] = x;
        x++;
        cout << a8[i] << " ";
    }
    cout << endl;
    delete[] a8;

    //drill 10
    vector<int> v5(10);
    int y = 100;
    for (int i = 0; i < 10; i++) {
        v5[i] = y;
        y++;
    }
    print_vector(cout, v5);

    vector<int> v6(11);
    y = 100;
    for (int i = 0; i < 11; i++) {
        v6[i] = y;
        y++;
    }
    print_vector(cout, v6);

    vector<int> v8(20);
    y = 100;
    for (int i = 0; i < 20; i++) {
        v8[i] = y;
        y++;
    }
    print_vector(cout, v8);

    return 0;
}
