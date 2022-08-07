//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_NUMERICTOKEN_H
#define REPPARSE_NUMERICTOKEN_H


#include <utility>

#include "OldToken.h"
#include "Token.h"



union Number {
    int16_t i16;
    uint16_t u16;
    int32_t i32;
    uint32_t u32;
    int64_t i64;
    uint64_t u64;
    float f32;
    double f64;

    // This is pretty neat. This will zero the union. Who knows what that means.
    Number() = default;
};



class NumericToken : public Token {
private:
    Number number_;

    std::string stringNumber_;


public:
    explicit NumericToken(std::string stringNumber) :
            stringNumber_(std::move(stringNumber)) {}


private:
    void emptyFunToken() override {}


public:
    [[nodiscard]]
    Number getNumber() const {
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

    std::ostream const &operator<<(std::ostream &os) override {
        return os << "NumericToken{ String: " << stringNumber_
                  << ", Number: " << std::to_string(number_.u64)
                  << " }";
    }

};



#endif //REPPARSE_NUMERICTOKEN_H
