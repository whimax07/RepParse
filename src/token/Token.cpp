//
// Created by max on 12/07/22.
//

#include "Token.h"

#include <utility>



bool Token::isNumber() {
    return type_ == E_TokenType::NUMBER;
}


Token::Token(std::string string, E_TokenType type)
        : string_(std::move(string)), type_(type), precedence_(0),
        isLeftAssociative_(true) {}


Token::Token(std::string string, E_TokenType type, int precedence,
             bool isLeftAssociative)
        : string_(std::move(string)), type_(type), precedence_(precedence),
          isLeftAssociative_(isLeftAssociative) {}


bool
Token::isOperator() {
    return type_ == E_TokenType::ADD || type_ == E_TokenType::SUBTRACT || type_ == E_TokenType::MULTIPLY
           || type_ == E_TokenType::DIVIDE || type_ == E_TokenType::NEGATE || type_ == E_TokenType::SENTENTIAL;
}


bool
Token::isUnary() {
    return type_ == E_TokenType::NEGATE;
}


bool
Token::isBinary() {
    return type_ == E_TokenType::ADD || type_ == E_TokenType::SUBTRACT || type_ == E_TokenType::MULTIPLY
           || type_ == E_TokenType::DIVIDE;
}


bool
Token::isSentential() {
    return type_ == E_TokenType::SENTENTIAL;
}


bool
Token::isEnd() {
    return type_ == E_TokenType::END;
}


bool
Token::operatorGreater(Token x, Token y) {
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
Token::getType() const {
    return type_;
}


const std::string
&Token::getString() const {
    return string_;
}
