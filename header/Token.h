#ifndef TOKEN_H
#define TOKEN_H
#include <string>


class Token {
	private:
	    Token* left = nullptr;
        Token* right = nullptr;
    public:
        Token() {}
        virtual int execute() = 0;
        virtual std::string toString() = 0;
        void setLeft(Token* t) { left = t; }
        void setRight(Token* t) { right = t; }
};

#endif
