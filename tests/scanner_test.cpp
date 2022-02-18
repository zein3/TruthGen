#include <gtest/gtest.h>
#include "scanner.hpp"


TEST(ScannerTest, HandleNoInput) {
    Scanner sc;
    EXPECT_EQ(sc.hasMoreTokens(), false);
}

TEST(ScannerTest, BasicTest) {
    std::string input = "T&T";
    Scanner sc;
    sc.loadExpression(input);

    EXPECT_EQ(sc.tokenType(), TokenType::IMM);
    EXPECT_EQ(sc.getValue(), true);

    sc.advance();

    EXPECT_EQ(sc.tokenType(), TokenType::BINARYOP);
    EXPECT_EQ(sc.getOperator(), Operator::AND);

    sc.advance();
    EXPECT_EQ(sc.hasMoreTokens(), false);
}

TEST(ScannerTest, ComplexTest) {
    std::string input = "T&F&~(T|F)";
    Scanner sc;
    sc.loadExpression(input);

    EXPECT_EQ(sc.tokenType(), TokenType::IMM);
    EXPECT_EQ(sc.getValue(), true);

    sc.advance();

    EXPECT_EQ(sc.tokenType(), TokenType::BINARYOP);
    sc.advance();
    sc.advance();
    sc.advance();
    sc.advance();
    EXPECT_EQ(sc.tokenType(), TokenType::SYMBOL);
}
