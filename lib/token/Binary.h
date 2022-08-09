//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_BINARY_H
#define REPPARSE_BINARY_H


#include "Operator.h"
#include "Token.h"


namespace repper {

    enum class E_Binary {
        ADD,
        SUBTRACT,
        MULTIPLY,
        DIVIDE
    };

    constexpr const char *E_BinaryToString(E_Binary e) {
        switch (e) {
            case E_Binary::ADD:
                return "ADD";
            case E_Binary::SUBTRACT:
                return "SUBTRACT";
            case E_Binary::MULTIPLY:
                return "MULTIPLY";
            case E_Binary::DIVIDE:
                return "DIVIDE";
            default:
                throw std::invalid_argument(
                        "Token type doesn't match an existing enum."
                );
        }
    }


    class Binary : public Operator {

    private:
        const E_Binary id_;

        const int precedence_;

        const bool isLeftAssociative_;


    public:
        Binary(E_Binary id, int precedence, bool isLeftAssociative) noexcept:
                id_(id), precedence_(precedence),
                isLeftAssociative_(isLeftAssociative) {}


    private:
        void emptyFunToken() override {}

        [[nodiscard]]
        bool isEqual(const Token &rhs) const override {
            auto rhsCasted = dynamic_cast<const Binary *>(&rhs);
            return this->id_ == rhsCasted->id_;
        }


    public:
        [[nodiscard]]
        int getPrecedence() const {
            return precedence_;
        }

        [[nodiscard]]
        bool isLeftAssociative() const {
            return isLeftAssociative_;
        }

        std::ostream const &operator<<(std::ostream &os) override {
            return os << "Binary{ Type: " << E_BinaryToString(id_)
                      << ", Precedence: " << precedence_
                      << ", Left Associative: " << isLeftAssociative_
                      << " }";
        }

    };

}

#endif //REPPARSE_BINARY_H
