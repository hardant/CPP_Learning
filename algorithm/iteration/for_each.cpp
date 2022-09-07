#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void print(int i) {
  cout << i << endl;
}

template<class Container, class _Function>
void myForEach(Container c, _Function f) {
  for_each(c.begin(), c.end(), f);
}

void test01() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    sort(v.begin(), v.end(), greater<int>());

    for_each(v.begin(), v.end(), print);
}

void test02() {
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  myForEach(v, print);
}

int main(int argc, char const *argv[])
{
  test02();
  return 0;
}

