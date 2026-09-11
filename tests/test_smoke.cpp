#include <gtest/gtest.h>
#include "calculator.hpp"

TEST(CalculatorSmokeTest, BasicAddition)
{
    EXPECT_EQ(calculator::eval("1 + 2"), 3);
}