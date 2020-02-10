#ifndef EXECTOKEN_H
#define EXECTOKEN_H
#include "Token.h"
#include <string>

class ExecToken : public Token {
    public:
        ExecToken(std::string s) : Token(s) {id = Identity::EXECTOKEN;}
};

#endif