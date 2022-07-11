//
// Created by max on 11/07/22.
//

#ifndef REPPARSE_TOKENIZER_H
#define REPPARSE_TOKENIZER_H


#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include "token/I_Token.h"


class Tokenizer {

private:
    std::string input_;

    std::vector<I_Token> tokens_;

    int fast_ = 0;

    int slow_ = 0;


public:
    static std::vector<I_Token> tokenize(std::string toTokenize) {
        return (new Tokenizer(std::move(toTokenize)))->tokens_;
    }


private:
    explicit Tokenizer(std::string input)
            : input_(std::move(input)), tokens_() {
        begin();
    }

    void begin();

    bool isOperator();

    I_Token getLastToken();

};


#endif //REPPARSE_TOKENIZER_H
