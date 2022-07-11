//
// Created by max on 11/07/22.
//

#ifndef REPPARSE_UNARY_H
#define REPPARSE_UNARY_H


#include "../I_Token.h"
#include "I_Operator.h"

class Unary : public I_Token, public I_Operator {

public:
    const int precedence_;


public:
    consteval explicit Unary(int precedence) : precedence_{precedence} {}

};



#endif //REPPARSE_UNARY_H
