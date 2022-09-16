#include <fstream>

using namespace std;

void clearContent() {
  ofstream ofs;
  ofs.open("out.txt", ios::out|ios::trunc);
  ofs.close();
}


void test01() {
  ofstream ofs;
  ofs.open("out.txt", ios::out);
  ofs << "hello" << endl;
  ofs.close();
  clearContent();
}


int main(int argc, char const *argv[])
{
  test01();
  return 0;
}
