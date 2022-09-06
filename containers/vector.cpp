
#include <iostream>
#include <vector>

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

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
