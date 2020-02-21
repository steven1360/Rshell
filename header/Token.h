#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum ID {
	COMMAND,
	CONNECTOR,
};

class Token {
	public:
	    Token* left = nullptr;
        Token* right = nullptr;
        ID id;
    public:
        Token() {}
        virtual int execute() = 0;
        virtual std::string getString() = 0;
        virtual void setLeft(Token* t) { left = t; }
        virtual void setRight(Token* t) { right = t; }
        virtual ID getIdentity() = 0;
};

#endif
