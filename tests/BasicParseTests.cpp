//
// Created by max on 07/08/22.
//
#include <gtest/gtest.h>
#include "utils/Utils.h"



// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}

TEST(RepParseBasic, EmptyParse) {
    auto text = repper::Utils::sstr("");
    auto text_2 = repper::Utils::sstr("Mismatched texted.");
    EXPECT_FALSE(text == text_2);
    std::cout << "Basic tests passed." << std::endl;
}
