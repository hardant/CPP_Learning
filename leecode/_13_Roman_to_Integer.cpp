#include <string>
#include <iostream>
#include <cmath>

#define ROMAN_META "IVXLCDM"
using namespace std;

// get the sub unit
char getSubUnit(char c) {
  string meta = ROMAN_META;
  size_t pos = meta.find_first_of(c, 0);
  return *(meta.begin() + pos - pow(2, (pos+1) % 2));
}

// get the value of privided unit
int getUnit(char c) {
  string meta = ROMAN_META;
  return pow(10, (int(meta.find_first_of(c, 0)) + 1) / 2 ) / pow(2, (meta.find_first_of(c) % 2));
}

class Solution {
public:
  int romanToInt(string s);
};


int romanToInt(string s);

int romanToInt(string s) {
    int result = 0;
    for (string::iterator it = s.begin(); it != s.end(); it++) {
      result += getUnit(*it);
      if (it != s.begin() && *it != 'I' && *(it-1) == getSubUnit(*it)) {
        result -= 2 * getUnit(*(it-1));
      }
    }

    return result;
}

int Solution::romanToInt(string s) {
  int result = 0;
  for(string::iterator it = s.begin();it != s.end();it++) {
    switch (*it) {
    case 'I':
      result += 1;
      break;
    case 'V':
      if (it != s.begin()) {
        if (*(it - 1) == 'I') {
        result += 3;
        } else {
          result += 5;
        }
      } else {
        result += 5;
      }
      break;
    case 'X':
      if (it != s.begin()) {
        if (*(it - 1) == 'I') {
        result += 8;
        } else {
          result += 10;
        }
      } else {
        result += 10;
      }
      break;
    case 'L': // 50
      if (it != s.begin()) {
        if (*(it - 1) == 'X') {
        result += 30;
        } else {
          result += 50;
        }
      } else {
        result += 50;
      }
      break;
    case 'C': // 100
      if (it != s.begin()) {
        if (*(it - 1) == 'X') {
        result += 80;
        } else {
          result += 100;
        }
      } else {
        result += 100;
      }
      break;
    case 'D': // 500
      if (it != s.begin()) {
        if (*(it - 1) == 'C') {
        result += 300;
        } else {
          result += 500;
        }
      } else {
        result += 500;
      }
      break;
    case 'M': // 1000
      if (it != s.begin()) {
        if (*(it - 1) == 'C') {
        result += 800;
        } else {
          result += 1000;
        }
      } else {
        result += 1000;
      }
      break;
    default:
      break;
    }
  }
  return result;
}