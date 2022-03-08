#include <gtest/gtest.h>
#include "vartable.hpp"


TEST(VariableTable, HandleEmptyInput) {
    std::string input = "";
    VariableTable vt(input);

    std::vector<char> &variables = vt.getVariables();
    EXPECT_EQ(variables.size(), 0);
}

TEST(VariableTable, BasicInput) {
    std::string input = "a&b|c";
    VariableTable vt(input);

    std::vector<char> &variables = vt.getVariables();
    EXPECT_EQ(variables.size(), 3);

    EXPECT_EQ(vt.getVariableValue('a'), true);
    EXPECT_EQ(vt.getVariableValue('b'), true);
    EXPECT_EQ(vt.getVariableValue('c'), true);
    EXPECT_EQ(vt.getVariableValue('d'), false);
}

TEST(VariableTable, InputWithImmediateValue) {
    std::string input = "T&a";
    VariableTable vt(input);

    std::vector<char> &variables = vt.getVariables();
    EXPECT_EQ(variables.size(), 1);
    EXPECT_EQ(vt.getVariableValue('a'), true);
}

TEST(VariableTable, ComplexInput) {
    std::string input = "( a & b ) | a & ~c";
    VariableTable vt(input);

    std::vector<char> &variables = vt.getVariables();
    EXPECT_EQ(variables.size(), 3);

    EXPECT_EQ(vt.getVariableValue('a'), true);
    EXPECT_EQ(vt.getVariableValue('b'), true);
    EXPECT_EQ(vt.getVariableValue('c'), true);
    EXPECT_EQ(vt.getVariableValue('d'), false);
}

TEST(VariableTable, CanSetVariable) {
    std::string input = "a";
    VariableTable vt(input);

    EXPECT_EQ(vt.getVariableValue('a'), true);

    vt.setVariableValue('a', false);

    EXPECT_EQ(vt.getVariableValue('a'), false);
}

TEST(VariableTable, IgnoreSmallV) {
    std::string input = "a v b v c";
    VariableTable vt(input);
    EXPECT_EQ(vt.getVariables().size(), 3);
}
