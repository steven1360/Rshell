#ifndef CONNECTORTOKEN_H
#define CONNECTORTOKEN_H
#include "Token.h"
#include <string>
#include <iostream>
#include "CommandToken.h"

class ConnectorToken : public Token {
    private:
        std::string connector;
    public:
        ConnectorToken(const std::string& s);
        virtual std::string toString();
        virtual std::string token_name();
        virtual bool execute();

};

#endif
