#ifndef CONNECTORTOKEN_H
#define CONNECTORTOKEN_H
#include "Token.h"
#include <string>
#include <iostream>
#include "CommandToken.h"

class ConnectorToken : public Token {
    private:
        std::string value;
    public:
        ConnectorToken(const std::string& s) {
            value = s;
            id = ID::CONNECTOR;
        }

        virtual std::string getString() {
            return value;
        }

        virtual ID getIdentity() {
            return ID::CONNECTOR;
        }


        virtual int execute(bool skipNextCommand = false) {
            bool leftStatus = 0;
            bool rightStatus = 0;


            if (left) {
                leftStatus = left->execute(skipNextCommand);
                skipNextCommand = false;
            }


            if (value == "&&" && !leftStatus) {
                skipNextCommand = true;
            }
            else if (value == "||" && leftStatus) {
                skipNextCommand = true;
            }
            else if (value == ";") {

            }


            if (right) {
                rightStatus = right->execute(skipNextCommand);
                skipNextCommand = false;
            }

            if (value == "&&") {
                return leftStatus && rightStatus;
            }
            else if (value == "||") {
                return leftStatus || rightStatus;
            }
            else if (value == ";") {
                return 1;
            }
        }



};

#endif
