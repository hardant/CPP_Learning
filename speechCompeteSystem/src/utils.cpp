#include "../header/utils.hpp"


inline void ignoreLine() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
template char standardIn<char>(string tips);
template int standardIn<int>(string tips);
template <typename T>
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