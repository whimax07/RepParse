//
// Created by max on 09/07/22.
//

#ifndef REPPARSE_REPPARSE_H
#define REPPARSE_REPPARSE_H


#include <string>
#include <utility>
#include "Tokenizer.h"
#include "tree/AST.h"


/**
 * An implementation from <a href="https://www.engr.mun.ca/~theo/Misc/exp_parsing.htm">Parsing Expressions by Recursive
 * Descent Theodore Norvell (C) 1999 with updates later on.</a>
 */
class RepParse {

    std::vector<OldToken> tokens_;

    std::string input_;

    std::stack<OldToken> operators_;

    std::stack<AST> operands_;


public:
    RepParse() : tokens_(), input_(), operators_(), operands_() {  }


public:
    AST parse(std::string stringToParse) {
        input_ = stringToParse;
        tokens_ = Tokenizer::tokenize(std::move(stringToParse));

        return operands_.top();
    }


private:

};


#endif //REPPARSE_REPPARSE_H
