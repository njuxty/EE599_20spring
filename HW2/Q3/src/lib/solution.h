#ifndef TEMPLATE_SOLUTION_H
#define TEMPLATE_SOLUTION_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <set>

class Solution {
public:
  void removeDuplicates(std::vector<int>& v);
  void removeDuplicatesUsingSet(std::vector<int>& v);
  void reverse(std::vector<int>& v);
  void removeOddNumbers(std::vector<int>& v);
  std::vector<int> concatenate(std::vector<int> v1, std::vector<int> v2);
  std::vector<int> unionValues(std::vector<int> v1, std::vector<int> v2);
};

void Solution::removeDuplicates(std::vector<int>& v) {
  int length = v.size();
  if (length < 1) {
    std::cout << "The vector is null." << std::endl;
    return;
  }

  int mark = 0;
  std::unordered_map<int, int> map;
  for (int i = 0; i < length; i++) {
    if (map.find(v[i]) == map.end()) {
      map[v[i]] = 1;
      v[mark] = v[i];
      mark += 1;
    }
  }

  for (int j = mark; j < length; j++) {
    v.pop_back();
  }
  return;
}

void Solution::removeDuplicatesUsingSet(std::vector<int>& v) {
  int length = v.size();
  if (length < 1) {
    std::cout << "The vector is null." << std::endl;
    return;
  }

  int mark = 0;
  std::set<int> sset;
  for (int i = 0; i < length; i++) {
    if (sset.find(v[i]) == sset.end()) {
      sset.insert(v[i]);
      v[mark] = v[i];
      mark += 1;
    }
  }

  for (int j = mark; j < length; j++) {
    v.pop_back();
  }
  return;
}

void Solution::reverse(std::vector<int>& v) {
  std::reverse(std::begin(v), std::end(v));
}

void Solution::removeOddNumbers(std::vector<int>& v) {
  int length = v.size();
  if (length < 1) {
    std::cout << "The vector is null." << std::endl;
    return;
  }

  int mark = 0;
  for (int i = 0; i < length; i++) {
    if (v[i] % 2 == 0) {
      v[mark] = v[i];
      mark += 1;
    }
  }

  for (int j = mark; j < length; j++) {
    v.pop_back();
  }
  return;
}

std::vector<int> Solution::concatenate(std::vector<int> v1, std::vector<int> v2) {
  std::vector<int> v;
  int length1 = v1.size();
  int length2 = v2.size();
  if (length1 == 0 && length2 == 0) return v;
  if (length1 == 0) {
    return v = v2;
  }
  if (length2 == 0) {
    return v = v1;
  }

  for (int i = 0; i < length1; i++) {
    v.push_back(v1[i]);
  } 

  for (int j = 0; j < length2; j++) {
    v.push_back(v2[j]);
  } 

  return v;
}

std::vector<int> Solution::unionValues(std::vector<int> v1, std::vector<int> v2) {
  int length1 = v1.size();
  int length2 = v2.size();
  std::vector<int> v;
  if (length1 == 0 || length2 == 0) {
    return v;
  }
  std::sort(v1.begin(), v1.end());
  std::sort(v2.begin(), v2.end());
  
  int i = 0;
  int j = 0;
  while (i < length1 && j < length2) {
    if (v1[i] == v2[j]) {
      v.push_back(v1[i]);
      i += 1;
      j += 1;
    } else if (v1[i] > v2[j]) {
      j += 1;
    } else i += 1;
  }
  Solution::removeDuplicates(v);
  return v;
}

#endif