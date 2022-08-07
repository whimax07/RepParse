//
// Created by max on 11/07/22.
//

#include <regex>
#include "Tokenizer.h"
#include "token/Symbols.h"
#include "token/NumericToken.h"


namespace repper {

    void
    Tokenizer::start() {
        while (fast_ < input_.length()) {
            if (std::isspace(input_[fast_])) {
                fast_++;
                continue;
            }

            if (checkIfOperator()) {
                fast_++;
                continue;
            }

            if (checkIfBracket()) {
                fast_++;
                continue;
            }

            if (checkIfNumber()) {
                fast_++;
                continue;
            }

            throw std::exception();
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
    Tokenizer::checkIfOperator() {
        switch (input_[fast_]) {
            case '*':
                tokens_.push_back(make_shared<Token>(symbols::MULTIPLY));
                break;
            case '/':
                tokens_.push_back(make_shared<Token>(symbols::DIVIDE));
                break;
            case '+':
                tokens_.push_back(make_shared<Token>(symbols::ADD));
                break;
            case '-': {
                if (isSubtract()) {
                    tokens_.push_back(make_shared<Token>(symbols::SUBTRACT));
                } else {
                    tokens_.push_back(make_shared<Token>(symbols::NEGATE));
                }
                break;
            }

            default:
                return false;
        }

        return true;
    }


    bool
    Tokenizer::checkIfBracket() {
        bool out = true;

        switch (input_[fast_]) {
            case '(':
                tokens_.push_back(make_shared<Token>(symbols::OPEN_BRACKET));
                break;
            case ')':
                tokens_.push_back(make_shared<Token>(symbols::CLOSE_BRACKET));
                break;
            default:
                out = false;
        }

        return out;
    }


    bool
    Tokenizer::checkIfNumber() {
        std::regex numbers("[0-9]");
        if (!std::regex_search(input_.substr(fast_, fast_ + 1), numbers)) {
            return false;
        }

        slow_ = fast_;

        if (fast_ + 1 < input_.length()) {
            switch (input_[fast_ + 1]) {
                case 'x':
                case 'X':
                    fast_ += 2;
                    if (fast_ > input_.length()) {
                        throw std::exception();
                    }
                    parseHex();
                    break;
                case 'b':
                case 'B':
                    fast_ += 2;
                    if (fast_ > input_.length()) {
                        throw std::exception();
                    }
                    parseBin();
                    break;
                default:
                    parseDec();
            }
        } else {
            parseDec();
        }

        return true;
    }


    void
    Tokenizer::parseHex() {
        std::regex hexDigits("[0-9aAbBcCdDeEfF_,]+");
        addNumberToken(hexDigits);
    }


    void
    Tokenizer::parseBin() {
        std::regex hexDigits("[0-1_,]+");
        addNumberToken(hexDigits);
    }


    void
    Tokenizer::parseDec() {
        std::regex hexDigits("[0-9_,]+[.]?[0-9_,]*");
        addNumberToken(hexDigits);
    }


    void
    Tokenizer::addNumberToken(
            Regex pattern
    ) {
        std::smatch results;
        std::string str = input_.substr(fast_);
        bool found = std::regex_search(str, results, pattern);

        if (!found) {
            throw std::exception();
        }

        fast_ += results[0].str().length();
        tokens_.push_back(make_shared<Token>(
                NumericToken(input_.substr(slow_, fast_))
        ));
        fast_--;
    }


    TokenSPtr
    Tokenizer::getLastToken() {
        assert(!tokens_.empty());
        return tokens_[tokens_.size() - 1];
    }

}
