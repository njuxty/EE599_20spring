#include "solution.h"
#include <map>

void removeDuplicates(std::string& v) {
  int length = v.size();
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

std::map<char, char> Solution::mappable(std::string str1, std::string str2) {
  int length1 = str1.size();
  int length2 = str2.size();
  std::map<char, char> mmap;
  if (length1 == 0 || length2 == 0) return mmap;

  removeDuplicates(str1);
  removeDuplicates(str2);
  length1 = str1.size();
  length2 = str2.size();
  if (length1 != length2) return mmap;
  for (int i = 0; i < length1; i ++) {
    mmap[str1[i]] = str2[i];
  }
  return mmap;
}
