//
// Created by AHowell on 20/08/2022.
//

#ifndef REPPARSERUNNABLE_RAWTOKEN_H
#define REPPARSERUNNABLE_RAWTOKEN_H


#include "Symbols.h"


namespace repper
{
    /*
     * Handles the separation of tokens. It is assumed that all tokens
     * consist of either a single operator or numeric.
     */
    class RawToken
    {
    public:
        enum TokenType
        {
            Numeric,
            Operator,
            None
        };

        // This is a bit shit
        inline const std::string static validOps {"+-*/()"};
        inline const std::regex static validMultiCharOps {""};

        explicit RawToken() { str_ = ""; }
        ~RawToken() = default;

        /*
         * Returns false when token done
         */
        bool isAppendValid(char c)
        {
            // Allow any number of space pre-fixes
            if (c == ' ')
                return str_.empty();

            if (validOps.find(c) != std::string::npos)
            {
                if (type_ == TokenType::Numeric)
                    return false;

                // If multi-char operators are ever required
                if (type_ == TokenType::Operator && !regex_match(str_ + c, validMultiCharOps))
                    return false;

                type_ = TokenType::Operator;
                str_ += c;
                return true;
            }

            if (type_ == TokenType::Operator)
                return false;

            type_ = TokenType::Numeric;
            str_ += c;
            return true;
        }

        std::string getString() { return str_; }
        TokenType getType() { return type_; }

    private:
        std::string str_;
        TokenType type_ {None};
    };
}


#endif //REPPARSERUNNABLE_RAWTOKEN_H
