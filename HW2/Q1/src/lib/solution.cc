#include "solution.h"
#include <iostream>

int Solution::add(int a, int b) {
  if (INT32_MAX - a < b || (a < INT32_MIN - b && a < 0 && b < 0)) {
    std::cout << "too large or too small numbers." << std::endl;
    return 0;
  }
  return a + b;
}

std::string Solution::add(std::string a, std::string b) {
  return a + b;
}

std::string Solution::add(std::string a, int b) {
  return a + std::to_string(b);
}

std::string Solution::add(int a, std::string b) {
  return std::to_string(a) + b;
}
