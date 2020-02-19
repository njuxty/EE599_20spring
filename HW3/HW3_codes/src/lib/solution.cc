#include "solution.h"
#include <vector>
#include <iostream>
#include <unordered_map>
#include <stack>

// Q2
std::vector<int> Solution::twoSum(std::vector<int>& nums, int sum) {
  std::unordered_map<int, int> hashmap;
  std::vector<int> result;
  for (int i = 0; i < nums.size(); i++) {
    if (hashmap.find(sum - nums[i]) != hashmap.end() && hashmap[sum - nums[i]] != i) {
      result.push_back(hashmap[sum - nums[i]]);
      result.push_back(i);              
      return result;
    }
    hashmap[nums[i]] = i;
  }
  return result;
}

// Q4
bool Solution::isValidBrackets(std::string s) {
    std::stack<char> sstack;
        
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sstack.push(s[i]);
        } else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (sstack.empty()) return false;
            else if (s[i] == ')' && sstack.top() == '(') sstack.pop();
            else if (s[i] == '}' && sstack.top() == '{') sstack.pop();
            else if (s[i] == ']' && sstack.top() == '[') sstack.pop();
            else return false;
        }
    }
         
    return sstack.empty();
}
