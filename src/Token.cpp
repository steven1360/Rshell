#include "../header/Token.h"

void Token::setLeft(Token* t) {
 	left = t; 
}

void Token::setRight(Token* t) { 
	right = t;
}

Token* Token::getLeft() {
 	return left; 
}

Token* Token::getRight() { 
	return right;
}