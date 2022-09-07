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

void test01() {
  int result = func<int, MyAdd<int> >(1, 2, MyAdd<int>());
  cout << result << endl;
}

template<typename T>
class MyPrint {
public:
  void operator()(T t) {
    cout << "myPrint:" << t << endl;
  }

  void operator()(T t1, T t2) {
    cout << "myPrint:" << t1 << "," << t2 << endl;
  }
};

void test02() {
  MyPrint<int> print;
  print(1);
  print(1, 2);
}

int main(int argc, char const *argv[])
{
  test02();
  return 0;
}
