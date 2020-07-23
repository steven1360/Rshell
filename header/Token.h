#ifndef TOKEN_H
#define TOKEN_H
#include <string>


class Token {
	protected:
	    Token* left = nullptr;
        Token* right = nullptr;
    public:
        virtual bool execute() = 0;
        virtual std::string toString() = 0;
        virtual std::string token_name() = 0;
        void setLeft(Token* t);
        void setRight(Token* t);
        Token* getLeft();
        Token* getRight();
};

#endif
