#include "utils.hpp"


inline void ignoreLine() {
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
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