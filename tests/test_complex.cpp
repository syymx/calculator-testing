#include <gtest/gtest.h>
#include "calculator.hpp"

// 十六进制参与运算
TEST(CalculatorComplexTest, HexadecimalExpression)
{
    EXPECT_EQ(calculator::eval("0x10 + 1"), 17);
}

// 幂运算、括号与移位组合
TEST(CalculatorComplexTest, PowerAndShift)
{
    EXPECT_EQ(calculator::eval("(2 ** 3) + (1 << 4)"), 24);
}

// 多种算术运算组合
TEST(CalculatorComplexTest, MixedExpression)
{
    EXPECT_EQ(calculator::eval("5 * (2 + 3) - 10 / 2"), 20);
}