//
// Created by max on 26/07/22.
//

#ifndef REPPARSE_TOKEN_H
#define REPPARSE_TOKEN_H


#include <ostream>



class Token {

public:
    using TokenSPtr = std::shared_ptr<Token>;


public:
    virtual void emptyFunToken();


public:
    virtual bool operator==(const Token &rhs) const {
        return true;
    };

    virtual bool operator!=(const Token &rhs) const {
        return this != &rhs;
    };

    virtual std::ostream const &operator<<(std::ostream &os) {
        return os << "Token{}";
    }

};

inline void Token::emptyFunToken() {  }



#endif //REPPARSE_TOKEN_H
