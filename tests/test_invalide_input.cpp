#include <gtest/gtest.h>

#include "../src/calculator.hpp"

// 空输入
TEST(InvalidInputTest, EmptyInput) {
    EXPECT_THROW(
        calculator::eval(""),
        calculator::error
    );
}

// 纯空白输入
TEST(InvalidInputTest, WhitespaceOnly) {
    EXPECT_THROW(
        calculator::eval("   "),
        calculator::error
    );
}

// 十进制数字含非法字符
TEST(InvalidInputTest, InvalidDecimalNumber) {
    EXPECT_THROW(
        calculator::eval("1z22222"),
        calculator::error
    );
}

// 十六进制含非法字符
TEST(InvalidInputTest, InvalidHexDigit) {
    EXPECT_THROW(
        calculator::eval("0xG1"),
        calculator::error
    );
}

// 十六进制缺少数字
TEST(InvalidInputTest, IncompleteHexNumber) {
    EXPECT_THROW(
        calculator::eval("0x"),
        calculator::error
    );
}

// 非法字符@
TEST(InvalidInputTest, InvalidCharacterAt) {
    EXPECT_THROW(
        calculator::eval("1 @ 2"),
        calculator::error
    );
}

// 不支持逻辑与
TEST(InvalidInputTest, InvalidLogicalAndToken) {
    EXPECT_THROW(
        calculator::eval("1 && 2"),
        calculator::error
    );
}

// 不支持逻辑或
TEST(InvalidInputTest, InvalidLogicalOrToken) {
    EXPECT_THROW(
        calculator::eval("1 || 2"),
        calculator::error
    );
}

// 移位次数等于位宽
TEST(InvalidInputTest, ShiftCountAtBitWidth) {
    EXPECT_THROW(
        calculator::eval("1 << 64"),
        calculator::error
    );

    EXPECT_THROW(
        calculator::eval("1 >> 64"),
        calculator::error
    );
}

// 负数移位
TEST(InvalidInputTest, NegativeShiftCount) {
    EXPECT_THROW(
        calculator::eval("1 << -1"),
        calculator::error
    );
}
