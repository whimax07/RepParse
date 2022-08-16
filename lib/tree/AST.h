//
// Created by max on 25/07/22.
//

#ifndef REPPARSE_AST_H
#define REPPARSE_AST_H


#include <utility>
#include <variant>
#include "../token/Token.h"
#include "../token/Operator.h"
#include "../token/Unary.h"
#include "../token/Binary.h"
#include "../token/NumericToken.h"


namespace repper {

typedef std::variant<NumericToken, Unary, Binary> NodeTypes;
//using NodeTypes = std::variant<NumericToken, Unary, Binary>;


class AST {

public:
    using AstSPtr = std::shared_ptr<AST>;



private:
    NodeTypes value_;

    AstSPtr left_;

    AstSPtr right_;


public:
    AST() : value_(), left_(), right_() {}

    explicit AST(NodeTypes value)
            : value_(std::move(value)), left_(), right_() {}

    AST(NodeTypes value, AstSPtr left)
            : value_(std::move(value)), left_(std::move(left)), right_() {}

    AST(NodeTypes value, AstSPtr left, AstSPtr right)
            : value_(std::move(value)), left_(std::move(left)),
              right_(std::move(right)) {}


public:
    [[nodiscard]]
    NodeTypes getValue() const {
        return value_;
    }

    void setValue(NodeTypes value) {
        auto temp = NodeTypes(std::move(value));
        swap(value_, temp);
    }

    AstSPtr getLeft() const {
        return left_;
    }

    void setLeft(AstSPtr left) {
        left_ = std::move(left);
    }

    AstSPtr getRight() const {
        return right_;
    }

    void setRight(AstSPtr right) {
        right_ = std::move(right);
    }

};

}


#endif //REPPARSE_AST_H
