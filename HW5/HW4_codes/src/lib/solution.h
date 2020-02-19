#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <iostream>
#include <queue>
#include <algorithm> 

class Solution {
public:
  std::vector<int> filter(std::vector<int> v);
  std::vector<int> map(std::vector<int> v);
  int reduce(std::vector<int> v);

  void sort(std::vector<int>& v);
  
  int kthLargest(std::vector<int> v, int k);
  
};

#endif