//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_NUMERICTOKEN_H
#define REPPARSE_NUMERICTOKEN_H


#include <utility>

#include "Token.h"


namespace repper {


class NumericToken : public Token {

private:
    std::string stringNumber_;


public:
    NumericToken() : stringNumber_() {}

    explicit NumericToken(std::string stringNumber) :
            stringNumber_(std::move(stringNumber)) {}

    NumericToken(const NumericToken &toCopy) = default;

    NumericToken(NumericToken &&toMove) = default;

    ~NumericToken() = default;

    NumericToken & operator=(NumericToken &&toMove) noexcept {
        auto temp = NumericToken(toMove);
        std::swap(*this, temp);
        return *this;
    };


private:
    void emptyFunToken() override {}


public:
    [[nodiscard]]
    const std::string &getStringNumber() const {
        return stringNumber_;
    }

    void setStringNumber(const std::string &stringNumber) {
        stringNumber_ = stringNumber;
    }

    std::ostream const &operator<<(std::ostream &os) override {
        return os << "NumericToken{ String: " << stringNumber_
                  << " }";
    }

    TypedNumbers parse() {
        return stoi(stringNumber_);
    }

};

}


#endif //REPPARSE_NUMERICTOKEN_H
