//
// Created by AHowell on 20/08/2022.
//

#ifndef REPPARSERUNNABLE_RAWTOKEN_H
#define REPPARSERUNNABLE_RAWTOKEN_H


#include "Symbols.h"
#include "E_RawTokenType.h"


namespace repper {


/*
 * Handles the separation of tokens. It is assumed that all tokens
 * consist of either a single operator or numeric.
 */
class RawToken {
public:
    static constexpr std::string_view validOps_ = "+-*/()";

    static inline const std::regex multiCharOps_{""};


private:
    std::string str_;

    E_RawTokenType type_ = E_RawTokenType::NONE;


public:
    explicit RawToken() : str_(), type_() {}

    ~RawToken() = default;


public:
    /** Returns false when token done. */
    bool isAppendValid(char c) {
        // Allow any number of space pre-fixes
        if (c == ' ')
            return str_.empty();

        bool isCharOperator = validOps_.find(c) != std::string::npos;
        switch (type_) {
            case E_RawTokenType::OPERATOR:
                if (!isCharOperator) {
                    return false;
                }

                // If multi-char operators are ever required.
                if (!regex_match(str_ + c, multiCharOps_)) {
                    return false;
                }
                break;

            case E_RawTokenType::NUMERIC:
                if (isCharOperator) {
                    return false;
                }
                break;

            default:
                if (isCharOperator) {
                    type_ = E_RawTokenType::OPERATOR;
                } else {
                    type_ = E_RawTokenType::NUMERIC;
                }
        }
        str_ += c;
        return true;
    }


public:
    std::string getString() { return str_; }

    E_RawTokenType getType() { return type_; }

};


}

#endif //REPPARSERUNNABLE_RAWTOKEN_H
