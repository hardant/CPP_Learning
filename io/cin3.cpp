#include <iostream>
#include <limits>
#include <string>

using namespace std;

void ignoreLine() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

template<typename T>
T standardIn(string tips) {
  T value;
  while(true) {
    cout << tips << endl;
    cin >> value;
    if(cin.fail()) {
      cout << "invalid input" << endl;
      cin.clear();
      ignoreLine();
    } else {
      ignoreLine();
      return value;
    }
  }
  
}


int main(int argc, char const *argv[])
{
  int a = standardIn<int>("请输入一个数值:");
  cout << a << endl;
  return 0;
}
