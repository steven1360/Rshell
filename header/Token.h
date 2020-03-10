#ifndef TOKEN_H
#define TOKEN_H
#include <string>

enum ID {
	COMMAND,
	CONNECTOR,
    IO
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

        virtual std::pair<std::string, std::string> getExecAndArg(const std::string& command) {
            std::string executable;
            std::string argument;
            int locationOfFirstSpace = -1;


            if ( command.empty() || isAllWhitespace(command) ) {
                return std::pair<std::string, std::string>(executable, argument);
            }

            //Remove leading whitespace from front and back
            std::string newStr = removeWhitespace(command);


            //Look for first whitespace char in string
            for (unsigned i = 0; i < newStr.size(); i++) {
                if ( newStr.at(i) == ' ') {
                    locationOfFirstSpace = i;
                    break;
                }
            }
            //no whitespace char ==> no args
            if (locationOfFirstSpace == -1) {
                executable = newStr;
            }
            else {
            //break command into executable and argument
                executable = removeWhitespace( newStr.substr(0, locationOfFirstSpace) );
                argument = removeWhitespace( newStr.substr(locationOfFirstSpace + 1, newStr.size() - locationOfFirstSpace + 1) );
            }
            return std::pair<std::string, std::string>(executable, argument);
        }
    protected:
        std::string removeWhitespace(const std::string& s) {
            std::string str;
            unsigned i = 0;
            unsigned k = s.size() - 1;

            if (s.empty()) {
                return "";
            }

            //Remove whitespaces from the left
            for (i = 0; i < s.size(); i++) {
                if (s.at(i) != ' ' ) {
                    break;
                }
            }
            //Remove whitespaces from the right
            for (k = s.size() - 1; k >= 0; k--) {
                if (s.at(k) != ' ' ) {
                    break;
                }
            }

            return s.substr(i, k - i + 1);
        }
        bool isAllWhitespace(const std::string& s) {
            int counter = 0;
            for (unsigned i = 0; i < s.size(); i++) {
                if (s.at(i) == ' ') {
                    counter++;
                }
            }
            if (counter == s.size()) return true;
            return false;
        }
};

#endif
