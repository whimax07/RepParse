//
// Created by max on 29/11/22.
//

#include <gtest/gtest.h>

#include "RepParse.h"


using namespace repper;

bool eq(const TypedNumbers& lhs, auto rhs) {
    return std::visit([rhs](auto in) { return in == rhs; }, lhs);
}



TEST(AstEval, basic) {
    auto ast1 = RepParse::parse("5 * 6");
    auto res1 = AST::evaluate(make_shared<AST>(ast1));
    ASSERT_TRUE(eq(res1, 30));

    auto ast2 = RepParse::parse("106168440 & 0xff");
    auto res2 = AST::evaluate(make_shared<AST>(ast2));
    ASSERT_TRUE(eq(res2, 120));
    ASSERT_FALSE(eq(res2, 20));
}
