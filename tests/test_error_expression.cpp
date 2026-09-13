#include <gtest/gtest.h>

#include "../src/calculator.hpp"

// 缺少右操作数
TEST(ErrorExpressionTest, MissingRightOperand) {
    EXPECT_THROW(
        calculator::eval("1 +"),
        calculator::error
    );
}

// 缺少左操作数
TEST(ErrorExpressionTest, MissingLeftOperand) {
    EXPECT_THROW(
        calculator::eval("* 2"),
        calculator::error
    );
}

// 运算符后缺少操作数
TEST(ErrorExpressionTest, MissingOperandAfterOperator) {
    EXPECT_THROW(
        calculator::eval("1 + * 2"),
        calculator::error
    );
}

// 缺少右括号
TEST(ErrorExpressionTest, MissingRightParenthesis) {
    EXPECT_THROW(
        calculator::eval("(1 + 2"),
        calculator::error
    );
}

// 多余右括号
TEST(ErrorExpressionTest, ExtraRightParenthesis) {
    EXPECT_THROW(
        calculator::eval("1 + 2)"),
        calculator::error
    );
}

// 空括号
TEST(ErrorExpressionTest, EmptyParentheses) {
    EXPECT_THROW(
        calculator::eval("()"),
        calculator::error
    );
}

// 乘除运算符相邻
TEST(ErrorExpressionTest, ConsecutiveMultiplyDivide) {
    EXPECT_THROW(
        calculator::eval("1 * / 2"),
        calculator::error
    );
}

// 连续三个星号
TEST(ErrorExpressionTest, TripleAsterisk) {
    EXPECT_THROW(
        calculator::eval("1 *** 2"),
        calculator::error
    );
}

// 操作数间缺少运算符
TEST(ErrorExpressionTest, MissingOperatorBetweenOperands) {
    EXPECT_THROW(
        calculator::eval("1 2"),
        calculator::error
    );
}

// 括号间缺少运算符
TEST(ErrorExpressionTest, MissingOperatorBetweenParentheses) {
    EXPECT_THROW(
        calculator::eval("(1)(2)"),
        calculator::error
    );
}
