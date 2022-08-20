//
// Created by max on 11/07/22.
//

#include <regex>
#include "Tokenizer.h"
#include "token/NumericToken.h"
#include "token/RawToken.h"
#include "token/Symbols.h"


namespace repper {

    typedef RawToken::TokenType RT;

    void
    Tokenizer::start() {
        while (appendNextToken());
    }

    bool
    Tokenizer::appendNextToken()
    {
        auto rawToken = RawToken();
        while (fast_ < input_.size() && rawToken.isAppendValid(input_[fast_]))
            fast_++;

        std::string tokenStr = rawToken.getString();
        switch (rawToken.getType())
        {
            case RT::Numeric:
                assert(checkIfNumber(tokenStr));
                return true;
            case RT::Operator:
                assert(checkIfOperator(tokenStr) || checkIfBracket(tokenStr));
                return true;
            default:
                // Should only occur at end of string
                assert(tokenStr.empty());
                return false;
        }
    }

    bool
    Tokenizer::isSubtract() {
        if (tokens_.empty()) {
            return false;
        }

        auto lastToken = getLastToken();

        auto number
                = dynamic_pointer_cast<NumericToken>(lastToken);
        bool isNumber = number != nullptr;

        bool isCloseBracket = false;
        if (auto bracket
                = dynamic_pointer_cast<Brackets>(lastToken)) {
            isCloseBracket = *bracket == symbols::CLOSE_BRACKET;
        }

        return isNumber || isCloseBracket;
    }


    bool
    Tokenizer::checkIfOperator(const std::string& s) {
        switch (s[0]) {
            case '*':
                tokens_.push_back(make_shared<Binary>(symbols::MULTIPLY));
                break;
            case '/':
                tokens_.push_back(make_shared<Binary>(symbols::DIVIDE));
                break;
            case '+':
                tokens_.push_back(make_shared<Binary>(symbols::ADD));
                break;
            case '-': {
                if (isSubtract()) {
                    tokens_.push_back(make_shared<Binary>(symbols::SUBTRACT));
                } else {
                    tokens_.push_back(make_shared<Unary>(symbols::NEGATE));
                }
                break;
            }
            default:
                return false;
        }
        return true;
    }


    bool
    Tokenizer::checkIfBracket(const std::string& s) {
        bool out = true;

        switch (s[0]) {
            case '(':
                tokens_.push_back(make_shared<Brackets>(symbols::OPEN_BRACKET));
                break;
            case ')':
                tokens_.push_back(make_shared<Brackets>(symbols::CLOSE_BRACKET));
                break;
            default:
                out = false;
        }
        return out;
    }


    bool
    Tokenizer::checkIfNumber(const std::string& s) {
        std::regex numbers("[0-9]");
        if (!std::regex_search(s, numbers)) {
            return false;
        }


        if (2 < s.length()) {
            switch (s[1]) {
                case 'x':
                case 'X':
                    if (2 > s.length()) {
                        throw std::exception();
                    }
                    return parseHex(s.substr(2));
                case 'b':
                case 'B':
                    if (2 > s.length()) {
                        throw std::exception();
                    }
                    return parseBin(s.substr(2));
                default:
                    return parseDec(s);
            }
        } else {
            return parseDec(s);
        }
    }


    bool
    Tokenizer::parseHex(const std::string& s) {
        std::regex hexDigits("[0-9aAbBcCdDeEfF_,]+");
        return addNumberToken(s, hexDigits);
    }


    bool
    Tokenizer::parseBin(const std::string& s) {
        std::regex hexDigits("[0-1_,]+");
        return addNumberToken(s, hexDigits);
    }


    bool
    Tokenizer::parseDec(const std::string& s) {
        std::regex hexDigits("[ ]*[0-9_,]+[.]?[0-9_,]*");
        return addNumberToken(s, hexDigits);
    }


    bool
    Tokenizer::addNumberToken(const std::string& s, Regex pattern) {
        std::smatch results;
        bool found = std::regex_match(s, results, pattern);

        if (!found) {
            throw std::exception();
        }

        tokens_.push_back(make_shared<NumericToken>(
                NumericToken(s)
        ));
        // Additional checks required?
        return true;
    }


    TokenSPtr
    Tokenizer::getLastToken() {
        assert(!tokens_.empty());
        return tokens_[tokens_.size() - 1];
    }

}
