#include <gtest/gtest.h>
#include <cstdint>
#include <limits>
#include <string>

#include "../src/calculator.hpp"

// ==================== 1. 十进制 int64 边界 ====================

// INT64_MAX
TEST(BoundaryTest, Int64Max) {
    EXPECT_EQ(
        calculator::eval("9223372036854775807"),
        std::numeric_limits<std::int64_t>::max()
    );
}

// INT64_MAX - 1
TEST(BoundaryTest, NearInt64Max) {
    EXPECT_EQ(
        calculator::eval("9223372036854775806"),
        std::int64_t{9223372036854775806LL}
    );
}

// 运算结果恰好达到 INT64_MAX
TEST(BoundaryTest, ReachInt64Max) {
    EXPECT_EQ(
        calculator::eval("9223372036854775806 + 1"),
        std::numeric_limits<std::int64_t>::max()
    );
}

// INT64_MIN + 1
TEST(BoundaryTest, NearInt64Min) {
    EXPECT_EQ(
        calculator::eval("-9223372036854775807"),
        std::int64_t{-9223372036854775807LL}
    );
}

// 运算结果恰好达到 INT64_MIN
TEST(BoundaryTest, ReachInt64Min) {
    EXPECT_EQ(
        calculator::eval("-9223372036854775807 - 1"),
        std::numeric_limits<std::int64_t>::min()
    );
}


// ==================== 2. 零值边界 ====================

TEST(BoundaryTest, ZeroValue) {
    EXPECT_EQ(calculator::eval("0"), 0);
}


// ==================== 3. 十六进制边界 ====================

// 十六进制最小值
TEST(BoundaryTest, HexZero) {
    EXPECT_EQ(calculator::eval("0x0"), 0);
}

// 十六进制 INT64_MAX - 1
TEST(BoundaryTest, HexNearInt64Max) {
    EXPECT_EQ(
        calculator::eval("0x7FFFFFFFFFFFFFFE"),
        std::int64_t{9223372036854775806LL}
    );
}

// 十六进制最大合法正 int64
TEST(BoundaryTest, HexInt64Max) {
    EXPECT_EQ(
        calculator::eval("0x7FFFFFFFFFFFFFFF"),
        std::numeric_limits<std::int64_t>::max()
    );
}

// 十六进制运算结果达到 INT64_MAX
TEST(BoundaryTest, HexReachInt64Max) {
    EXPECT_EQ(
        calculator::eval("0x7FFFFFFFFFFFFFFE + 1"),
        std::numeric_limits<std::int64_t>::max()
    );
}

// 十六进制参与运算得到 INT64_MIN
TEST(BoundaryTest, HexReachInt64Min) {
    EXPECT_EQ(
        calculator::eval("-0x7FFFFFFFFFFFFFFF - 1"),
        std::numeric_limits<std::int64_t>::min()
    );
}


// ==================== 4. 移位边界 ====================

// 最小合法移位量 0
TEST(BoundaryTest, ShiftByZero) {
    EXPECT_EQ(calculator::eval("1 << 0"), 1);
}

// 大的合法左移，结果仍在 int64 正数范围
TEST(BoundaryTest, LargeValidLeftShift) {
    EXPECT_EQ(
        calculator::eval("1 << 62"),
        std::int64_t{4611686018427387904LL}
    );
}

// 64 位整数最大的合法移位次数边界
TEST(BoundaryTest, LargeValidRightShift) {
    EXPECT_EQ(calculator::eval("1 >> 63"), 0);
}


// ==================== 5. 表达式长度边界 ====================

// 最短合法表达式：长度为 1
TEST(BoundaryTest, MinimumExpressionLength) {
    std::string expr = "1";

    ASSERT_EQ(expr.size(), 1u);
    EXPECT_EQ(calculator::eval(expr), 1);
}

// 最大长度附近：9998
TEST(BoundaryTest, ExpressionLength9998) {
    // "+1" + 4998 个 "+0"
    // 2 + 4998 * 2 = 9998
    std::string expr = "+1";

    for (int i = 0; i < 4998; ++i) {
        expr += "+0";
    }

    ASSERT_EQ(expr.size(), 9998u);
    EXPECT_EQ(calculator::eval(expr), 1);
}

// 最大合法长度：9999
TEST(BoundaryTest, ExpressionLength9999) {
    // "1" + 4999 个 "+0"
    // 1 + 4999 * 2 = 9999
    std::string expr = "1";

    for (int i = 0; i < 4999; ++i) {
        expr += "+0";
    }

    ASSERT_EQ(expr.size(), 9999u);
    EXPECT_EQ(calculator::eval(expr), 1);
}

// 第一个非法长度：10000
TEST(BoundaryTest, ExpressionLength10000) {
    // "+1" + 4999 个 "+0"
    // 2 + 4999 * 2 = 10000
    std::string expr = "+1";

    for (int i = 0; i < 4999; ++i) {
        expr += "+0";
    }

    ASSERT_EQ(expr.size(), 10000u);
    EXPECT_ANY_THROW(calculator::eval(expr));
}


// ==================== 6. 括号深度边界 ====================

// 最小括号嵌套
TEST(BoundaryTest, SingleParentheses) {
    EXPECT_EQ(calculator::eval("(1)"), 1);
}

// 深层括号嵌套鲁棒性
TEST(BoundaryTest, DeepParentheses) {
    constexpr int depth = 100;

    std::string expr(depth, '(');
    expr += "1";
    expr += std::string(depth, ')');

    EXPECT_EQ(calculator::eval(expr), 1);
}