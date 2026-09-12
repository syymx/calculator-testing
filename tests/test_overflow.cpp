#include <gtest/gtest.h>

#include "../src/calculator.hpp"

// ==================== 运算过程溢出 ====================

// 1. 加法溢出：INT64_MAX + 1
TEST(OverflowTest, AdditionOverflow) {
    EXPECT_ANY_THROW(
        calculator::eval("9223372036854775807 + 1")
    );
}

// 2. 减法下溢：结果小于 INT64_MIN
TEST(OverflowTest, SubtractionUnderflow) {
    EXPECT_ANY_THROW(
        calculator::eval("-9223372036854775807 - 2")
    );
}

// 3. 乘法溢出
// 3037000500^2 > INT64_MAX
TEST(OverflowTest, MultiplicationOverflow) {
    EXPECT_ANY_THROW(
        calculator::eval("3037000500 * 3037000500")
    );
}

// 4. 幂运算溢出
// 2^63 = 9223372036854775808 > INT64_MAX
TEST(OverflowTest, PowerOverflow) {
    EXPECT_ANY_THROW(
        calculator::eval("2 ** 63")
    );
}

// 5. 特殊除法溢出
// INT64_MIN / -1 = 9223372036854775808
TEST(OverflowTest, Int64MinDivideNegativeOne) {
    EXPECT_ANY_THROW(
        calculator::eval(
            "(-9223372036854775807 - 1) / -1"
        )
    );
}

// 6. 减法溢出：0 - INT64_MIN
TEST(OverflowTest, ZeroMinusInt64MinOverflow) {
    EXPECT_THROW(
        calculator::eval("0-(-9223372036854775807-1)"),
        calculator::error
    );
}


// ==================== 数字解析 / 进制转换溢出 ====================

// 7. 十进制数字转换溢出
// 第一个超过 INT64_MAX 的正整数
TEST(OverflowTest, DecimalConversionOverflow) {
    EXPECT_ANY_THROW(
        calculator::eval("9223372036854775808")
    );
}

// 8. 十六进制数字转换溢出
// 0x7FFFFFFFFFFFFFFF 是 INT64_MAX
// 因此 0x8000000000000000 为第一个越界值
TEST(OverflowTest, HexConversionOverflow) {
    EXPECT_ANY_THROW(
        calculator::eval("0x8000000000000000")
    );
}
