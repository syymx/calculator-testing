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
