/**
 * @file selectSort.cpp
 * @author Brandon Fu (fuhaifeng11@sina.com)
 * @brief 
 * @version 0.1
 * @date 2022-09-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>

using namespace std;

template <class T>
void myswap(T &a, T &b) {
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
void mySelectSort(T *arr, int len) {
    for (int i = len - 1; i > 1; i--) {
        int maxIndex = i;
        for(int j = 0; j < i; j++) {
            if (arr[maxIndex] < arr[j]) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            myswap(arr[maxIndex], arr[i]);
        }
    }
}
template <class T>
void myprint(T *arr, int len) {
    for(int i = 0; i < len; i++) {
        cout << arr[i] << ",";
    }
    cout << endl;
}

void test01() {
    int a[5] = {5, 4, 3, 2, 1};
    mySelectSort(a, 5);


    myprint(a, 5);
}

void test02() {
    double a[5] = {5.1, 4.1, 3.1, 2.1, 1.1};
    mySelectSort(a, 5);


    myprint(a, 5);
}

int main(int argc, char const *argv[])
{
    test01();
    test02();
    return 0;
}
