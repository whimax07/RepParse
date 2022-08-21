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

            bool isCharOperator = validOps.find(c) != std::string::npos;
            switch (type_)
            {
                case TokenType::Operator:
                    if (!isCharOperator)
                        return false;

                    // If multi-char operators are ever required
                    if (!regex_match(str_ + c, validMultiCharOps))
                        return false;
                    break;

                case TokenType::Numeric:
                    if (isCharOperator)
                        return false;
                    break;

                default:
                    if (isCharOperator)
                        type_ = TokenType::Operator;
                    else
                        type_ = TokenType::Numeric;
            }
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