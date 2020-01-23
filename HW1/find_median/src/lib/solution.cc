#include "solution.h"
#include <iostream>
double Solution::FindMedian(std::vector<double> &inputs) {
  if (inputs.size() == 0) {
    return -1;
  }

  int left = 0;
  int right = inputs.size() - 1;
  while (left < right) {
    left += 1;
    right -= 1;
  }
  
  if (left == right) return inputs[left];
  else return (inputs[left] + inputs[right]) / 2;
}