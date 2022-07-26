//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_OPERATOR_H
#define REPPARSE_OPERATOR_H


#include <stdexcept>
#include "Binary.h"
#include "Unary.h"
#include "Sentinel.h"



class Operator {
public:
    virtual void emptyFunOperator() = 0;


public:
    static bool comparePrecedence(Operator *operator1, Operator *operator2) {
        auto b1 = dynamic_cast<Binary *>(operator1);
        auto b2 = dynamic_cast<Binary *>(operator2);
        if (b1 != nullptr && b2 != nullptr) {
            return (b1->getPrecedence() > b2->getPrecedence())
                   || (b1->isLeftAssociative()
                       && b1->getPrecedence() == b2->getPrecedence());
        }

        auto u1 = dynamic_cast<Unary *>(operator1);
        if (u1 != nullptr && b2 != nullptr) {
            return u1->getPrecedence() >= b2->getPrecedence();
        }

        auto u2 = dynamic_cast<Unary *>(operator2);
        if (u2 != nullptr) {
            return false;
        }

        auto s1 = dynamic_cast<Sentinel *>(operator1);
        if (s1 != nullptr) {
            return false;
        }

        auto s2 = dynamic_cast<Sentinel *>(operator2);
        if (s2 != nullptr) {
            return true;
        }


        throw std::logic_error("Unexpected operator types.");
    }

};


#endif //REPPARSE_OPERATOR_H
