//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_NUMBERTOKEN_H
#define REPPARSE_NUMBERTOKEN_H


#include <utility>

#include "OldToken.h"
#include "Token.h"


class NumberToken : public Token {
private:
    Number number_;

    std::string stringNumber_;


public:
    explicit NumberToken(std::string stringNumber) :
            stringNumber_(std::move(stringNumber)) {}


public:
    [[nodiscard]]
    const Number &getNumber() const {
        return number_;
    }

    void setNumber(const Number &number) {
        number_ = number;
    }

    [[nodiscard]]
    const std::string &getStringNumber() const {
        return stringNumber_;
    }

    void setStringNumber(const std::string &stringNumber) {
        stringNumber_ = stringNumber;
    }

};


#endif //REPPARSE_NUMBERTOKEN_H
