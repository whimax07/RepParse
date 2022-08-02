//
// Created by max on 02/08/22.
//

#ifndef REPPARSE_SYMBOLS_H
#define REPPARSE_SYMBOLS_H


#include "Binary.h"
#include "Unary.h"
#include "Sentinel.h"
#include "Brackets.h"
#include "End.h"


namespace symbols {
    static const End END = End(E_End::END);

    static const Sentinel SENTINEL = Sentinel(E_Sentinel::SENTINEL);

    static const Brackets OPEN_BRACKET = Brackets(E_Brackets::OPEN);
    static const Brackets CLOSE_BRACKET = Brackets(E_Brackets::CLOSE);

    static const Unary NEGATE = Unary(E_Unary::NEGATE, 4);

    static const Binary ADD = Binary(E_Binary::ADD, 3, true);
    static const Binary SUBTRACT = Binary(E_Binary::SUBTRACT, 3, true);
    static const Binary MULTIPLY = Binary(E_Binary::MULTIPLY, 5, true);
    static const Binary DIVIDE = Binary(E_Binary::DIVIDE, 5, true);
}


#endif //REPPARSE_SYMBOLS_H
