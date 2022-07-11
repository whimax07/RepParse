//
// Created by max on 11/07/22.
//

#include "Tokenizer.h"
#include "token/operators/E_Binary.h"

#define instanceof

void
Tokenizer::begin() {
    while (fast_ < input_.length()) {
        if (std::isspace(input_[fast_])) {
            fast_ ++;
            continue;
        }


    }
}


bool
Tokenizer::isOperator() {
    switch (input_[fast_]) {
        case '*':
            tokens_.push_back(E_Binary::MULTIPLY);
            break;
        case '/':
            tokens_.push_back(E_Binary::DIVIDE);
            break;
        case '+':
            tokens_.push_back(E_Binary::ADD);
            break;
        case '-': {
            bool isSubtract = !tokens_.empty()
                    && (getLastToken() )
        }

    }
}


I_Token
Tokenizer::getLastToken() {
    assert(!tokens_.empty());
    return tokens_[tokens_.size() - 1];
}
