#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

void test01() {
  map<int, string> m;
  m.insert(make_pair(2, "aaa"));
  m.insert(make_pair(3, "bbb"));
  m.insert(make_pair(4, "ccc"));
  m.insert(make_pair(5, "ddd"));

  // m[1] = "aaa";
  // m[1] = "bbb";
  // m[2] = "ccc";
  // m[1] = "ddd";
  cout << "size:" << m.size() << endl;

  for (map<int, string>::iterator it = m.begin(); it != m.end(); it++) {
    cout << it->first << " => " << it->second << endl;
  }
}

void test02() {
  multimap<double, int, greater<double> > groupmap;
  groupmap.insert(make_pair(77.7625, 10007));
  groupmap.insert(make_pair(77.3875, 10011));
  groupmap.insert(make_pair(80.5125, 10008));
  groupmap.insert(make_pair(80.8875, 10005));
  groupmap.insert(make_pair(73.1375, 10001));
  groupmap.insert(make_pair(76.2625, 10009));
  for (multimap<double, int>::iterator git = groupmap.begin(); git != groupmap.end(); git++) {
    cout << git->second << "=>" << git->first << endl;
  }
}

int main(int argc, char const *argv[])
{
  test02();
  return 0;
}
