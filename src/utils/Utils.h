//
// Created by max on 02/08/22.
//

#ifndef REPPARSE_UTILS_H
#define REPPARSE_UTILS_H


#include <string>
#include <sstream>


class Utils {

public:
    template<typename... Args>
    static std::string sstr(Args &&... args) {
        std::ostringstream sstr = std::ostringstream();
        // Fold expression.
        ( sstr << ... << args );
        return sstr.str();
    }

};


#endif //REPPARSE_UTILS_H
