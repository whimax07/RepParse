//
// Created by max on 16/08/22.
//

#include <gtest/gtest.h>
#include "token/Symbols.h"
#include "tree/AST.h"
#include "token/EvalAST.h"


using namespace repper;


TEST(AstParsing, basic) {
    auto myAst = AST(
            NumericToken("10")
    );

    visit(
            [](auto toPrint) { std::cout << toPrint << std::endl; },
            evaluate(std::make_shared<AST>(myAst))
    );

}
