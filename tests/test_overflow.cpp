#include <gtest/gtest.h>

#include "../src/calculator.hpp"

// 加法溢出
TEST(OverflowTest, AdditionOverflow) {
    EXPECT_THROW(
        calculator::eval("9223372036854775807 + 1"),
        calculator::error
    );
}

// 减法下溢
TEST(OverflowTest, SubtractionUnderflow) {
    EXPECT_THROW(
        calculator::eval("-9223372036854775807 - 2"),
        calculator::error
    );
}

// 乘法溢出
TEST(OverflowTest, MultiplicationOverflow) {
    EXPECT_THROW(
        calculator::eval("3037000500 * 3037000500"),
        calculator::error
    );
}

// 幂运算溢出
TEST(OverflowTest, PowerOverflow) {
    EXPECT_THROW(
        calculator::eval("2 ** 63"),
        calculator::error
    );
}

// 最小整数除以负一
TEST(OverflowTest, Int64MinDivideNegativeOne) {
    EXPECT_THROW(
        calculator::eval(
            "(-9223372036854775807 - 1) / -1"
        ),
        calculator::error
    );
}

// 零减最小整数溢出
TEST(OverflowTest, ZeroMinusInt64MinOverflow) {
    EXPECT_THROW(
        calculator::eval("0-(-9223372036854775807-1)"),
        calculator::error
    );
}

// 十进制解析溢出
TEST(OverflowTest, DecimalConversionOverflow) {
    EXPECT_THROW(
        calculator::eval("9223372036854775808"),
        calculator::error
    );
}

// 十六进制解析溢出
TEST(OverflowTest, HexConversionOverflow) {
    EXPECT_THROW(
        calculator::eval("0x8000000000000000"),
        calculator::error
    );
}

// 两个负数相加下溢；通过表达式构造最小值，避开字面量解析缺陷
TEST(OverflowTest, NegativeAdditionUnderflow) {
    EXPECT_THROW(
        calculator::eval("(-9223372036854775807 - 1) + (-1)"),
        calculator::error
    );
}

// 正数减负数的正向溢出，与零减最小值的用例对应不同条件
TEST(OverflowTest, PositiveMinusInt64MinOverflow) {
    EXPECT_THROW(
        calculator::eval("1 - (-9223372036854775807 - 1)"),
        calculator::error
    );
}

// 正数乘负数的下溢检查
TEST(OverflowTest, PositiveTimesNegativeUnderflow) {
    EXPECT_THROW(
        calculator::eval("2 * (-9223372036854775807 - 1)"),
        calculator::error
    );
}

// 负数乘正数走独立的下溢检查分支
TEST(OverflowTest, NegativeTimesPositiveUnderflow) {
    EXPECT_THROW(
        calculator::eval("(-9223372036854775807 - 1) * 2"),
        calculator::error
    );
}

// 两个负数相乘的一般溢出检查
TEST(OverflowTest, NegativeTimesNegativeOverflow) {
    EXPECT_THROW(
        calculator::eval("(-3037000500) * (-3037000500)"),
        calculator::error
    );
}

// 最小值位于左操作数时的特殊乘法溢出检查
TEST(OverflowTest, Int64MinTimesNegativeOne) {
    EXPECT_THROW(
        calculator::eval("(-9223372036854775807 - 1) * (-1)"),
        calculator::error
    );
}

// 最小值位于右操作数时走另一条特殊乘法检查分支
TEST(OverflowTest, NegativeOneTimesInt64Min) {
    EXPECT_THROW(
        calculator::eval("(-1) * (-9223372036854775807 - 1)"),
        calculator::error
    );
}

// 最小值模负一按库的安全检查规则抛出异常
TEST(OverflowTest, Int64MinModuloNegativeOne) {
    EXPECT_THROW(
        calculator::eval("(-9223372036854775807 - 1) % (-1)"),
        calculator::error
    );
}

// 对已计算得到的最小值取负，检查一元负号的溢出保护
TEST(OverflowTest, NegateInt64MinOverflow) {
    EXPECT_THROW(
        calculator::eval("-(-9223372036854775807 - 1)"),
        calculator::error
    );
}
