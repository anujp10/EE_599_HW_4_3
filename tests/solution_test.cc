#include "src/lib/solution.h"
#include "gtest/gtest.h"
#include <vector>

TEST(BSTShould, BSTReturn) {
  BST tree;
  tree.push(10);
  bool actual = tree.find(50);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(BSTShould_1, BSTReturn_1) {
  BST tree;
  tree.push(10);
  bool actual = tree.find(10);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

TEST(BSTShould_2, BSTReturn_2) {
  BST tree;
  tree.push(10);
  tree.push(20);
  tree.push(30);
  tree.push(40);
  tree.push(50);
  bool actual = tree.find(50);
  bool expected = true;
  EXPECT_EQ(expected, actual);
}

TEST(BSTShould_3, BSTReturn_3) {
  BST tree;
  tree.push(10);
  tree.push(20);
  tree.push(30);
  tree.push(40);
  tree.push(50);
  tree.erase(50);
  bool actual = tree.find(50);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(BSTShould_4, BSTReturn_4) {
  BST tree;
  bool actual = tree.find(50);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}

TEST(BSTShould_5, BSTReturn_5) {
  BST tree;
  bool actual = tree.erase(50);
  bool expected = false;
  EXPECT_EQ(expected, actual);
}