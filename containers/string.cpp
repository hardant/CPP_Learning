// extract to string
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

void test01() {
  std::string str;
  std::cout << "Please, enter your full name: ";
  std::getline (std::cin,str);
  std::cout << str << std::endl;
  std::stringstream ss(str);
  std::string name;
  while(std::getline(ss, name, ',')) {
    std::cout << "Hello, " << name << "!" << std::endl;
  }
}

void test02() {
  // 10012,选手L,87.0125,10003,选手C,83.2625,10005,选手E,83.1375,

  std::ifstream ifs;
  ifs.open("speech.csv", std::ios::in);

  std::string str;
  while(std::getline(ifs, str)) {
      std::size_t start_pos = 0;
      for (int i = 0; i < 3; i++) {
      std::size_t pos = str.find(",", start_pos);
      int num = std::stoi(str.substr(0, pos-start_pos));
      std::cout << "num:" << num << std::endl;
      start_pos = pos+1;
      pos = str.find(",", start_pos);
      std::string name = str.substr(start_pos, pos-start_pos);
      std::cout << "name:" << name << std::endl;
      start_pos = pos+1;
      pos = str.find(",", start_pos);
      double score = stod(str.substr(start_pos, pos-start_pos));
      std::cout << "score:" << score << std::endl;
      start_pos = pos + 1;
    }
  }
}

void test03() {
  std::string str = "10012,选手L,87.0125,10003,选手C,83.2625,10005,选手E,83.1375,";
  std::size_t start_pos = 0;

  for (int i = 0; i < 3; i++) {
    std::size_t pos = str.find(",", start_pos);
    int num = std::stoi(str.substr(0, pos-start_pos));
    std::cout << "num:" << num << std::endl;
    start_pos = pos+1;
    pos = str.find(",", start_pos);
    std::string name = str.substr(start_pos, pos-start_pos);
    std::cout << "name:" << name << std::endl;
    start_pos = pos+1;
    pos = str.find(",", start_pos);

    double score = stod(str.substr(start_pos, pos-start_pos));
    std::cout << "score:" << score << std::endl;
    start_pos = pos + 1;
  }
}



void test04() {
  std::string strs[2];
  strs[0] = "aa";
  strs[1] = "bb";


  std::cout << strs[1] << std::endl;

  std::cout << *strs << std::endl;
}

std::vector<std::string> split(std::string str, std::string splitor) {
  int splitor_len = splitor.length();
  std::size_t found = -1;
  std::size_t start = 0;
  found = str.find(splitor, start);
  std::vector<std::string> strs;
  
  while (found != -1) {
    strs.push_back(str.substr(start, found-start));
    start = found + splitor_len;
    if (start >= str.length()) {
      break;
    }
    found = str.find(splitor, start);
  }
  strs.push_back(str.substr(start, str.length() - start));
  return strs;
}

void test05() {
  std::string str = "10012,选手L,87.0125,10003,选手C,83.2625,10005,选手E,83.1375,";
  std::vector<std::string> subs = split(str, ",");

  for (std::vector<std::string>::iterator it = subs.begin(); it != subs.end(); it ++) {
    std::cout << *it << std::endl;
  }
  std::cout << "-----" << std::endl;
  str = ",aa,bb,";
  subs = split(str, ",");
  
  for (std::vector<std::string>::iterator it = subs.begin(); it != subs.end(); it ++) {
    std::cout << *it << std::endl;
  }
}

void test06() {
  std::vector<std::string> subs = split("", ",");
  std::cout << subs.size() << std::endl;
  for (std::vector<std::string>::iterator it = subs.begin(); it != subs.end(); it ++) {
    std::cout << *it << std::endl;
  }
}

int main ()
{
  test06();
  //std::cout << "Hello, " << str << "!\n";
  return 0;
}