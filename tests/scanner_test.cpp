#include <gtest/gtest.h>
#include "scanner.hpp"


TEST(ScannerTest, Basic) {
    Scanner sc;
    EXPECT_EQ(sc.hasMoreTokens(), false);
    EXPECT_EQ(3 * 4, 12);
}

TEST(ScannerTest, ShouldFail) {
    Scanner sc;
    EXPECT_EQ(sc.hasMoreTokens(), false);
}
