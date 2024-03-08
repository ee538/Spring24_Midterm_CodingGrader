#include <iostream>
#include <string>

#include "q.h"
#include "gtest/gtest.h"

//-----------------------------------------------------------------------------
// Write some test cases for each function.
//-----------------------------------------------------------------------------

// Google Test cases
TEST(evaluateExpressionTest, HandlesSimpleExpressions) {
  EXPECT_EQ(evaluateExpression("1+1+1-1"), 2);
  EXPECT_EQ(evaluateExpression("1-0+0-1"), 0);
}

TEST(evaluateExpressionTest, HandlesExpressionsWithSpaces) {
  EXPECT_EQ(evaluateExpression("1 + 1 - 1 + 1"), 2);
  EXPECT_EQ(evaluateExpression("1 - 1 + 1 - 1"), 0);
}

TEST(evaluateExpressionTest, HandlesExpressionsWithLeadingOperator) {
  EXPECT_EQ(evaluateExpression("+1-1+1-1"), 0);
  EXPECT_EQ(evaluateExpression("-1+1-1+1"), 0);
}

TEST(evaluateExpressionTest, HandlesEmpty) {
  EXPECT_EQ(evaluateExpression(""), 0);
}
