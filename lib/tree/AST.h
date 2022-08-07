//
// Created by max on 25/07/22.
//

#ifndef REPPARSE_AST_H
#define REPPARSE_AST_H


#include <utility>
#include "../token/Token.h"



namespace repper {

    class AST {

    public:
        using AstSPtr = std::shared_ptr<AST>;


    private:
        TokenSPtr value_;

        AstSPtr left_;

        AstSPtr right_;


    public:
        AST() : value_(), left_(), right_() {}

        explicit AST(TokenSPtr value)
                : value_(std::move(value)), left_(), right_() {}

        AST(TokenSPtr value, AstSPtr left)
                : value_(std::move(value)), left_(std::move(left)), right_() {}

        AST(TokenSPtr value, AstSPtr left, AstSPtr right)
                : value_(std::move(value)), left_(std::move(left)),
                  right_(std::move(right)) {}


    public:
        TokenSPtr getValue() {
            return value_;
        }

        void setValue(TokenSPtr value) {
            value_ = std::move(value);
        }

        AstSPtr getLeft() {
            return left_;
        }

        void setLeft(AstSPtr left) {
            left_ = std::move(left);
        }

        AstSPtr getRight() {
            return right_;
        }

        void setRight(AstSPtr right) {
            right_ = std::move(right);
        }

    };

}


#endif //REPPARSE_AST_H
