// extract to string
#include <iostream>
#include <string>
#include <sstream>

int main ()
{
  std::string str;
  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,str);
  std::cout << str << std::endl;
  std::stringstream ss(str);
  std::string name;
  while(std::getline(ss, name, ',')) {
    std::cout << "Hello, " << name << "!" << std::endl;
  }
  //std::cout << "Hello, " << str << "!\n";
  return 0;
}