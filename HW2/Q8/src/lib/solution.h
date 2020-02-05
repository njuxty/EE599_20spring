#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

class Solution {
public:
  double rearrange(std::vector<double>& v);
};

double Solution::rearrange(std::vector<double>& v) {
  int length = v.size();
  if (length < 1) return 0;

  std::sort(v.begin(), v.end());
  double median;
  std::reverse(v.begin(), v.end());
  if (length % 2 == 0) {
    median = (v[length/2] + v[length/2-1]) / 2;
    std::swap_ranges(v.begin(), v.begin() + length/2, v.begin() + length/2);
  } else {
    median = v[length/2];
    std::swap_ranges(v.begin(), v.begin() + length/2, v.begin() + length/2 + 1);
  }
  return median;
}


#endif