#include "std_lib_facilities.h"

//ex 1
template <typename T>
struct S {
private:
	T val;
public :
	//ex 2
	S() {
		val = 0;
	}
	S(T val2) {
		val=val2;
	}

	T get();
	/*
	* //ex 5
    {
    return val;
	}
	*/
	const T get() const;
	void operator=(const T&);
	/*
	 //ex 9
	void set(T val3) {
		val = val3;
	}
	*/

};
//ex 6
template<typename T>
 T S<T>::get() {
		return val;
	}

 //ex 11
 template<typename T>
 const T S<T>::get() const {
	 return val;
 }

 //ex 10
template <typename T>
void S<T>:: operator=(const T& val3) {
	val = val3;
}

//ex 12
 template<typename T>
 void read_val(T& v) {
	 cin >> v;
}

int main() {
    //ex 3
    S<int> intS(19);
    S<char> charS('L');
    S<double> doubS(1.9);
    S<string> strS("String A");
    S<vector<int>> vecS ({ 1, 2, 3 });

    //ex 4+8
    cout << intS.get()<<endl;
    cout << charS.get() << endl;
    cout << doubS.get() << endl;
    cout << strS.get() << endl;
    for(int i : vecS.get())
        cout << i <<" ";
    cout << endl;

    //ex 13
    int i1; read_val(i1); S<int> i1S(i1);

	double d1; read_val(d1); S<double> d1S(d1);

    char c1; read_val(c1); S<char> c1S(c1);
    cout << i1S.get() << endl;
    cout << d1S.get() << endl;
    cout << c1S.get() << endl;

	return 0;
}
