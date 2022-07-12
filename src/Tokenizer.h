//
// Created by max on 11/07/22.
//

#ifndef REPPARSE_TOKENIZER_H
#define REPPARSE_TOKENIZER_H


#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <regex>
#include "token/Token.h"


class Tokenizer {

private:
    std::string input_;

    std::vector<Token> tokens_;

    int fast_ = 0;

    int slow_ = 0;


public:
    static std::vector<Token> tokenize(std::string toTokenize) {
        auto *tokenizer = new Tokenizer(std::move(toTokenize));
        return tokenizer->tokens_;
    }


private:
    explicit Tokenizer(std::string input)
            : input_(std::move(input)), tokens_() {
        start();
    }

    void start();

    bool checkIfOperator();

    bool checkIfBracket();

    bool checkIfNumber();

    void parseHex();

    void parseBin();

    void parseDec();

    void addNumberToken(const std::__cxx11::basic_regex<char>& pattern);

    Token getLastToken();
};


#endif //REPPARSE_TOKENIZER_H
