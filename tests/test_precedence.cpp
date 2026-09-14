#include <gtest/gtest.h>
#include "calculator.hpp"

// 乘法优先于加法
TEST(CalculatorPrecedenceTest, MultiplicationBeforeAddition)
{
    EXPECT_EQ(calculator::eval("1 + 2 * 3"), 7);
}

// 除法优先于加法
TEST(CalculatorPrecedenceTest, DivisionBeforeAddition)
{
    EXPECT_EQ(calculator::eval("3 + 20 / 5"), 7);
}

// 乘法与加减混合
TEST(CalculatorPrecedenceTest, MixedArithmetic)
{
    EXPECT_EQ(calculator::eval("2 + 3 * 4 - 5"), 9);
}

// 幂运算优先于乘法
TEST(CalculatorPrecedenceTest, PowerBeforeMultiplication)
{
    EXPECT_EQ(calculator::eval("2 ** 3 * 2"), 16);
}