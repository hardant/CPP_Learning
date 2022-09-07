
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void test01() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
}

void test02() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    sort(v.begin(), v.end(), greater<int>());

    for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << endl;
    }
}

int main(int argc, char const *argv[])
{
    test02();
    return 0;
}
