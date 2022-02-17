#include <gtest/gtest.h>
#include "permuter.hpp"


TEST(PermuterTest, HandleEmptyInput) {
    std::string input = "";
    Permuter p(input);

    EXPECT_EQ(p.canPermute(), false);
}

TEST(PermuterTest, BasicTest) {
    std::string input = "a&b";
    Permuter p(input);

    EXPECT_EQ(p.getExpression(), "T&T");
}

//TEST(PermuterTest, FullTest) {
    //std::string input = "a&b";
    //Permuter p(input);

    //EXPECT_EQ(p.getExpression(), "T&T");
    //p.permute();
    //EXPECT_EQ(p.getExpression(), "T&F");
    //p.permute();
    //EXPECT_EQ(p.getExpression(), "F&T");
    //p.permute();
    //EXPECT_EQ(p.getExpression(), "F&F");
    //EXPECT_EQ(p.canPermute(), false);
//}
