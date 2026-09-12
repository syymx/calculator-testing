#include <gtest/gtest.h>

#include "../src/calculator.hpp"

// ==================== 1. 缺失操作数 ====================

// 缺失右操作数
TEST(ErrorExpressionTest, MissingRightOperand) {
    EXPECT_ANY_THROW(
        calculator::eval("1 +")
    );
}

// 缺失左操作数
TEST(ErrorExpressionTest, MissingLeftOperand) {
    EXPECT_ANY_THROW(
        calculator::eval("* 2")
    );
}

// 运算符后缺少合法操作数
TEST(ErrorExpressionTest, MissingOperandAfterOperator) {
    EXPECT_ANY_THROW(
        calculator::eval("1 + * 2")
    );
}


// ==================== 2. 括号错误 ====================

// 缺少右括号
TEST(ErrorExpressionTest, MissingRightParenthesis) {
    EXPECT_ANY_THROW(
        calculator::eval("(1 + 2")
    );
}

// 多余右括号
TEST(ErrorExpressionTest, ExtraRightParenthesis) {
    EXPECT_ANY_THROW(
        calculator::eval("1 + 2)")
    );
}

// 空括号
TEST(ErrorExpressionTest, EmptyParentheses) {
    EXPECT_ANY_THROW(
        calculator::eval("()")
    );
}


// ==================== 3. 非法连续运算符 ====================

// * 后面紧跟 /，/ 不能作为一元运算符
TEST(ErrorExpressionTest, ConsecutiveMultiplyDivide) {
    EXPECT_ANY_THROW(
        calculator::eval("1 * / 2")
    );
}

// ** 被识别为幂运算后，又多出一个 *
TEST(ErrorExpressionTest, TripleAsterisk) {
    EXPECT_ANY_THROW(
        calculator::eval("1 *** 2")
    );
}


// ==================== 4. 错误表达式结构 ====================

// 两个操作数之间缺少运算符
TEST(ErrorExpressionTest, MissingOperatorBetweenOperands) {
    EXPECT_ANY_THROW(
        calculator::eval("1 2")
    );
}

// 两个括号表达式之间缺少运算符
TEST(ErrorExpressionTest, MissingOperatorBetweenParentheses) {
    EXPECT_ANY_THROW(
        calculator::eval("(1)(2)")
    );
}