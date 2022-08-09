//
// Created by max on 07/08/22.
//
#include <gtest/gtest.h>
#include "utils/Utils.h"
#include "Tokenizer.h"
#include "token/Symbols.h"
#include "token/NumericToken.h"


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


TEST(RepParseBasic, SimpleParse1) {
    auto singleAdd = Tokenizer::tokenize("+");
    EXPECT_TRUE(*singleAdd[0] == symbols::ADD);
    EXPECT_FALSE(*singleAdd[0] == symbols::SUBTRACT);
}


TEST(RepParseBasic, SimpleParse2) {
    auto singleAdd = Tokenizer::tokenize("10 + 20");
    EXPECT_TRUE(*singleAdd[0] == NumericToken("10"));
    EXPECT_TRUE(*singleAdd[1] == symbols::ADD);
    EXPECT_TRUE(*singleAdd[2] == NumericToken("20"));

    auto singleAddNoSpaces = Tokenizer::tokenize("10+20");
    EXPECT_TRUE(*singleAddNoSpaces[0] == NumericToken("10"));
    EXPECT_TRUE(*singleAddNoSpaces[1] == symbols::ADD);
    EXPECT_TRUE(*singleAddNoSpaces[2] == NumericToken("20"));
}