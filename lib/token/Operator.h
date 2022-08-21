//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_OPERATOR_H
#define REPPARSE_OPERATOR_H


#include <ostream>
#include "Token.h"

namespace repper {

    class Operator : public Token {

    public:
        void emptyFunToken() override {}

        virtual void emptyFunOperator() {}


    public:
        friend std::ostream &operator<<(
                std::ostream &os, const Operator &anOperator
        ) {
            return os << "OPERATOR{ }";
        }

    };


    using OperatorSPtr = std::shared_ptr<Operator>;

}


#endif //REPPARSE_OPERATOR_H
