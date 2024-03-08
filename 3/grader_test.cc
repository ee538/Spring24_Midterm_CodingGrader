#include <iostream>
#include <string>

#include "q.h"
#include "gtest/gtest.h"

TEST(CalculatorTest, CalculateAddition) {
  Calculator calc;
  EXPECT_FLOAT_EQ(calc.Calculate(5, 3, Operation::kAdd), 8);
}

TEST(CalculatorTest, CalculateSubtraction) {
  Calculator calc;
  EXPECT_FLOAT_EQ(calc.Calculate(5, 3, Operation::kSubtract), 2);
}

TEST(CalculatorTest, CalculateDivision) {
  Calculator calc;
  EXPECT_FLOAT_EQ(calc.Calculate(10, 2, Operation::kDivision), 5);
}

TEST(CalculatorTest, CalculateDivisionByZero) {
  Calculator calc;
  calc.Calculate(10, 0, Operation::kDivision);
  EXPECT_EQ(calc.error_code, ErrorCode::kDivisionByZero);
}

TEST(CalculatorTest, CalculateMultiplication) {
  Calculator calc;
  EXPECT_FLOAT_EQ(calc.Calculate(5, 3, Operation::kMultiplication), 15);
}

TEST(CalculatorTest, CalculateWithLastResult) {
  Calculator calc;
  calc.Calculate(5, 3, Operation::kAdd);
  EXPECT_FLOAT_EQ(calc.Calculate(2, Operation::kMultiplication), 16);
}

TEST(CalculatorTest, CalculateWithNoPreviousStep) {
  Calculator calc;
  EXPECT_FLOAT_EQ(calc.Calculate(5, Operation::kMultiplication), 0);
}

TEST(CalculatorTest, History) {
  Calculator calc;
  calc.Calculate(10, 0, Operation::kDivision);
  calc.Calculate(5, 3, Operation::kAdd);
  calc.Calculate(10, 2, Operation::kDivision);
  auto history = calc.History(0);
  EXPECT_EQ(history.op1, 10);
  EXPECT_EQ(history.op2, 2);
  EXPECT_EQ(history.operation, Operation::kDivision);
  EXPECT_FLOAT_EQ(history.result, 5);

  history = calc.History(1);
  EXPECT_EQ(history.op1, 5);
  EXPECT_EQ(history.op2, 3);
  EXPECT_EQ(history.operation, Operation::kAdd);
  EXPECT_FLOAT_EQ(history.result, 8);

  history = calc.History(2);
  EXPECT_EQ(history.op1, 10);
  EXPECT_EQ(history.op2, 0);
  EXPECT_EQ(history.operation, Operation::kDivision);
}

TEST(CalculatorTest, CopyConstructor) {
  Calculator calc1;
  calc1.Calculate(5, 3, Operation::kAdd);
  calc1.Calculate(10, 2, Operation::kDivision);

  Calculator calc2(calc1);

  auto history1 = calc1.History(0);
  auto history2 = calc2.History(0);

  EXPECT_EQ(history1.op1, history2.op1);
  EXPECT_EQ(history1.op2, history2.op2);
  EXPECT_EQ(history1.operation, history2.operation);
  EXPECT_FLOAT_EQ(history1.result, history2.result);
  EXPECT_EQ(calc1.error_code, calc2.error_code);
}

TEST(CalculatorTest, InvalidIndexHistory) {
  Calculator calc;
  calc.Calculate(5, 3, Operation::kAdd);
  auto history = calc.History(1);
  EXPECT_EQ(history.op1, 0);
  EXPECT_EQ(history.op2, 0);
  EXPECT_EQ(history.operation, Operation::kAdd);
  EXPECT_FLOAT_EQ(history.result, 0);
  EXPECT_EQ(calc.error_code, ErrorCode::kInvalidIndex);
}
