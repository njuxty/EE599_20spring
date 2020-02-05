#include "solution.h"
#include <algorithm>
#include <iostream>

void Solution::swapChar(std::string& str, int i, int j) {
  if (str.size() < 2) {
    std::cout << "String can not be swapped." << std::endl;
    return;
  } 

  if (i < 0 || j < 0 || i >= str.size() || j >= str.size()) {
    std::cout << "Ineffective position index." << std::endl;
    return;
  }

  char temp;
  temp = str[i];
  str[i] = str[j];
  str[j] = temp;
}

void Solution::reverse(std::string& str) {
  std::reverse(std::begin(str), std::end(str));
}

void Solution::lowerStr(std::string& str) {
  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] += 32;
    }
  }
}