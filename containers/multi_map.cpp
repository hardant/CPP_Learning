#include <map>
#include <iostream>
using namespace std;

void test01() {
    multimap<int, int> map;
    map.insert(std::pair<int, int>(1, 1));
    map.insert(std::pair<int, int>(2, 1));
    map.insert(std::pair<int, int>(3, 1));
    map.insert(std::pair<int, int>(1, 2));

    multimap<int, int>::iterator it = map.begin();

    for(; it != map.end(); ++it) {
        cout << it->first << "=>" << it->second << endl;
    }
    cout << "-------" << endl;
    it = map.find(1);
    cout << it->first << "=>" << it->second << endl;
    it = map.find(1);
    cout << it->first << "=>" << it->second << endl;

    clog << "complete" << endl;
}

int main(int argc, char const *argv[])
{
    test01();
    return 0;
}
