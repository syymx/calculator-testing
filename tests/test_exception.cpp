#include <gtest/gtest.h>

#include "../src/calculator.hpp"

// 直接除零
TEST(ExceptionTest, DivisionByZero) {
    EXPECT_THROW(
        calculator::eval("10 / 0"),
        calculator::error
    );
}

// 表达式除零
TEST(ExceptionTest, DivisionByExpressionZero) {
    EXPECT_THROW(
        calculator::eval("10 / (2 - 2)"),
        calculator::error
    );
}

// 直接模零
TEST(ExceptionTest, ModuloByZero) {
    EXPECT_THROW(
        calculator::eval("10 % 0"),
        calculator::error
    );
}

// 表达式模零
TEST(ExceptionTest, ModuloByExpressionZero) {
    EXPECT_THROW(
        calculator::eval("10 % (2 - 2)"),
        calculator::error
    );
}
