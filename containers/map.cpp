#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
  map<int, string> m;
  // m.insert(make_pair(1, "aaa"));
  // m.insert(make_pair(1, "bbb"));
  // m.insert(make_pair(1, "ccc"));
  // m.insert(make_pair(1, "ddd"));

  m[1] = "aaa";
  m[1] = "bbb";
  m[2] = "ccc";
  m[1] = "ddd";

  for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " => " << it->second << endl;
  }
  return 0;
}
