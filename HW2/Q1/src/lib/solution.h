#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>

class Solution {
public:
  int add(int a, int b);
  std::string add(std::string a, std::string b);
  std::string add(std::string a, int b);
  std::string add(int a, std::string b);
};

#endif