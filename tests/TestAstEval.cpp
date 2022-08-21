//
// Created by max on 16/08/22.
//

#include <gtest/gtest.h>
#include "token/Symbols.h"
#include "tree/AST.h"


using namespace repper;


TEST(AstParsing, basic) {
    auto myAst = AST(
            NumericToken("10")
    );

    visit(
            [](auto toPrint) { std::cout << toPrint << std::endl; },
            AST::evaluate<2>(std::make_shared<AST>(myAst))
    );


    auto floatAST = AST(
            NumericToken("10.")
    );

    visit(
            [](auto toPrint) { std::cout << toPrint << std::endl; },
            AST::evaluate<4>(std::make_shared<AST>(floatAST))
    );

}
