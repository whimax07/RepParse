//
// Created by max on 12/07/22.
//


#include <iostream>
#include "Tokenizer.h"

int main() {
    auto test = Tokenizer::tokenize("123 + 456");
    std::cout << test << std::endl;
}
