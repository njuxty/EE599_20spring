#include "src/lib/solution.h"
#include "gtest/gtest.h"

TEST(add, int_int) {
  Solution solution;
  int a = 33583;
  int b = 60;
  int expected = 33643;
  EXPECT_EQ(expected, solution.add(a, b)); 
}

TEST(add, largeInt_int) {
  Solution solution;
  int a = 8;
  int b = 2147483646;
  int expected = 0;
  EXPECT_EQ(expected, solution.add(a, b)); 
}

TEST(add, smallInt_int) {
  Solution solution;
  int a = -8;
  int b = -2147483645;
  int expected = 0;
  EXPECT_EQ(expected, solution.add(a, b)); 
}

TEST(add, str_str) {
  Solution solution;
  std::string a = "Kobe";
  std::string b = "Byrant"; 
  std::string expected = "KobeByrant";
  EXPECT_EQ(expected, solution.add(a, b));
}

TEST(add, str_emptyStr) {
  Solution solution;
  std::string a = "Kobe";
  std::string b = ""; 
  std::string expected = "Kobe";
  EXPECT_EQ(expected, solution.add(a, b));
}

TEST(add, str_int) {
  Solution solution;
  std::string a = "Kobe";
  int b = 24;
  std::string expected = "Kobe24";
  EXPECT_EQ(expected, solution.add(a, b));
}

TEST(add, int_str) {
  Solution solution;
  int a = 8;
  std::string b = "Kobe"; 
  std::string expected = "8Kobe";
  EXPECT_EQ(expected, solution.add(a, b));
}