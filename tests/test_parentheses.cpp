#include <gtest/gtest.h>
#include "calculator.hpp"

// 括号改变运算顺序
TEST(CalculatorParenthesesTest, ChangePrecedence)
{
    EXPECT_EQ(calculator::eval("(1 + 2) * 3"), 9);
}

// 多层括号
TEST(CalculatorParenthesesTest, NestedParentheses)
{
    EXPECT_EQ(calculator::eval("((2 + 3) * 4)"), 20);
}

// 减法与括号
TEST(CalculatorParenthesesTest, SubtractionWithParentheses)
{
    EXPECT_EQ(calculator::eval("10 - (2 + 3)"), 5);
}

// 括号整体取负
TEST(CalculatorParenthesesTest, NegativeParentheses)
{
    EXPECT_EQ(calculator::eval("-(2 + 3)"), -5);
}