#include <gtest/gtest.h>
#include "calculator.hpp"

// 按位与
TEST(CalculatorBitwiseTest, BitwiseAnd)
{
    EXPECT_EQ(calculator::eval("5 & 3"), 1);
}

// 按位或
TEST(CalculatorBitwiseTest, BitwiseOr)
{
    EXPECT_EQ(calculator::eval("5 | 2"), 7);
}

// 左移
TEST(CalculatorBitwiseTest, LeftShift)
{
    EXPECT_EQ(calculator::eval("1 << 3"), 8);
}

// 右移
TEST(CalculatorBitwiseTest, RightShift)
{
    EXPECT_EQ(calculator::eval("8 >> 2"), 2);
}

// 按位取反
TEST(CalculatorBitwiseTest, BitwiseNot)
{
    EXPECT_EQ(calculator::eval("~0"), -1);
}