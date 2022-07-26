cmake_minimum_required(VERSION 3.22)
project(RepParse)

set(CMAKE_CXX_STANDARD 20)

add_executable(RepParse
        src/Tokenizer.h src/Tokenizer.cpp
        src/RepParse.h src/RepParse.cpp
        src/token/OldToken.h src/token/OldToken.cpp
        src/token/E_TokenType.h
        src/main.cpp src/tree/AST.h src/token/Operator.h src/token/Token.h src/token/Binary.h src/token/Unary.h src/token/NumberToken.h src/token/End.h src/token/Sentinel.h)
