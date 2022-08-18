//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_UNARY_H
#define REPPARSE_UNARY_H


#include "Operator.h"
#include "NumberVariant.h"


namespace repper {

enum class E_Unary {
    NEGATE
};

constexpr const char *E_UnaryToString(E_Unary e) {
    switch (e) {
        case E_Unary::NEGATE:
            return "NEGATE";
        default:
            throw std::invalid_argument(
                    "Token type doesn't match an existing enum."
            );
    }
}


class Unary : public Operator {
private:
    const E_Unary id_;

    const int precedence_;


public:
    constexpr Unary(E_Unary id, int precedence) noexcept:
            id_(id), precedence_(precedence) {}

    Unary(const Unary &toCopy) = default;

    Unary(Unary &&toMove) = default;

    ~Unary() = default;

    Unary & operator=(Unary &&toMove) noexcept {
        auto temp = Unary(toMove);
        std::swap(*this, temp);
        return *this;
    };


private:
    void emptyFunToken() override {}

    [[nodiscard]]
    bool isEqual(const Token &rhs) const override {
        auto rhsCasted = dynamic_cast<const Unary *>(&rhs);
        return this->id_ == rhsCasted->id_;
    }


public:
    [[nodiscard]]
    int getPrecedence() const {
        return precedence_;
    }

    bool operator==(const Unary &rhs) const {
        return id_ == rhs.id_;
    }

    bool operator!=(const Unary &rhs) const {
        return !(rhs == *this);
    }

    std::ostream const &operator<<(std::ostream &os) override {
        return os << "Unary{ Type: " << E_UnaryToString(id_)
                  << ", Precedence: " << precedence_
                  << " }";
    }


    template<class T>
    constexpr TypedNumbers evalUnary(const T lhs) const {
        switch (id_) {
            case E_Unary::NEGATE: return -lhs;
        }
    }

};

}



#endif //REPPARSE_UNARY_H
