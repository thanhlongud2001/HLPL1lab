#include "std_lib_facilities.h"

void print_array(ostream& os, int* a, int n) {
    for (int i = 0; i < n; i++) {
        os << a[i] << " ";
    }
    cout << endl;
}

int main() {
    //drill 1
    int a = 7;
    int* p1 = &a;

    //drill 2
    cout << p1 << " " << *p1 << endl;

    //drill 3+4
    a = 1;
    int* ar = new int[7];
    for (int i = 0; i < 7; i++) {
        ar[i] = a;
        a *= 2;
    }
    int* p2 = ar;

    cout << p2 << " ";
    print_array(cout, ar, 7);

    //drill 5
    int* p3 = p2;

    //drill 6+7
    p1 = p2;
    p3 = p2;

    //drill 8
    cout << *p1 << " " << p1 << endl;
    cout << *p2 << " " << p2 << endl;

    //drill 9
    delete[] ar;

    //drill 10
    p1 = new int[10] {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

    //drill 11
    p2 = new int[10];

    //drill 12
    for (int i = 0; i < 10; i++) {
        p2[i] = p1[i];
    }
    print_array(cout, p2, 10);

    //drill 13
    vector<int> v1 = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};
    p1 = &v1[0];

    vector<int> v2(10);
    p2 = &v2[0];

    v2 = v1;
    for (auto i : v2)
        cout << i << " ";
    cout << endl;

    return 0;
}
