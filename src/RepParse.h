//
// Created by max on 09/07/22.
//

#ifndef REPPARSE_REPPARSE_H
#define REPPARSE_REPPARSE_H


#include <string>
#include <utility>
#include "Tokenizer.h"
#include "tree/AST.h"
#include "token/Sentinel.h"
#include "token/Symbols.h"


/**
 * An implementation from <a href="https://www.engr.mun.ca/~theo/Misc/exp_parsing.htm">Parsing Expressions by Recursive
 * Descent Theodore Norvell (C) 1999 with updates later on.</a>
 */
class RepParse {

private:
    std::vector<Token> tokens_;

    std::string toParse_;

    std::stack<Token> operators_;

    std::stack<AST> operands_;

    size_t currentPosition_ = 0;


public:
    RepParse() :
            tokens_(), toParse_(), operators_(), operands_()
    {  }

    explicit RepParse(std::string toParse) :
            tokens_(), toParse_(std::move(toParse)), operators_(), operands_()
    {  }


public:
    static AST parse(const std::string &stringToParse);


private:
    AST parse();

    void expect(Token token);

    const Token & next();

    void consume();

    AST makeLeaf(Token value);

    AST makeNode(Unary unaryOperator, AST value);

    AST makeNode(Binary binaryOperator, AST value1, AST value2);

};


#endif //REPPARSE_REPPARSE_H
