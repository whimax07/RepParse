cmake_minimum_required(VERSION 3.22)
project(RepParse)

set(CMAKE_CXX_STANDARD 20)

add_executable(RepParse
        src/Tokenizer.h src/Tokenizer.cpp
        src/RepParse.h src/RepParse.cpp
        src/token/Token.h src/token/Token.cpp
        src/token/E_TokenType.h
        src/main.cpp)
