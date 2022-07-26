//
// Created by max on 25/07/22.
//

#ifndef REPPARSE_AST_H
#define REPPARSE_AST_H


#include <utility>
#include "../token/Token.h"



class AST {

private:
    Token value_;

    Token left_;

    Token right_;


public:
    explicit AST(Token value)
            : value_(value), left_(), right_() {  }

    AST(Token value, Token left)
            : value_(value), left_(left), right_() {  }

    AST(Token value, Token left, Token right)
            : value_(value), left_(left), right_(right) {  }


public:
    Token getValue() {
        return value_;
    }

    void setValue(Token value) {
        AST::value_ = value;
    }

    Token getLeft() {
        return left_;
    }

    void setLeft(Token left) {
        AST::left_ = left;
    }

    Token getRight() {
        return right_;
    }

    void setRight(Token right) {
        AST::right_ = right;
    }

};


#endif //REPPARSE_AST_H
