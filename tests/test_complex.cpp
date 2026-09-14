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

// 科学计数的大小写符号及偶数指数路径
TEST(CalculatorComplexTest, ScientificNotationBothCases)
{
    EXPECT_EQ(calculator::eval("2e2 + 3E1"), 230);
}

// ^ 表示乘方，零的零次方按库约定返回 1
TEST(CalculatorComplexTest, ZeroToZeroPower)
{
    EXPECT_EQ(calculator::eval("0 ^ 0"), 1);
}

// 底数为 1 的快速返回路径
TEST(CalculatorComplexTest, UnitBasePower)
{
    EXPECT_EQ(calculator::eval("1 ** 3"), 1);
}

// 零的正整数次方
TEST(CalculatorComplexTest, ZeroToPositivePower)
{
    EXPECT_EQ(calculator::eval("0 ** 2"), 0);
}

// 零的负整数次方触发除零异常
TEST(CalculatorComplexTest, ZeroToNegativePower)
{
    EXPECT_THROW(calculator::eval("0 ** -1"), calculator::error);
}

// 负一的偶数次方
TEST(CalculatorComplexTest, NegativeUnitEvenPower)
{
    EXPECT_EQ(calculator::eval("(-1) ** 2"), 1);
}

// 负一的奇数次方
TEST(CalculatorComplexTest, NegativeUnitOddPower)
{
    EXPECT_EQ(calculator::eval("(-1) ** 3"), -1);
}

// 整数求值中普通底数的负指数返回 0
TEST(CalculatorComplexTest, IntegerNegativePower)
{
    EXPECT_EQ(calculator::eval("2 ** -1"), 0);
}
