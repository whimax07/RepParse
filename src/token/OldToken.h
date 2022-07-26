//
// Created by max on 11/07/22.
//

#ifndef REPPARSE_OLDTOKEN_H
#define REPPARSE_OLDTOKEN_H


#include <iostream>
#include <string>
#include <vector>
#include "E_TokenType.h"



union Number {
    int16_t i16;
    uint16_t u16;
    int32_t i32;
    uint32_t u32;
    int64_t i64;
    uint64_t u64;
    float f32;
    double f64;

    // This is pretty neat.
    Number() : u64() {}
};



class OldToken {

private:
    std::string string_;

    Number number_;

    int precedence_;

    bool isLeftAssociative_;

    E_TokenType type_;


public:
    OldToken();

    OldToken(std::string string, E_TokenType type);

    OldToken(std::string string, E_TokenType type, int precedence,
             bool isLeftAssociative);

    bool isNumber();

    bool isOperator();

    bool isUnary();

    bool isBinary();

    bool isSentential();

    bool isEnd();

    static bool operatorGreater(OldToken x, OldToken y);


public:
    [[nodiscard]] E_TokenType getType() const;

    [[nodiscard]] const std::string &getString() const;

};



inline std::ostream &operator<<(std::ostream &os, OldToken const &token) {
    os << "OldToken{ type=" << token.getType() << ", String=" << token.getString()
       << " }";
    return os;
}


inline std::ostream &operator<<(std::ostream &os, std::vector<OldToken> const &tokens) {
    os << "[";
    for (int i = 0; i < tokens.size() - 1; i++) {
        os << tokens[i] << ", ";
    }
    os << tokens[tokens.size() - 1] << "]";

    return os;
}



#endif //REPPARSE_OLDTOKEN_H
