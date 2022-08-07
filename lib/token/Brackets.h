//
// Created by max on 02/08/22.
//

#ifndef REPPARSE_BRACKETS_H
#define REPPARSE_BRACKETS_H


#include "Token.h"



namespace repper {

    enum class E_Brackets {
        OPEN,
        CLOSE
    };

    constexpr const char *E_BracketsToString(E_Brackets e) {
        switch (e) {
            case E_Brackets::OPEN:
                return "OPEN_BRACKET";
            case E_Brackets::CLOSE:
                return "CLOSE_BRACKET";
            default:
                throw std::invalid_argument(
                        "Token type doesn't match an existing enum."
                );
        }
    }


    class Brackets : public Token {

    private:
        const E_Brackets id_;


    public:
        explicit Brackets(E_Brackets id) noexcept: id_(id) {}


    private:
        void emptyFunToken() override {}


    public:
        bool operator==(const Brackets &rhs) const {
            return id_ == rhs.id_;
        }

        bool operator!=(const Brackets &rhs) const {
            return !(rhs == *this);
        }

        std::ostream const &operator<<(std::ostream &os) override {
            return os << "Brackets{ Type: " << E_BracketsToString(id_) << " }";
        }

    };

}



#endif //REPPARSE_BRACKETS_H