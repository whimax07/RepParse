//
// Created by max on 12/07/22.
//

#include "OldToken.h"

#include <utility>




OldToken::OldToken() {
    string_ = "";
    precedence_ = 0;
    isLeftAssociative_ = false;
    type_ = E_TokenType::END;
}


OldToken::OldToken(std::string string, E_TokenType type)
        : string_(std::move(string)), type_(type), precedence_(0),
        isLeftAssociative_(true) {}


OldToken::OldToken(std::string string, E_TokenType type, int precedence,
                   bool isLeftAssociative)
        : string_(std::move(string)), type_(type), precedence_(precedence),
          isLeftAssociative_(isLeftAssociative) {}


bool OldToken::isNumber() {
    return type_ == E_TokenType::NUMBER;
}


bool
OldToken::isOperator() {
    return type_ == E_TokenType::ADD || type_ == E_TokenType::SUBTRACT || type_ == E_TokenType::MULTIPLY
           || type_ == E_TokenType::DIVIDE || type_ == E_TokenType::NEGATE || type_ == E_TokenType::SENTENTIAL;
}


bool
OldToken::isUnary() {
    return type_ == E_TokenType::NEGATE;
}


bool
OldToken::isBinary() {
    return type_ == E_TokenType::ADD || type_ == E_TokenType::SUBTRACT || type_ == E_TokenType::MULTIPLY
           || type_ == E_TokenType::DIVIDE;
}


bool
OldToken::isSentential() {
    return type_ == E_TokenType::SENTENTIAL;
}


bool
OldToken::isEnd() {
    return type_ == E_TokenType::END;
}


bool
OldToken::operatorGreater(OldToken x, OldToken y) {
    if (!x.isOperator() || !y.isOperator()) {
        throw std::exception();
    }

    if (x.isBinary() && y.isBinary()) {
        return x.precedence_ > y.precedence_
               || x.isLeftAssociative_ && x.precedence_ == y.precedence_;
    }

    if (x.isUnary() && y.isBinary()) {
        return x.precedence_ >= y.precedence_;
    }

    if (y.isUnary()) {
        return false;
    }

    if (x.isSentential()) {
        return false;
    }

    if (y.isSentential()) {
        return true;
    }

    throw std::exception();
}


E_TokenType
OldToken::getType() const {
    return type_;
}

const std::string
&OldToken::getString() const {
    return string_;
}
