//
// Created by max on 25/07/22.
//

#ifndef REPPARSE_AST_H
#define REPPARSE_AST_H


#include <utility>
#include "../token/Token.h"



class AST  {

private:
    Token value_;

    AST left_;

    AST right_;


public:
    explicit AST(Token value)
            : value_(std::move(value)), left_(), right_() {  }

    AST(Token value, AST left)
            : value_(std::move(value)), left_(left), right_() {  }

    AST(Token value, AST left, AST right)
            : value_(std::move(value)), left_(left), right_(right) {  }


public:
    Token getValue() {
        return value_;
    }

    void setValue(Token value) {
        AST::value_ = std::move(value);
    }

    AST getLeft() {
        return left_;
    }

    void setLeft(AST left) {
        AST::left_ = left;
    }

    AST getRight() {
        return right_;
    }

    void setRight(AST right) {
        AST::right_ = right;
    }

};


#endif //REPPARSE_AST_H
