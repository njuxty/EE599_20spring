#include "src/lib/solution.h"
#include "src/lib/singlyLinkedList.h"
#include "src/lib/academicRecord.h"
#include "gtest/gtest.h"
#include <vector>

// Test for Q2
TEST(twoSum, two_different_num) {
  Solution solution;
  std::vector<int> v = {3, 7, 11, 15};
  int sum = 10;
  std::vector<int> expected = {0, 1};
  EXPECT_EQ(expected, solution.twoSum(v, sum)); 
}

TEST(twoSum, two_same_num) {
  Solution solution;
  std::vector<int> v = {3, 7, 11, 15, 15};
  int sum = 30;
  std::vector<int> expected = {3, 4};
  EXPECT_EQ(expected, solution.twoSum(v, sum)); 
}

TEST(twoSum, null) {
  Solution solution;
  std::vector<int> v = {3, 7, 11, 15};
  int sum = 1;
  std::vector<int> expected = {};
  EXPECT_EQ(expected, solution.twoSum(v, sum)); 
}

// Test for Q3
TEST(singlyLinkedList, default_constructor_nonpara) {
  SinglyLinkedList ll;
  EXPECT_EQ(nullptr, ll.head_->next);
}

TEST(singlyLinkedList, default_constructor_para_within) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  SinglyLinkedList lll = SinglyLinkedList(v, 2);
  ListNode *p = lll.head_->next->next->next->next->next;
  EXPECT_EQ(2, p->next->val);
}

TEST(singlyLinkedList, default_constructor_para_without) {
  std::vector<int> v = {1, 2, 3, 4, 5};
  SinglyLinkedList ll = SinglyLinkedList(v, 7);
  ListNode *p = ll.GetBackPointer();
  EXPECT_EQ(nullptr, p->next);
}


TEST(singlyLinkedList, empty) {
  SinglyLinkedList ll;
  EXPECT_EQ(true, ll.empty());
}

TEST(singlyLinkedList, not_empty) {
  SinglyLinkedList ll;
  ll.push_back(1);
  EXPECT_EQ(false, ll.empty());
}

TEST(singlyLinkedList, size) {
  SinglyLinkedList ll;
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);
  ll.push_back(6);
  ListNode *p = ll.GetBackPointer();
  ListNode *q = ll.GetIthPointer(3);
  ll.insert_after(p, 7);
  ll.insert_after(q,5);
  ll.push_front(1);
  ll.pop_back();
  ll.pop_front();
  ll.erase(q);
  EXPECT_EQ(4, ll.size());
}

TEST(singlyLinkedList, size_empty) {
  SinglyLinkedList ll;
  EXPECT_EQ(0, ll.size());
}

TEST(singlyLinkedList, push_back) {
  SinglyLinkedList ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);
  EXPECT_EQ(4, ll.back());
  EXPECT_EQ(4, ll.size());
}

TEST(singlyLinkedList, push_front) {
  SinglyLinkedList ll;
  ll.push_back(1);
  ll.push_front(2);
  ll.push_back(3);
  ll.push_front(4);
  EXPECT_EQ(4, ll.front());
  EXPECT_EQ(4, ll.size());
}

TEST(singlyLinkedList, insert_after) {
  SinglyLinkedList ll;
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);
  ll.push_back(6);
  ListNode *q = ll.GetIthPointer(3);
  ll.insert_after(q,5);
  ll.pop_back();
  EXPECT_EQ(5, ll.back());
  EXPECT_EQ(4, ll.size());
}

TEST(singlyLinkedList, erase) {
  SinglyLinkedList ll;
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);
  ll.push_back(5);
  ListNode *q = ll.GetIthPointer(3);
  ll.erase(q);
  EXPECT_EQ(5, ll.back());
  EXPECT_EQ(3, ll.size());
  ll.pop_back();
  EXPECT_EQ(3, ll.back());
  EXPECT_EQ(2, ll.size());
}

TEST(singlyLinkedList, pop_back) {
  SinglyLinkedList ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.pop_back();
  EXPECT_EQ(2, ll.back());
  EXPECT_EQ(2, ll.size());
}

TEST(singlyLinkedList, pop_front) {
  SinglyLinkedList ll;
  ll.push_back(1);
  ll.push_front(2);
  ll.push_back(3);
  ll.push_front(4);
  ll.pop_front();
  EXPECT_EQ(2, ll.front());
  EXPECT_EQ(3, ll.size());
}

TEST(singlyLinkedList, back) {
  SinglyLinkedList ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  EXPECT_EQ(3, ll.back());
}

