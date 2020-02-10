#ifndef ARGTOKEN_H
#define ARGTOKEN_H
#include "Token.h"
#include <string>

class ArgToken : public Token {
    public:
        ArgToken(std::string s) : Token(s) {}
};

#endif