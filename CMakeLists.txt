cmake_minimum_required(VERSION 3.22)
project(RepParse)

set(CMAKE_CXX_STANDARD 20)

add_executable(RepParse main.cpp
        src src/token/I_Token.h src/token/operators/Binary.h src/token/operators/Unary.h src/token/operators/I_Operator.h src/token/operators/E_Binary.h src/token/operators/E_Unary.h)
