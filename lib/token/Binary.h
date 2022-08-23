//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_BINARY_H
#define REPPARSE_BINARY_H


#include "Operator.h"
#include "Token.h"
#include "NumberVariant.h"


namespace repper {

enum class E_Binary {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    RIGHT_SHIFT,
    LEFT_SHIFT,
    BIT_AND,
    BIT_OR
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


// Constructors and assignment.
public:
    constexpr Binary(E_Binary id, int precedence, bool isLeftAssociative)
    noexcept: id_(id), precedence_(precedence),
              isLeftAssociative_(isLeftAssociative) {}

    Binary(const Binary &toCopy) = default;

    Binary(Binary &&toMove) = default;

    ~Binary() = default;

    Binary & operator=(Binary &&toMove) noexcept {
        auto temp = Binary(toMove);
        std::swap(*this, temp);
        return *this;
    };


// Polymorphism functions.
private:
    void emptyFunToken() override {}

    [[nodiscard]]
    bool isEqual(const Token &rhs) const override {
        auto rhsCasted = dynamic_cast<const Binary *>(&rhs);
        return this->id_ == rhsCasted->id_;
    }


// Getter, Setters and operators.
public:
    std::ostream const &operator<<(std::ostream &os) override {
        return os << "Binary{ Type: " << E_BinaryToString(id_)
                  << ", Precedence: " << precedence_
                  << ", Left Associative: " << isLeftAssociative_
                  << " }";
    }

    [[nodiscard]]
    int getPrecedence() const {
        return precedence_;
    }

    [[nodiscard]]
    bool isLeftAssociative() const {
        return isLeftAssociative_;
    }


    template<class T, class U>
    constexpr TypedNumbers evalBinary(const T lhs, const U rhs) const {
        switch (id_) {
            case E_Binary::MULTIPLY: return lhs * rhs;
            case E_Binary::DIVIDE: return lhs / rhs;
            case E_Binary::ADD: return lhs + rhs;
            case E_Binary::SUBTRACT: return lhs - rhs;
            case E_Binary::RIGHT_SHIFT: return lhs >> rhs;
            case E_Binary::LEFT_SHIFT: return lhs << rhs;
            case E_Binary::BIT_AND: return lhs & rhs;
            case E_Binary::BIT_OR: return lhs | rhs;
        }
    }

};

}

#endif //REPPARSE_BINARY_H
