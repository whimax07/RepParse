//
// Created by max on 25/07/22.
//

#ifndef REPPARSE_AST_H
#define REPPARSE_AST_H


#include <utility>

#include "../token/OldToken.h"



class AST {

private:
    OldToken value_;

    OldToken left_;

    OldToken right_;


public:
    explicit AST(OldToken value) : value_(std::move(value)), left_(), right_() {  }

    AST(OldToken value, OldToken left) : value_(std::move(value)),
                                         left_(std::move(left)), right_() {  }

    AST(OldToken value, OldToken left, OldToken right) : value_(std::move(value)),
                                                         left_(std::move(left)),
                                                         right_(std::move(right)) {  }


public:
    OldToken getValue() {
        return value_;
    }

    void setValue(OldToken value) {
        AST::value_ = value;
    }

    OldToken getLeft() {
        return left_;
    }

    void setLeft(OldToken left) {
        AST::left_ = left;
    }

    OldToken getRight() {
        return right_;
    }

    void setRight(OldToken right) {
        AST::right_ = right;
    }

};


#endif //REPPARSE_AST_H
