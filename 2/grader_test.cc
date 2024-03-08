#include <iostream>
#include <string>

#include "q.h"
#include "gtest/gtest.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------
// Test push_back and front on a non-empty list
TEST(LinkedListBasic, PushBackAndFront) {
  LinkedList list;
  list.push_back(1);
  EXPECT_EQ(1, list.front());
  list.push_back(2);
  EXPECT_EQ(
      1, list.front()); // front should remain the same after another push_back
}

// Test push_back and back for correct behavior
TEST(LinkedListBasic, PushBackAndBack) {
  LinkedList list;
  list.push_back(1);
  EXPECT_EQ(1, list.back());
  list.push_back(2);
  EXPECT_EQ(2, list.back()); // back should update after another push_back
}

// Test pop_back on a list with multiple elements
TEST(LinkedListBasic, PopBack) {
  LinkedList list;
  list.push_back(1);
  list.push_back(2);
  list.pop_back();
  EXPECT_EQ(1, list.back()); // Check if back is correct after pop_back
}

// Test the behavior of front and back on an empty list
TEST(LinkedListBasic, EmptyListFrontAndBack) {
  LinkedList list;
  EXPECT_EQ(-1, list.front()); // front should return -1 on an empty list
  EXPECT_EQ(-1, list.back());  // back should return -1 on an empty list
}

// Test pop_back on an empty list to ensure it doesn't crash
TEST(LinkedListBasic, PopBackEmptyList) {
  LinkedList list;
  list.pop_back();            // Should not crash or throw
  EXPECT_EQ(-1, list.back()); // Ensure back still returns -1 after pop_back on
                              // an empty list
}
