//
// Created by max on 11/07/22.
//

#ifndef REPPARSE_TOKEN_H
#define REPPARSE_TOKEN_H


#include <iostream>
#include <string>
#include <vector>
#include "E_TokenType.h"


class Token {

private:
    std::string string_;

    int precedence_;

    bool isLeftAssociative_;

    E_TokenType type_;



public:
    Token(std::string string, E_TokenType type);

    Token(std::string string, E_TokenType type, int precedence,
          bool isLeftAssociative);

    bool isNumber();

    bool isOperator();

    bool isUnary();

    bool isBinary();

    bool isSentential();

    bool isEnd();

    static bool operatorGreater(Token x, Token y);


public:
    [[nodiscard]] E_TokenType getType() const;

    [[nodiscard]] const std::string &getString() const;

};



inline std::ostream &operator<<(std::ostream &os, Token const &token) {
    os << "Token{ type=" << token.getType() << ", String=" << token.getString()
       << " }";
    return os;
}


inline std::ostream &operator<<(std::ostream &os, std::vector<Token> const &tokens) {
    os << "[";
    for (int i = 0; i < tokens.size() - 1; i++) {
        os << tokens[i] << ", ";
    }
    os << tokens[tokens.size() - 1] << "]";

    return os;
}



#endif //REPPARSE_TOKEN_H
