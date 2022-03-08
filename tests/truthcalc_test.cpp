#include <gtest/gtest.h>
#include "truthcalc.hpp"


class TruthCalculatorTest : public ::testing::Test {
protected:
    TruthCalculator calc;
};

TEST_F(TruthCalculatorTest, BasicExpressionTest) {
    EXPECT_EQ(calc.calculateTruth("T&F"), false);
    EXPECT_EQ(calc.calculateTruth("T|F"), true);
}

TEST_F(TruthCalculatorTest, UnaryOpTest) {
    EXPECT_EQ(calc.calculateTruth("~T & T"), false);
}

TEST_F(TruthCalculatorTest, NestedParanTest) {
    EXPECT_EQ(calc.calculateTruth("~(T&T&(T&F))"), true);
}

TEST_F(TruthCalculatorTest, MoreTests) {
    EXPECT_EQ(calc.calculateTruth("~T v F"), false);
    EXPECT_EQ(calc.calculateTruth("TvF"), true);
    EXPECT_EQ(calc.calculateTruth("~T v T"), true);
}
