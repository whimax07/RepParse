//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_UNARY_H
#define REPPARSE_UNARY_H


#include "Operator.h"


enum class E_Unary {
    NEGATE
};


class Unary : public Operator {
private:
    const E_Unary id_;

    const int precedence_;


public:
    explicit Unary(E_Unary id, int precedence) noexcept :
            id_(id), precedence_(precedence) {}


private:
    void emptyFunOperator() override {}


public:
    [[nodiscard]]
    int getPrecedence() const {
        return precedence_;
    }

    bool operator==(const Unary &rhs) const {
        return id_ == rhs.id_;
    }

    bool operator!=(const Unary &rhs) const {
        return !(rhs == *this);
    }

};


[[maybe_unused]]
static const Unary NEGATE = Unary(E_Unary::NEGATE, 4);


#endif //REPPARSE_UNARY_H
