//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_BINARY_H
#define REPPARSE_BINARY_H


#include "Operator.h"
#include "Token.h"

enum class E_Binary {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};


class Binary : public Token, Operator {
private:
    const E_Binary id_;

    const int precedence_;

    const bool isLeftAssociative_;


public:
    Binary(E_Binary id, int precedence, bool isLeftAssociative) noexcept
            : id_(id), precedence_(precedence),
            isLeftAssociative_(isLeftAssociative) {}


private:
    void emptyFunOperator() override {}


public:
    [[nodiscard]]
    int getPrecedence() const {
        return precedence_;
    }

    [[nodiscard]]
    bool isLeftAssociative() const {
        return isLeftAssociative_;
    }

    bool operator==(const Binary &rhs) const {
        return id_ == rhs.id_;
    }

    bool operator!=(const Binary &rhs) const {
        return !(rhs == *this);
    }

};


static const Binary ADD = Binary(E_Binary::ADD, 3, true);
static const Binary SUBTRACT = Binary(E_Binary::SUBTRACT, 3, true);
static const Binary MULTIPLY = Binary(E_Binary::MULTIPLY, 5, true);
static const Binary DIVIDE = Binary(E_Binary::DIVIDE, 5, true);


#endif //REPPARSE_BINARY_H
