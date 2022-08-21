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
    EXPECT_TRUE(singleAdd.size() == 1);
    EXPECT_TRUE(*singleAdd[0] == symbols::ADD);
    EXPECT_FALSE(*singleAdd[0] == symbols::SUBTRACT);
}


TEST(RepParseBasic, SimpleParse2) {
    auto singleAddNoSpaces = Tokenizer::tokenize("10+20");
    EXPECT_TRUE(singleAddNoSpaces.size() == 3);
    EXPECT_TRUE(*singleAddNoSpaces[0] == NumericToken("10"));
    EXPECT_TRUE(*singleAddNoSpaces[1] == symbols::ADD);
    EXPECT_TRUE(*singleAddNoSpaces[2] == NumericToken("20"));
}


TEST(RepParseBasic, ExtraSpacesParse) {
    auto singleAdd = Tokenizer::tokenize("  10 +     20  ");
    EXPECT_TRUE(singleAdd.size() == 3);
    EXPECT_TRUE(*singleAdd[0] == NumericToken("10"));
    EXPECT_TRUE(*singleAdd[1] == symbols::ADD);
    EXPECT_TRUE(*singleAdd[2] == NumericToken("20"));
}


TEST(RepParseBasic, AllOperatorsParse) {
    auto allOps = Tokenizer::tokenize("-10+( (0xFF/2)*4) ");
    EXPECT_TRUE(allOps.size() == 12);
    EXPECT_TRUE(*allOps[0] == symbols::NEGATE);
    EXPECT_TRUE(*allOps[1] == NumericToken("10"));
    EXPECT_TRUE(*allOps[2] == symbols::ADD);
    EXPECT_TRUE(*allOps[3] == symbols::OPEN_BRACKET);
    EXPECT_TRUE(*allOps[4] == symbols::OPEN_BRACKET);
    EXPECT_TRUE(*allOps[5] == NumericToken("0xFF"));
    EXPECT_TRUE(*allOps[6] == symbols::DIVIDE);
    EXPECT_TRUE(*allOps[7] == NumericToken("2"));
    EXPECT_TRUE(*allOps[8] == symbols::CLOSE_BRACKET);
    EXPECT_TRUE(*allOps[9] == symbols::MULTIPLY);
    EXPECT_TRUE(*allOps[10] == NumericToken("4"));
    EXPECT_TRUE(*allOps[11] == symbols::CLOSE_BRACKET);
}



TEST(RepParseBasic, InvalidOperatorParse) {
    ASSERT_DEATH(Tokenizer::tokenize("1 ~ 2"), ""); // metal asf
}