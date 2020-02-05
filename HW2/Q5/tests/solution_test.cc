#include "src/lib/solution.h"
#include "gtest/gtest.h"

TEST(swapChar, string) {
  Solution solution;
  std::string a = "Kobe";
  std::string expected = "oKbe";
  solution.swapChar(a, 0, 1);
  EXPECT_EQ(expected, a); 
}

TEST(swapChar, wrongString) {
  Solution solution;
  std::string a = "";
  std::string expected = "";
  solution.swapChar(a, 0, 1);
  EXPECT_EQ(expected, a); 
}

TEST(swapChar, wrongPosition) {
  Solution solution;
  std::string a = "Kobe";
  std::string expected = "Kobe";
  solution.swapChar(a, 0, 10);
  EXPECT_EQ(expected, a); 
}

TEST(reverse, string) {
  Solution solution;
  std::string a = "Kobe";
  std::string expected = "eboK";
  solution.reverse(a);
  EXPECT_EQ(expected, a);   
}

TEST(reverse, emptyString) {
  Solution solution;
  std::string a = "";
  std::string expected = "";
  solution.reverse(a);
  EXPECT_EQ(expected, a);   
}

TEST(lowerStr, string) {
  Solution solution;
  std::string a = "Kobe";
  std::string expected = "kobe";
  solution.lowerStr(a);
  EXPECT_EQ(expected, a); 
}