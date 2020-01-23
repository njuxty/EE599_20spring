#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(HelloWorldShould, ReturnHelloWorld) {
  Solution solution;
  std::string actual = solution.PrintHelloWorld();
  std::string expected = "**** My name is Tianyi and I like Pokemon! ****";
  EXPECT_EQ(expected, actual);
}

TEST(FactorialTest, HandlesPositiveNumber) {
  Solution solution;
  int inputs = 5;
  EXPECT_EQ(solution.Factorial(inputs), 120);
}

TEST(FactorialTest, HandlesZero) {
  Solution solution;
  int inputs = 0;
  EXPECT_EQ(solution.Factorial(inputs), 1);
}

TEST(FactorialTest, HandlesNegativeNumber) {
  Solution solution;
  int inputs = -17;
  EXPECT_EQ(solution.Factorial(inputs), -1);
}

TEST(FactorialRecursiveTest, HandlesPositiveNumber) {
  Solution solution;
  int inputs = 5;
  EXPECT_EQ(solution.FactorialRecursive(inputs), 120);
}

TEST(FactorialRecursiveTest, HandlesZero) {
  Solution solution;
  int inputs = 0;
  EXPECT_EQ(solution.FactorialRecursive(inputs), 1);
}

TEST(FactorialRecursiveTest, HandlesNegativeNumber) {
  Solution solution;
  int inputs = -17;
  EXPECT_EQ(solution.FactorialRecursive(inputs), -1);
}