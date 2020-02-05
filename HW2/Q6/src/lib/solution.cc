#include "solution.h"

bool Solution::simplePalindrome(std::string str) {
  int i = 0;
  int j = str.size() - 1;
  while (i <= j) {
    if (str[i] != str[j]) return false;
    i += 1;
    j -= 1;
  }
  return true;
}

bool Solution::approximatePalindrome(std::string str) {
  int i = 0;
  int j = str.size() - 1;
  while (i <= j) {
    if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
      if ((str[j] >= 'A' && str[j] <= 'Z') || (str[j] >= 'a' && str[j] <= 'z')) {
        if (str[i] != str[j] && std::abs(str[i]-str[j]) != 32) {
          return false;
        } else {
          i += 1;
          j -= 1;
        }
      } else j -= 1;
    } else i += 1;  
  }
  return true;
}
