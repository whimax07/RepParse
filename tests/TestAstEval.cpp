//
// Created by max on 16/08/22.
//

#include <gtest/gtest.h>
#include "token/Symbols.h"
#include "tree/AST.h"


using namespace repper;


TEST(AstParsing, basic) {
    auto myAst = AST(
            TypedNumbers {(int32_t) 10}
    );

    visit(
            [](auto toPrint) { std::cout << toPrint << std::endl; },
            AST::evaluate(std::make_shared<AST>(myAst))
    );


    auto floatAST = AST(
            TypedNumbers {(float) 10}
    );

    visit(
            [](auto toPrint) { std::cout << toPrint << std::endl; },
            AST::evaluate(std::make_shared<AST>(floatAST))
    );
}


TEST(AstParsing, basic_expresions) {

}
