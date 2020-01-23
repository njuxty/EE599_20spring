#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(FindMedianTest, HandlesConsecutiveNumbersOddLength) {
  Solution solution;
  std::vector<double> inputs = {1, 3, 3, 6, 7, 8, 9};
  EXPECT_EQ(solution.FindMedian(inputs), 6);
}

TEST(FindMedianTest, HandlesConsecutiveNumbersEvenLength) {
  Solution solution;
  std::vector<double> inputs = {1, 2, 3, 4, 5, 6, 8, 9};
  EXPECT_EQ(solution.FindMedian(inputs), 4.5);
}

TEST(FindMedianTest, HandlesSizeOne) {
  Solution solution;
  std::vector<double> inputs = {2};
  EXPECT_EQ(solution.FindMedian(inputs), 2);
}

TEST(FindMedianTest, HandlesEmptyVector) {
  Solution solution;
  std::vector<double> inputs = {};
  EXPECT_EQ(solution.FindMedian(inputs), -1);
}
