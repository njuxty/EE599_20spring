#include "src/lib/solution.h"
#include "gtest/gtest.h"

TEST(mappable, true) {
  Solution solution;
  std::string str1 = "Kobe24Kobe";
  std::string str2 = "Byrant";
  std::string str3 = "Kobe24";
  std::map<char, char> expected = {std::pair<char,char>('K','B'),std::pair<char,char>('o','y'),std::pair<char,char>('b','r'),
  std::pair<char,char>('e','a'),std::pair<char,char>('2','n'),std::pair<char,char>('4','t')};
  EXPECT_EQ(expected, solution.mappable(str1, str2));
  EXPECT_EQ(expected, solution.mappable(str3, str2));
}

TEST(mappable, false) {
  Solution solution;
  std::string str1 = "Kobe24kobe";
  std::string str2 = "Byrant";
  std::map<char, char> expected = {};
  EXPECT_EQ(expected, solution.mappable(str1, str2));
}
