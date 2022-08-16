//
// Created by max on 16/08/22.
//

#ifndef REPPARSERUNNABLE_EVALAST_H
#define REPPARSERUNNABLE_EVALAST_H


#include "NumericToken.h"
#include "../tree/AST.h"

namespace repper {



TypedNumbers evaluate(const AST::AstSPtr& toEval) {
    auto nodeValue = toEval->getValue();

    TypedNumbers out = std::visit(
            [toEval](auto nodeValue) -> TypedNumbers {
                using T = std::decay_t<decltype(nodeValue)>;

                if constexpr (std::is_same_v<T, NumericToken>) {
                    return nodeValue.parse();
                } else if constexpr (std::is_same_v<T, Unary>) {
                    return std::visit(
                            [nodeValue](auto in) -> TypedNumbers {
                                return nodeValue.evalUnary(in);
                            },
                            evaluate(toEval->getLeft())
                    );
                } else if constexpr (std::is_same_v<T, Binary>) {
                    return std::visit(
                            [nodeValue](auto in1, auto in2) -> TypedNumbers {
                                return nodeValue.evalBinary(in1, in2);
                            },
                            evaluate(toEval->getLeft()),
                            evaluate(toEval->getRight())
                    );
                }
            } ,
            nodeValue
    );

    return out;
}


}


#endif //REPPARSERUNNABLE_EVALAST_H
