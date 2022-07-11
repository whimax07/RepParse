//
// Created by max on 11/07/22.
//

#ifndef REPPARSE_E_BINARY_H
#define REPPARSE_E_BINARY_H


#include "Binary.h"



class E_Binary {

public:
    static constexpr Binary ADD = Binary(3, true);

    static constexpr Binary SUBTRACT = Binary(3, true);

    static constexpr Binary MULTIPLY = Binary(5, true);

    static constexpr Binary DIVIDE = Binary(5, true);

};


#endif //REPPARSE_E_BINARY_H
