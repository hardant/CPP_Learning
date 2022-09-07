#include <iostream>

using namespace std;

template<class T>
class MyAdd {
public:
  T operator()(T v1, T v2) {
    return v1+v2;
  }
};
template <typename T, typename Add>
T func(T v1, T v2, Add add) {
  return add(v1, v2);
}

int main(int argc, char const *argv[])
{
  int result = func<int, MyAdd<int> >(1, 2, MyAdd<int>());
  cout << result << endl;
  return 0;
}
