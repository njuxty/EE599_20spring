#include "src/lib/solution.h"
#include "gtest/gtest.h"

TEST(swap, reference) {
  Solution solution;
  int a = 8;
  int b = 24;
  solution.swapByReference(a, b);
  EXPECT_EQ(24, a); 
  EXPECT_EQ(8, b);
}

TEST(swap, pointer) {
  Solution solution;
  int a = 8;
  int b = 24;
  solution.swapByPointers(&a, &b);
  EXPECT_EQ(24, a); 
  EXPECT_EQ(8, b);
}