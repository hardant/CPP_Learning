
#include <iostream>
#include <string>

using namespace std;


// template <T>
void myswap(int &a, int & b) {
    cout << "swap1" << endl;
    int tem = a;
    a = b;
    b = tem;
}

template <class T>
void myswap2(T &a, T &b) {
    cout << "swap2" << endl;
    T tmp = a;
    a = b;
    b = tmp;
}


int main(int argc, char const *argv[])
{
    int a = 1;
    int b = 2;
    myswap2(a, b);
    cout << a << "," << b << endl;
    return 0;
}
