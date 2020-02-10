#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum Identity {
    ArgToken,
    BadToken,
    ConnectorToken,
    ExecToken
};

class Token {
    public:
        std::string val;
        Token(std::string s) : val(s) {}
        Identity id;
};

#endif