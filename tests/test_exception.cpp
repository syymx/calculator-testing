#include <gtest/gtest.h>

#include "../src/calculator.hpp"

// 1. 直接除零
TEST(ExceptionTest, DivisionByZero) {
    EXPECT_ANY_THROW(
        calculator::eval("10 / 0")
    );
}

// 2. 除数由表达式计算得到 0
TEST(ExceptionTest, DivisionByExpressionZero) {
    EXPECT_ANY_THROW(
        calculator::eval("10 / (2 - 2)")
    );
}

// 3. 直接模零
TEST(ExceptionTest, ModuloByZero) {
    EXPECT_ANY_THROW(
        calculator::eval("10 % 0")
    );
}

// 4. 模数由表达式计算得到 0
TEST(ExceptionTest, ModuloByExpressionZero) {
    EXPECT_ANY_THROW(
        calculator::eval("10 % (2 - 2)")
    );
}