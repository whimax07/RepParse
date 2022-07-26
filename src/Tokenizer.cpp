//
// Created by max on 11/07/22.
//

#include <regex>
#include "Tokenizer.h"


void
Tokenizer::start() {
    while (fast_ < input_.length()) {
        if (std::isspace(input_[fast_])) {
            fast_ ++;
            continue;
        }

        if (checkIfOperator()) {
            fast_ ++;
            continue;
        }

        if (checkIfBracket()) {
            fast_ ++;
            continue;
        }

        if (checkIfNumber()) {
            fast_ ++;
            continue;
        }

        throw std::exception();
    }
}


bool
Tokenizer::checkIfOperator() {
    switch (input_[fast_]) {
        case '*':
            tokens_.emplace_back("*", E_TokenType::MULTIPLY, 5, true);
            break;
        case '/':
            tokens_.emplace_back("/", E_TokenType::DIVIDE, 5, true);
            break;
        case '+':
            tokens_.emplace_back("+", E_TokenType::ADD, 3, true);
            break;
        case '-': {
            bool isSubtract = !tokens_.empty()
                    && (getLastToken().isNumber()
                        || getLastToken().getType()
                           == E_TokenType::CLOSE_BRACKET);
            if (isSubtract) {
                tokens_.emplace_back("-", E_TokenType::SUBTRACT, 3, true);
            } else {
                tokens_.emplace_back("-", E_TokenType::NEGATE, 4, false);
            }
            break;
        }

        default: return false;
    }

    return true;
}


bool
Tokenizer::checkIfBracket() {
    bool out = true;

    switch (input_[fast_]) {
        case '(':
            tokens_.emplace_back("(", E_TokenType::OPEN_BRACKET);
            break;
        case ')':
            tokens_.emplace_back(")", E_TokenType::CLOSE_BRACKET);
            break;
        default:
            out = false;
    }

    return out;
}


bool
Tokenizer::checkIfNumber() {
    std::regex numbers ("[0-9]");
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
    std::regex hexDigits ("[0-9aAbBcCdDeEfF_,]+");
    addNumberToken(hexDigits);
}


void
Tokenizer::parseBin() {
    std::regex hexDigits ("[0-1_,]+");
    addNumberToken(hexDigits);
}


void Tokenizer::parseDec() {
    std::regex hexDigits ("[0-9_,]+[.]?[0-9_,]*");
    addNumberToken(hexDigits);
}


void
Tokenizer::addNumberToken(
        const std::regex& pattern
) {
    std::smatch results;
    std::string str = input_.substr(fast_);
    bool found = std::regex_search(str, results, pattern);

    if (!found) {
        throw std::exception();
    }

    fast_ += results[0].length();
    tokens_.emplace_back(input_.substr(slow_, fast_), E_TokenType::NUMBER);
    fast_ --;
}


OldToken
Tokenizer::getLastToken() {
    assert(!tokens_.empty());
    return tokens_[tokens_.size() - 1];
}
