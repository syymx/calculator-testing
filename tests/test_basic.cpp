#include <gtest/gtest.h>
#include "calculator.hpp"

// 加法
TEST(CalculatorBasicTest, Addition)
{
    EXPECT_EQ(calculator::eval("1 + 2"), 3);
}

// 减法
TEST(CalculatorBasicTest, Subtraction)
{
    EXPECT_EQ(calculator::eval("10 - 7"), 3);
}

// 乘法
TEST(CalculatorBasicTest, Multiplication)
{
    EXPECT_EQ(calculator::eval("6 * 7"), 42);
}

// 除法
TEST(CalculatorBasicTest, Division)
{
    EXPECT_EQ(calculator::eval("20 / 5"), 4);
}

// 取模
TEST(CalculatorBasicTest, Modulo)
{
    EXPECT_EQ(calculator::eval("20 % 6"), 2);
}

// 负数参与运算
TEST(CalculatorBasicTest, NegativeNumber)
{
    EXPECT_EQ(calculator::eval("-5 + 2"), -3);
}

// 零参与运算
TEST(CalculatorBasicTest, ZeroOperand)
{
    EXPECT_EQ(calculator::eval("0 + 15"), 15);
}