//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_OPERATOR_H
#define REPPARSE_OPERATOR_H


#include <ostream>

class Operator : public Token {

public:
    void emptyFunToken() override {  }

    virtual void emptyFunOperator() {  }

    friend std::ostream &
    operator<<(std::ostream &os, const Operator &anOperator) {
        return os << "Operator{ }";
    }


};


#endif //REPPARSE_OPERATOR_H
