//
// Created by max on 07/08/22.
//
#include <gtest/gtest.h>
#include "utils/Utils.h"
#include "Tokenizer.h"
#include "token/Symbols.h"


using namespace repper;


// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
    // Expect two strings not to be equal.
    EXPECT_STRNE("hello", "world");
    // Expect equality.
    EXPECT_EQ(7 * 6, 42);
}


TEST(RepParseBasic, EmptyParse) {
    auto emptyTokens = Tokenizer::tokenize("");
    EXPECT_TRUE(emptyTokens.empty());
}


TEST(RepParseBasic, SimpleParse) {
    auto singleAdd = Tokenizer::tokenize("+");
    EXPECT_TRUE(*singleAdd[0] == symbols::ADD);
    EXPECT_FALSE(*singleAdd[0] == symbols::SUBTRACT);
}
