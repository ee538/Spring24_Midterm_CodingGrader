#include <iostream>
#include <vector>

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "q.h"
using ::testing::ElementsAreArray;
//-----------------------------------------------------------------------------s
template <class T>
void PrintCollection(T& input) {
  std::cout << "{ ";
  unsigned int count = 0;
  for (auto n : input) {
    count++;
    std::cout << n;
    if (count < input.size()) std::cout << ", ";
  }
  std::cout << " }" << std::endl;
}
//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
TEST(FindInsertionIndexTest, EmptyVector) {
  std::vector<int> in;
  PrintCollection(in);
  EXPECT_EQ(0, findInsertionIndex(in, 42));
}

TEST(FindInsertionIndexTest, SingleElementVector) {
  std::vector<int> v = {5};
  PrintCollection(v);
  EXPECT_EQ(0, findInsertionIndex(v, 4));
  EXPECT_EQ(0, findInsertionIndex(v, 5));
  EXPECT_EQ(1, findInsertionIndex(v, 6));
}

TEST(FindInsertionIndexTest, MultipleElementVector) {
  std::vector<int> v = {1, 3, 5, 7, 9};
  PrintCollection(v);
  EXPECT_EQ(0, findInsertionIndex(v, 0));
  EXPECT_EQ(1, findInsertionIndex(v, 2));
  EXPECT_EQ(2, findInsertionIndex(v, 4));
  EXPECT_EQ(3, findInsertionIndex(v, 6));
  EXPECT_EQ(4, findInsertionIndex(v, 8));
  EXPECT_EQ(5, findInsertionIndex(v, 10));
}

TEST(FindInsertionIndexTest, MultipleElementVector2) {
  std::vector<int> v = {1, 7};
  PrintCollection(v);
  EXPECT_EQ(1, findInsertionIndex(v, 2));
  EXPECT_EQ(0, findInsertionIndex(v, 1));
  EXPECT_EQ(1, findInsertionIndex(v, 7));
  EXPECT_EQ(2, findInsertionIndex(v, 8));
}
//-----------------------------------------------------------------------------
TEST(MySetTest, EmptySet) {
  MySet s;
  EXPECT_EQ(0, s.size());
  EXPECT_FALSE(s.is_in(55));
  EXPECT_TRUE(s.ConvertToStdVector().empty());
}

TEST(MySetTest, ConstructorWithVector) {
  std::vector<int> v = {2, 3, 1, 5, 4};
  MySet s(v);
  EXPECT_EQ(5, s.size());
  EXPECT_TRUE(s.is_in(1));
  EXPECT_TRUE(s.is_in(2));
  EXPECT_TRUE(s.is_in(3));
  EXPECT_TRUE(s.is_in(4));
  EXPECT_TRUE(s.is_in(5));
  EXPECT_FALSE(s.is_in(0));
  EXPECT_FALSE(s.is_in(6));
  std::vector<int> expected = {1, 2, 3, 4, 5};
  EXPECT_EQ(expected, s.ConvertToStdVector());
}

TEST(MySetTest, ConstructorWithVectorDuplicates) {
  std::vector<int> v = {2, 3, 1, 5, 4, 2, 5, 1, 4};
  MySet s(v);
  EXPECT_EQ(5, s.size());
  EXPECT_TRUE(s.is_in(1));
  EXPECT_TRUE(s.is_in(2));
  EXPECT_TRUE(s.is_in(3));
  EXPECT_TRUE(s.is_in(4));
  EXPECT_TRUE(s.is_in(5));
  EXPECT_FALSE(s.is_in(0));
  EXPECT_FALSE(s.is_in(6));
  std::vector<int> expected = {1, 2, 3, 4, 5};
  EXPECT_EQ(expected, s.ConvertToStdVector());
}

TEST(MySetTest, CopyConstructor) {
  std::vector elements{1, 2, 3};
  MySet s1(elements);
  MySet s2(s1);
  EXPECT_EQ(s1.size(), s2.size());
  EXPECT_EQ(s1.is_in(1), s2.is_in(1));
  EXPECT_EQ(s1.is_in(2), s2.is_in(2));
  EXPECT_EQ(s1.is_in(3), s2.is_in(3));
  EXPECT_EQ(s1.ConvertToStdVector(), s2.ConvertToStdVector());
  s1.insert(4);
  std::vector<int> expected = {1, 2, 3, 4};
  EXPECT_EQ(s1.ConvertToStdVector(), expected);
  expected = {1, 2, 3};
  EXPECT_EQ(s2.ConvertToStdVector(), expected);
}

TEST(MySetTest, Insert) {
  MySet s;
  s.insert(2);
  s.insert(1);
  s.insert(3);
  s.insert(1);
  s.insert(2);
  EXPECT_EQ(3, s.size());
  EXPECT_TRUE(s.is_in(1));
  EXPECT_TRUE(s.is_in(2));
  EXPECT_TRUE(s.is_in(3));
  EXPECT_FALSE(s.is_in(0));
  EXPECT_FALSE(s.is_in(4));
  std::vector<int> expected = {1, 2, 3};
  EXPECT_EQ(expected, s.ConvertToStdVector());
}