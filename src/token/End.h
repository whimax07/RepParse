//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_END_H
#define REPPARSE_END_H


#include "Token.h"


enum class E_End {
    END
};


class End : public Token {
private:
    const E_End id_;


public:
    explicit End(E_End id) noexcept : id_(id) {}


private:
    void emptyFunToken() override {}


public:
    bool operator==(const End &rhs) const {
        return id_ == rhs.id_;
    }

    bool operator!=(const End &rhs) const {
        return !(rhs == *this);
    }

    std::ostream &operator<<(std::ostream &os) override {
        return os << "END";
    }

};



#endif //REPPARSE_END_H
