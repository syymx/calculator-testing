#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include <string>

#include "../src/calculator.hpp"

// 十进制上界
TEST(BoundaryTest, Int64Max) {
    EXPECT_EQ(
        calculator::eval("9223372036854775807"),
        std::numeric_limits<std::int64_t>::max()
    );
}

// 十进制上界邻值
TEST(BoundaryTest, NearInt64Max) {
    EXPECT_EQ(
        calculator::eval("9223372036854775806"),
        std::int64_t{9223372036854775806LL}
    );
}

// 加法达到上界
TEST(BoundaryTest, ReachInt64Max) {
    EXPECT_EQ(
        calculator::eval("9223372036854775806 + 1"),
        std::numeric_limits<std::int64_t>::max()
    );
}

// 十进制下界邻值
TEST(BoundaryTest, NearInt64Min) {
    EXPECT_EQ(
        calculator::eval("-9223372036854775807"),
        std::int64_t{-9223372036854775807LL}
    );
}

// 减法达到下界
TEST(BoundaryTest, ReachInt64Min) {
    EXPECT_EQ(
        calculator::eval("-9223372036854775807 - 1"),
        std::numeric_limits<std::int64_t>::min()
    );
}

// 零值
TEST(BoundaryTest, ZeroValue) {
    EXPECT_EQ(calculator::eval("0"), 0);
}

// 十六进制零值
TEST(BoundaryTest, HexZero) {
    EXPECT_EQ(calculator::eval("0x0"), 0);
}

// 十六进制上界邻值
TEST(BoundaryTest, HexNearInt64Max) {
    EXPECT_EQ(
        calculator::eval("0x7FFFFFFFFFFFFFFE"),
        std::int64_t{9223372036854775806LL}
    );
}

// 十六进制上界
TEST(BoundaryTest, HexInt64Max) {
    EXPECT_EQ(
        calculator::eval("0x7FFFFFFFFFFFFFFF"),
        std::numeric_limits<std::int64_t>::max()
    );
}

// 十六进制加法达到上界
TEST(BoundaryTest, HexReachInt64Max) {
    EXPECT_EQ(
        calculator::eval("0x7FFFFFFFFFFFFFFE + 1"),
        std::numeric_limits<std::int64_t>::max()
    );
}

// 十六进制减法达到下界
TEST(BoundaryTest, HexReachInt64Min) {
    EXPECT_EQ(
        calculator::eval("-0x7FFFFFFFFFFFFFFF - 1"),
        std::numeric_limits<std::int64_t>::min()
    );
}

// 左移零位
TEST(BoundaryTest, ShiftByZero) {
    EXPECT_EQ(calculator::eval("1 << 0"), 1);
}

// 左移62位
TEST(BoundaryTest, LargeValidLeftShift) {
    EXPECT_EQ(
        calculator::eval("1 << 62"),
        std::int64_t{4611686018427387904LL}
    );
}

// 右移63位
TEST(BoundaryTest, LargeValidRightShift) {
    EXPECT_EQ(calculator::eval("1 >> 63"), 0);
}

// 最短表达式
TEST(BoundaryTest, MinimumExpressionLength) {
    std::string expr = "1";

    ASSERT_EQ(expr.size(), 1u);
    EXPECT_EQ(calculator::eval(expr), 1);
}

// 表达式长度9998
TEST(BoundaryTest, ExpressionLength9998) {
    std::string expr = "+1";

    for (int i = 0; i < 4998; ++i) {
        expr += "+0";
    }

    ASSERT_EQ(expr.size(), 9998u);
    EXPECT_EQ(calculator::eval(expr), 1);
}

// 表达式长度9999
TEST(BoundaryTest, ExpressionLength9999) {
    std::string expr = "1";

    for (int i = 0; i < 4999; ++i) {
        expr += "+0";
    }

    ASSERT_EQ(expr.size(), 9999u);
    EXPECT_EQ(calculator::eval(expr), 1);
}

// 表达式长度10000
TEST(BoundaryTest, ExpressionLength10000) {
    std::string expr = "+1";

    for (int i = 0; i < 4999; ++i) {
        expr += "+0";
    }

    ASSERT_EQ(expr.size(), 10000u);
    EXPECT_THROW(calculator::eval(expr), calculator::error);
}

// 单层括号
TEST(BoundaryTest, SingleParentheses) {
    EXPECT_EQ(calculator::eval("(1)"), 1);
}

// 百层括号
TEST(BoundaryTest, DeepParentheses) {
    constexpr int depth = 100;

    std::string expr(depth, '(');
    expr += "1";
    expr += std::string(depth, ')');

    EXPECT_EQ(calculator::eval(expr), 1);
}

// 十进制下界直接解析
TEST(BoundaryTest, Int64MinDecimalLiteral) {
    std::int64_t result = 0;

    ASSERT_NO_THROW(
        result = calculator::eval("-9223372036854775808")
    );

    EXPECT_EQ(
        result,
        std::numeric_limits<std::int64_t>::min()
    );
}
