#include <iostream>
#include <limits>
#include <string>

using namespace std;

#include "./utils.hpp"


int main(int argc, char const *argv[])
{
  int a = standardIn<int>("请输入一个数值:");
  cout << a << endl;
  return 0;
}
