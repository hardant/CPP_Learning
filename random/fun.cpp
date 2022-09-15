#include "fun.hpp"

void test01() {
  for (int i = 0; i < 5; i++) {
    int r = std::rand() % 100;
    std::cout << r << std::endl;
  }
}