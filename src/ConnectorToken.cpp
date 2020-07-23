#include "../header/ConnectorToken.h"

ConnectorToken::ConnectorToken(const std::string& s) {
    connector = s;
}

std::string ConnectorToken::toString() {
    return connector;
}

std::string ConnectorToken::token_name() {
    return "ConnectorToken";
}

bool ConnectorToken::execute() {
    bool leftStatus = 0;
    bool rightStatus = 0;


    if (left) {
        leftStatus = left->execute();
    }


    if (connector == "&&" && !leftStatus) {
        return 0;
    }
    else if (connector == "||" && leftStatus) {
        return 1;
    }
    else if (connector == ";") {

    }


    if (right) {
        rightStatus = right->execute();
    }

    if (connector == "&&") {
        return leftStatus && rightStatus;
    }
    else if (connector == "||") {
        return leftStatus || rightStatus;
    }
    else if (connector == ";") {
        return 1;
    }
}

