#include "src/lib/solution.h"
#include "src/lib/maxHeap.h"
#include "src/lib/binarySearchTree.h"
#include "gtest/gtest.h"
#include <vector>

// Test for Q1
TEST(filter, true) {
  Solution solution;
  std::vector<int> v = {0,2,1,5,6,3};
  std::vector<int> expected = {0, 2, 6};
  EXPECT_EQ(expected, solution.filter(v)); 
}

TEST(map, true) {
  Solution solution;
  std::vector<int> v = {0,2,1,5,6,3};
  std::vector<int> expected = {0, 4, 1, 25, 36, 9};
  EXPECT_EQ(expected, solution.map(v)); 
}

TEST(reduce, true) {
  Solution solution;
  std::vector<int> v = {0,2,1,5,6,3};
  EXPECT_EQ(17, solution.reduce(v)); 
}

// Test for Q2
MaxHeap heap;
TEST(maxHeap, top_empty) {
  int expected = __INT_MAX__;
  EXPECT_EQ(expected, heap.top()); 
}

TEST(maxHeap, getParentIndex_non) {
  heap.push(21);
  int expected = -1;
  EXPECT_EQ(expected, heap.GetParentIndex(0));
}

TEST(maxHeap, getLeftIndex_non) {
  int expected = -1;
  EXPECT_EQ(expected, heap.GetLeftIndex(0));
}

TEST(maxHeap, getRightIndex_non) {
  int expected = -1;
  EXPECT_EQ(expected, heap.GetRightIndex(0));
}

TEST(maxHeap, getBiggestIndex_non) {
  int expected = -1;
  EXPECT_EQ(expected, heap.GetBiggestChildIndex(0));
}

TEST(maxHeap, push) {
  heap.push(20);
  heap.push(24);
  heap.push(7);
  heap.push(22);
  heap.push(10);
  std::vector<int> expected = {24, 22, 21, 7, 20, 10};
  EXPECT_EQ(expected, heap.testHelper()); 
}

TEST(maxHeap, top_nonempty) {
  int expected = 24;
  EXPECT_EQ(expected, heap.top()); 
}

TEST(maxHeap, getParentIndex) {
  int expected = 1;
  EXPECT_EQ(expected, heap.GetParentIndex(3));
  EXPECT_EQ(expected, heap.GetParentIndex(4));
}

TEST(maxHeap, getLeftIndex) {
  int expected = 5;
  EXPECT_EQ(expected, heap.GetLeftIndex(2));
}

TEST(maxHeap, getRightIndex) {
  int expected = 4;
  EXPECT_EQ(expected, heap.GetRightIndex(1));
}

TEST(maxHeap, getBiggestIndex) {
  int expected = 1;
  EXPECT_EQ(expected, heap.GetBiggestChildIndex(0));
}

TEST(maxHeap, pop) {
  heap.pop();
  std::vector<int> expected = {22, 20, 21, 7, 10};
  EXPECT_EQ(expected, heap.testHelper()); 
}

// Test for Q3
std::vector<int> values  = {54, 5, 67, 22, 13, 100, 63, 43};
BST tree;

TEST(BST, push) {
  tree.push(54);
  tree.push(5);
  tree.push(67);
  tree.push(22);
  tree.push(13);
  tree.push(100);
  tree.push(63);
  tree.push(43);
  std::vector<int> actual = tree.print();
  std::vector<int> expected = {5, 13, 22, 43, 54, 63, 67, 100};
  EXPECT_EQ(expected, actual); 
}

TEST(BST, find_true) {
  EXPECT_EQ(true, tree.find(100)); 
}

TEST(BST, find_false) {
  EXPECT_EQ(false, tree.find(101)); 
}

TEST(BST, erase_false) {
  EXPECT_EQ(false, tree.erase(101)); 
}

TEST(BST, erase_only_has_left) {
  tree.push(60);
  tree.erase(63);
  std::vector<int> actual = tree.print();
  std::vector<int> expected = {5, 13, 22, 43, 54, 60, 67, 100};
  EXPECT_EQ(expected, actual); 
}

TEST(BST, erase_only_has_right) {
  tree.erase(5);
  std::vector<int> actual = tree.print();
  std::vector<int> expected = {13, 22, 43, 54, 60, 67, 100};
  EXPECT_EQ(expected, actual); 
}

TEST(BST, erase_no_child) {
  tree.erase(13);
  std::vector<int> actual = tree.print();
  std::vector<int> expected = {22, 43, 54, 60, 67, 100};
  EXPECT_EQ(expected, actual); 
}

TEST(BST, erase_two_child) {
  tree.push(57);
  tree.erase(67);
  std::vector<int> actual = tree.print();
  std::vector<int> expected = {22, 43, 54, 57, 60, 100};
  EXPECT_EQ(expected, actual); 
}

TEST(BST, erase_root) {
  tree.erase(54);
  std::vector<int> actual = tree.print();
  std::vector<int> expected = {22, 43, 57, 60, 100};
  EXPECT_EQ(expected, actual); 
}

// Test for Q4
TEST(BST, traverse) {
  std::vector<int> actual = tree.traverseByLevel();
  std::vector<int> expected = {57, 22, 100, 43, 60};
  EXPECT_EQ(expected, actual); 
}

// Test for Q5
TEST(sort, true) {
  Solution solution;
  std::vector<int> v = {5, 9, 3, 1, 7};
  solution.sort(v);
  std::vector<int> expected = {1, 3, 5, 7, 9};
  EXPECT_EQ(expected, v); 
}

// Test for Q6
TEST(kthLargest, exist) {
  Solution solution;
  std::vector<int> v = {0,2,1,5,6,3};
  EXPECT_EQ(5, solution.kthLargest(v, 2)); 
}

TEST(kthLargest, nonexist_too_big) {
  Solution solution;
  std::vector<int> v = {0,2,1,5,6,3};
  EXPECT_EQ(__INT_MAX__, solution.kthLargest(v, 8)); 
}

TEST(kthLargest, nonexist_too_small) {
  Solution solution;
  std::vector<int> v = {0,2,1,5,6,3};
  EXPECT_EQ(__INT_MAX__, solution.kthLargest(v, -2)); 
}