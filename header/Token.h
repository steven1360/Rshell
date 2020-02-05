#ifndef TOKEN_H
#define TOKEN_H
#include <string>

class Token {
    public:
    std::string val;
    public:
    Token(std::string s) : val(s) {}
};

#endif