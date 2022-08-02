cmake_minimum_required(VERSION 3.22)
project(RepParse)

set(CMAKE_CXX_STANDARD 20)

add_executable(RepParse
        src/main.cpp
        src/Tokenizer.h src/Tokenizer.cpp
        src/RepParse.h src/RepParse.cpp
        src/token/OldToken.h src/token/OldToken.cpp
        src/token/E_TokenType.h
        src/tree/AST.h
        src/token/Operator.h
        src/token/Token.h
        src/token/Binary.h
        src/token/Unary.h
        src/token/NumericToken.h
        src/token/End.h
        src/token/Sentinel.h
        src/token/Brackets.h
        src/token/Compare.h src/token/Symbols.h src/utils/Utils.h)