TEST(singlyLinkedList, front) {
  SinglyLinkedList ll;
  ll.push_back(1);
  ll.push_front(2);
  ll.push_back(3);
  ll.push_front(4);
  EXPECT_EQ(4, ll.front());
}

TEST(singlyLinkedList, back_empty) {
  SinglyLinkedList ll;
  EXPECT_EQ(0, ll.back());
}

TEST(singlyLinkedList, front_empty) {
  SinglyLinkedList ll;
  EXPECT_EQ(0, ll.front());
}

TEST(singlyLinkedList, get_back_pointer) {
  SinglyLinkedList ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  EXPECT_EQ(3, ll.GetBackPointer()->val);
}

TEST(singlyLinkedList, get_ith_pointer) {
  SinglyLinkedList ll;
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);
  ll.push_back(5);
  ListNode *q = ll.GetIthPointer(3);
  EXPECT_EQ(4, q->val);
}

TEST(singlyLinkedList, get_back_pointer_empty) {
  SinglyLinkedList ll;
  EXPECT_EQ(nullptr, ll.GetBackPointer());
}

TEST(singlyLinkedList, get_ith_pointer_empty) {
  SinglyLinkedList ll;
  ListNode *q = ll.GetIthPointer(3);
  EXPECT_EQ(nullptr, q);
}

// Test for Q4
TEST(isValidBrackets, valid) {
  Solution solution;
  std::string str = "(a+b)[c*d]{5g+h}";
  EXPECT_EQ(true, solution.isValidBrackets(str)); 
}

TEST(isValidBrackets, invalid_not_match) {
  Solution solution;
  std::string str = "(7h+[5c)+7]";
  EXPECT_EQ(false, solution.isValidBrackets(str)); 
}

TEST(isValidBrackets, invalid_first_come_right_bracket) {
  Solution solution;
  std::string str = "]343{0";
  EXPECT_EQ(false, solution.isValidBrackets(str)); 
}

TEST(isValidBrackets, empty) {
  Solution solution;
  std::string str = "";
  EXPECT_EQ(true, solution.isValidBrackets(str)); 
}

// Test for Q5
TEST(academicRecord, above_100_postfix) {
  AcademicRecord stu = AcademicRecord(100, 80, 70);
  stu++;
  std::string str = "\nMaths: 100\nComputers: 90\nPhysics: 80";
  EXPECT_EQ(str, stu.print()); 
}

TEST(academicRecord, above_100_prefix) {
  AcademicRecord stu = AcademicRecord(100, 80, 70);
  ++stu;
  std::string str = "\nMaths: 100\nComputers: 90\nPhysics: 80";
  EXPECT_EQ(str, stu.print()); 
}

TEST(academicRecord, below_0_postfix) {
  AcademicRecord stu = AcademicRecord(20, 10, 30);
  stu--;
  std::string str = "\nMaths: 0\nComputers: 0\nPhysics: 10";
  EXPECT_EQ(str, stu.print()); 
}

TEST(academicRecord, below_0_prefix) {
  AcademicRecord stu = AcademicRecord(20, 10, 30);
  --stu;
  std::string str = "\nMaths: 0\nComputers: 0\nPhysics: 10";
  EXPECT_EQ(str, stu.print()); 
}

TEST(academicRecord, operator_postfix_plus) {
  AcademicRecord stu = AcademicRecord(50, 60, 40);
  std::string str = "\nMaths: 50\nComputers: 60\nPhysics: 40";
  EXPECT_EQ(str, stu++.print()); 
}

TEST(academicRecord, operator_postfix_minus) {
  AcademicRecord stu = AcademicRecord(50, 60, 40);
  std::string str = "\nMaths: 50\nComputers: 60\nPhysics: 40";
  EXPECT_EQ(str, stu--.print()); 
}

TEST(academicRecord, operator_plusequal) {
  AcademicRecord stu = AcademicRecord(50, 60, 40);
  stu += 50;
  std::string str = "\nMaths: 100\nComputers: 100\nPhysics: 90";
  EXPECT_EQ(str, stu.print()); 
}

TEST(academicRecord, operator_minusequal) {
  AcademicRecord stu = AcademicRecord(50, 60, 40);
  stu -= 50;
  std::string str = "\nMaths: 0\nComputers: 10\nPhysics: 0";
  EXPECT_EQ(str, stu.print()); 
}

TEST(academicRecord, copy_equalequal) {
  AcademicRecord stu = AcademicRecord(50, 60, 40);
  AcademicRecord stu1 = AcademicRecord(stu);
  EXPECT_EQ(true, stu == stu1);
}