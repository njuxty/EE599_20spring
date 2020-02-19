#include "solution.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

bool isEven(int i) {
  return ((i % 2) == 0);
}

int square(int i) {
  return i * i;
}

std::vector<int> Solution::filter(std::vector<int> v) {
  std::vector<int> result (v.size());
  auto it = std::copy_if(v.begin(), v.end(), result.begin(), isEven);
  result.resize(std::distance(result.begin(),it));
  return result;
}

std::vector<int> Solution::map(std::vector<int> v) {
  std::vector<int> result(v.size());
  std::transform(v.begin(), v.end(), result.begin(), square);
  return result;
}

int Solution::reduce(std::vector<int> v) {
  int sum = std::accumulate(v.begin(), v.end(), 0);
  return sum;
}

void Solution::sort(std::vector<int>& v) {
  int vsize = v.size();
  if (vsize <= 1) return;

  std::priority_queue<int, std::vector<int>, std::greater<int>> p;
  for (int i = vsize - 1; i >= 0; i -= 1) {
    p.push(v.at(i));
    v.pop_back();
  }
  for (int i = 0; i < vsize; i += 1) {
    v.push_back(p.top());
    p.pop();
  }
}

int Solution::kthLargest(std::vector<int> v, int k) {
  if (k > v.size() || k < 1) {
    std::cout << "Ineffective k!" << std::endl;
    return __INT_MAX__;
  }

  std::priority_queue<int, std::vector<int>, std::greater<int>> p;
  for (int i = 0; i < v.size(); i += 1) {
    if (p.size() < k) {
      p.push(v.at(i));
    } else {
      if (v.at(i) > p.top()) {
        p.pop();
        p.push(v.at(i));
      }
    }
  }
  return p.top();
}


