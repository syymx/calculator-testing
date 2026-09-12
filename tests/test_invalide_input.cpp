#include <gtest/gtest.h>

#include "../src/calculator.hpp"

// 1. 空输入
TEST(InvalidInputTest, EmptyInput) {
    EXPECT_ANY_THROW(
        calculator::eval("")
    );
}

// 2. 只有空白字符
TEST(InvalidInputTest, WhitespaceOnly) {
    EXPECT_ANY_THROW(
        calculator::eval("   ")
    );
}

// 3. 非法十进制数字：数字中混入非法字符
TEST(InvalidInputTest, InvalidDecimalNumber) {
    EXPECT_ANY_THROW(
        calculator::eval("1z22222")
    );
}

// 4. 非法十六进制数字：G 不属于十六进制字符
TEST(InvalidInputTest, InvalidHexDigit) {
    EXPECT_ANY_THROW(
        calculator::eval("0xG1")
    );
}

// 5. 不完整十六进制数字
TEST(InvalidInputTest, IncompleteHexNumber) {
    EXPECT_ANY_THROW(
        calculator::eval("0x")
    );
}

// 6. 非法字符 @
TEST(InvalidInputTest, InvalidCharacterAt) {
    EXPECT_ANY_THROW(
        calculator::eval("1 @ 2")
    );
}

// 7. 非法字符 $
TEST(InvalidInputTest, InvalidCharacterDollar) {
    EXPECT_ANY_THROW(
        calculator::eval("1 $ 2")
    );
}

// 8. 非法 Token：逻辑与 &&
// Calculator 支持 &，但不应把 && 当作合法运算符
TEST(InvalidInputTest, InvalidLogicalAndToken) {
    EXPECT_ANY_THROW(
        calculator::eval("1 && 2")
    );
}

// 9. 非法 Token：逻辑或 ||
// Calculator 支持 |，但不应把 || 当作合法运算符
TEST(InvalidInputTest, InvalidLogicalOrToken) {
    EXPECT_ANY_THROW(
        calculator::eval("1 || 2")
    );
}