//
// Created by max on 12/07/22.
//

#ifndef REPPARSE_E_TOKENTYPE_H
#define REPPARSE_E_TOKENTYPE_H



enum class E_TokenType {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    NEGATE,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    SENTENTIAL,
    END,
    NUMBER
};


constexpr const char* E_TokenTypeToString(E_TokenType e) {
    switch (e) {
        case E_TokenType::ADD: return "ADD";
        case E_TokenType::SUBTRACT: return "SUBTRACT";
        case E_TokenType::MULTIPLY: return "MULTIPLY";
        case E_TokenType::DIVIDE: return "DIVIDE";
        case E_TokenType::NEGATE: return "NEGATE";
        case E_TokenType::OPEN_BRACKET: return "OPEN_BRACKET";
        case E_TokenType::CLOSE_BRACKET: return "CLOSE_BRACKET";
        case E_TokenType::SENTENTIAL: return "SENTENTIAL";
        case E_TokenType::END: return "END";
        case E_TokenType::NUMBER: return "NUMBER";
        default: throw std::invalid_argument(
            "Token type doesn't match an existing enum."
        );
    }
}


inline std::ostream &operator<<(std::ostream &os, E_TokenType const &type) {
    os << E_TokenTypeToString(type);
    return os;
}


#endif //REPPARSE_E_TOKENTYPE_H
