#include <vector>
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;

int main(int argc, char const *argv[])
{
  vector<int> v;
  for(int i = 0; i < 10; i++) {
    v.push_back(i);
  }
  srand(time(0));
  random_shuffle(v.begin(), v.end());

  for(vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    cout << *it << endl;;
  }
  return 0;
}
