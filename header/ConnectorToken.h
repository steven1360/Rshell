#ifndef CONNECTORTOKEN_H
#define CONNECTORTOKEN_H
#include "Token.h"
#include <string>

class ConnectorToken : public Token {
    public:
        ConnectorToken(std::string s) : Token(s) {id = Identity::CONNECTORTOKEN;}
};

#endif