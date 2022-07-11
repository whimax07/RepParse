//
// Created by max on 11/07/22.
//

#ifndef REPPARSE_BINARY_H
#define REPPARSE_BINARY_H


#include "../I_Token.h"
#include "I_Operator.h"

class Binary : public I_Token, public I_Operator {

public:
    const int precedence_;

    const bool isLeftAssociative_;


public:
    consteval Binary(int precedence, bool isLeftAssociative)
            : precedence_{precedence}, isLeftAssociative_{isLeftAssociative} {}

};


#endif //REPPARSE_BINARY_H
