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

    using namespace repper;


    static constexpr End END = End(E_End::END);

    static constexpr Sentinel SENTINEL = Sentinel(E_Sentinel::SENTINEL);

    static constexpr Brackets OPEN_BRACKET = Brackets(E_Brackets::OPEN);
    static constexpr Brackets CLOSE_BRACKET = Brackets(E_Brackets::CLOSE);

    static constexpr Unary NEGATE = Unary(E_Unary::NEGATE, 4);

    static constexpr Binary ADD = Binary(E_Binary::ADD, 3, true);
    static constexpr Binary SUBTRACT = Binary(E_Binary::SUBTRACT, 3, true);
    static constexpr Binary MULTIPLY = Binary(E_Binary::MULTIPLY, 5, true);
    static constexpr Binary DIVIDE = Binary(E_Binary::DIVIDE, 5, true);

}


#endif //REPPARSE_SYMBOLS_H
