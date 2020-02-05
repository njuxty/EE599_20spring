#include "src/lib/solution.h"
#include "gtest/gtest.h"

TEST(removeDuplicates, vector) {
  Solution solution;
  std::vector<int> v = {3, 5, 1, 7, 24, 8, 1, 8};
  std::vector<int> expected = {3, 5, 1, 7, 24, 8};
  solution.removeDuplicates(v);
  EXPECT_EQ(expected, v); 
}

TEST(removeDuplicates, emptyVector) {
  Solution solution;
  std::vector<int> v = {};
  std::vector<int> expected = {};
  solution.removeDuplicates(v);
  EXPECT_EQ(expected, v); 
}

TEST(removeDuplicatesUsingSet, vector) {
  Solution solution;
  std::vector<int> v = {3, 5, 1, 7, 24, 8, 1, 8};
  std::vector<int> expected = {3, 5, 1, 7, 24, 8};
  solution.removeDuplicatesUsingSet(v);
  EXPECT_EQ(expected, v); 
}

TEST(removeDuplicatesUsingSet, emptyVector) {
  Solution solution;
  std::vector<int> v = {};
  std::vector<int> expected = {};
  solution.removeDuplicatesUsingSet(v);
  EXPECT_EQ(expected, v); 
}

TEST(reverse, vector) {
  Solution solution;
  std::vector<int> v = {8, 24};
  std::vector<int> expected = {24, 8};
  solution.reverse(v);
  EXPECT_EQ(expected, v); 
}

TEST(removeOdd, vector) {
  Solution solution;
  std::vector<int> v = {8, 24, 7};
  std::vector<int> expected = {8, 24};
  solution.removeOddNumbers(v);
  EXPECT_EQ(expected, v); 
}

TEST(removeOdd, emptyVector) {
  Solution solution;
  std::vector<int> v = {};
  std::vector<int> expected = {};
  solution.removeOddNumbers(v);
  EXPECT_EQ(expected, v); 
}

TEST(concatenate, vector) {
  Solution solution;
  std::vector<int> v1 = {8, 24};
  std::vector<int> v2 = {33643};
  std::vector<int> expected = {8, 24, 33643};
  EXPECT_EQ(expected, solution.concatenate(v1, v2)); 
}

TEST(concatenate, emptyVector) {
  Solution solution;
  std::vector<int> v1 = {8, 24};
  std::vector<int> v2 = {};
  std::vector<int> expected = {8, 24};
  EXPECT_EQ(expected, solution.concatenate(v1, v2)); 
}

TEST(union, vector) {
  Solution solution;
  std::vector<int> v1 = {8, 24};
  std::vector<int> v2 = {24};
  std::vector<int> expected = {24};
  EXPECT_EQ(expected, solution.unionValues(v1, v2)); 
}

TEST(union, duplicatedVector) {
  Solution solution;
  std::vector<int> v1 = {8, 8, 24, 33643};
  std::vector<int> v2 = {8, 8, 24, 81};
  std::vector<int> expected = {8 ,24};
  EXPECT_EQ(expected, solution.unionValues(v1, v2)); 
}

TEST(union, emptyVector) {
  Solution solution;
  std::vector<int> v1 = {8, 24};
  std::vector<int> v2 = {};
  std::vector<int> expected = {};
  EXPECT_EQ(expected, solution.unionValues(v1, v2)); 
}