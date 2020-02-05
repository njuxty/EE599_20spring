#include "src/lib/solution.h"
#include "gtest/gtest.h"

TEST(simplePali, truePali) {
  Solution solution;
  std::string str = "KobeeboK";
  std::string str1 = "Kobe8eboK";
  int expected = 1;
  EXPECT_EQ(expected, solution.simplePalindrome(str)); 
  EXPECT_EQ(expected, solution.simplePalindrome(str1));
}

TEST(simplePali, falsePali) {
  Solution solution;
  std::string str = "Kobe";
  std::string str1 = "rwtrtr4534(*^&&(";
  int expected = 0;
  EXPECT_EQ(expected, solution.simplePalindrome(str)); 
  EXPECT_EQ(expected, solution.simplePalindrome(str1));
}

TEST(approPali, truePali) {
  Solution solution;
  std::string str = "%$#^%^&^&%%*^*  16524215631&*^";
  std::string str1 = "A man, a plan, a canal, Panama!";
  int expected = 1;
  EXPECT_EQ(expected, solution.approximatePalindrome(str)); 
  EXPECT_EQ(expected, solution.approximatePalindrome(str1));
}

TEST(approPali, falsePali) {
  Solution solution;
  std::string str = "Kobe";
  std::string str1 = "rwtrtr4534(*^&&(";
  int expected = 0;
  EXPECT_EQ(expected, solution.approximatePalindrome(str)); 
  EXPECT_EQ(expected, solution.approximatePalindrome(str1));
}