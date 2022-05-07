#include "std_lib_facilities.h"

void swap_v(int a, int b)
{
    cout << "Before :a: " << a << " b: " << b << endl;v
    int temp = a;
    a = b;
    b = temp;
    cout << "After a: " << a << " b: " << b << endl;
}
void swap_r(int& a, int& b)
{
    cout << "Before :a: " << a << " b: " << b << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "After a: " << a << " b: " << b << endl;
}
void swap_cr(const int a, const int  b)
{
    cout << "Before :a: " << a << " b: " << b << endl;
	int temp = a;
	a = b;
	b = temp;
    cout << "After a: " << a << " b: " << b << endl;
};

int main() {
    /*int x = 7;
    int y =9;
    swap_v(x,y); //works normal
    swap_r(7,9); //not work since 7,9 are intergers and cant be allocated memory

    const int cx = 7;
    const int cy = 9;
    swap_r(cx,cy); // npt work since both are constants and cant be swapped
    swap_v(7.7,9.9); //only swap the interger part
    */
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx,dy); //only swap the interger part
    swap_cr(7.7,9.9);
}
