//
// Created by max on 09/07/22.
//

#include "RepParse.h"

#include <utility>
#include "utils/Utils.h"

AST
RepParse::parse() {
    if (toParse_.empty()) {
        return AST(Token());
    }

    tokens_ = Tokenizer::tokenize(toParse_);

    operators_.push(symbols::SENTINEL);

    return operands_.top();
}


AST
RepParse::parse(
        const std::string &stringToParse
) {
    auto parser = RepParse(stringToParse);
    return parser.parse();
}


void
RepParse::expect(
        Token token
) {
    if (next() == token) {
        consume();
    } else {
        auto nextToken = next();
        throw std::logic_error(Utils::sstr(
                "Expected token: ", &token, ". Received: ", &nextToken
        ));
    }
}


const Token &
RepParse::next() {
    if (currentPosition_ < tokens_.size()) {
        return tokens_[currentPosition_];
    } else {
        return symbols::END;
    }
}


void
RepParse::consume() {
    currentPosition_ ++;
}


AST
RepParse::makeLeaf(
        Token value
) {
    return AST(std::move(value));
}


AST
RepParse::makeNode(
        Unary unaryOperator,
        AST value
) {
    return AST(unaryOperator, std::move(value));
}


AST
RepParse::makeNode(
        Binary binaryOperator,
        AST value1,
        AST value2
) {

}
