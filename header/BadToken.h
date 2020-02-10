#ifndef BADTOKEN_H
#define BADTOKEN_H
#include <string>
#include "Token.h"

class BadToken : public Token {
    public:
        BadToken(std::string s) : Token(s) {id = Identity::BadToken;}
};

#endif