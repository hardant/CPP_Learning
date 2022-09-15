#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
  cout << "press any key to continue!" << endl;
  int c = getchar();
  cout << c << endl;
  int a;
  cout << "input an integer:" << endl;
  cin >> a;
  cout << "the end" << endl;
  return 0;
}
