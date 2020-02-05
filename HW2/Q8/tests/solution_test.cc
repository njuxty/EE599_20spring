#include "src/lib/solution.h"
#include "gtest/gtest.h"

TEST(rearrange, oddVectors) {
  Solution solution;
  std::vector<double> v = {637, 231, 123, 43, 69, 43, 900, 10, 7, 21, 99, 0, 500};
  std::vector<double> expected = {43, 43, 21,10, 7, 0, 69, 900, 637, 500, 231, 123, 99};
  double median = solution.rearrange(v);
  double exp = 69;
  EXPECT_EQ(expected, v);
  EXPECT_EQ(exp, median);
}

TEST(rearrange, evenVectors) {
  Solution solution;
  std::vector<double> v = {637, 231, 123, 43, 43, 900, 10, 7, 21, 99, 0, 500};
  std::vector<double> expected = {43, 43, 21,10, 7, 0, 900, 637, 500, 231, 123, 99};
  double median = solution.rearrange(v);
  double exp = 71;
  EXPECT_EQ(expected, v);
  EXPECT_EQ(exp, median);
}

TEST(rearrange, emptyVectors) {
  Solution solution;
  std::vector<double> v = {};
  std::vector<double> expected = {};
  double median = solution.rearrange(v);
  double exp = 0;
  EXPECT_EQ(expected, v);
  EXPECT_EQ(exp, median);
}