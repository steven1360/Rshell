#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <queue>
#include <iostream>
#include "Token.h"  
#include "ConnectorToken.h"
#include "ExecToken.h"
#include "ArgToken.h"

class Tokenizer {
    public:
        static std::vector<Token*> makeTokens(const std::string& s) {
            std::vector<Token*> v;
            std::string command;

            //s is just a connector or begins with a connector
            if (s.size() >= 2 && ( isAConnector(s.substr(0, 2))  || s.at(0) == ';'  )  || (s.size() == 1 && s.at(0) == ';')  ) {
                return std::vector<Token*> {nullptr};
            }

            for (unsigned i = 0; i < s.size(); i++) {
                if ( ( (i + 1) < s.size() ) && isAConnector( s.substr(i, 2) ) ) {
                    auto pair = getExecAndArg(removeWhitespace(command));
                    v.push_back( new ExecToken(pair.first) );
                    v.push_back( new ExecToken(pair.second) );
                    v.push_back( new ConnectorToken( removeWhitespace( s.substr(i, 2) ) ) );
                    command.clear();
                    i++; //increment one more time bc connector 2 characters ==> read an extra char

                }
                else if ( s.at(i) == ';') {
                    auto pair = getExecAndArg(removeWhitespace(command));
                    v.push_back( new ExecToken(pair.first) );
                    v.push_back( new ExecToken(pair.second) );
                    v.push_back( new ConnectorToken(";") );
                    command.clear();

                }
                else {
                    command += s.at(i);
                }
            }

            if (!command.empty()) {
                    auto pair = getExecAndArg( removeWhitespace(command) );
		    if (!pair.first.empty()) {
                 	   v.push_back( new ExecToken(pair.first) );
		    }
		    if (!pair.second.empty()) {
             	           v.push_back( new ExecToken(pair.second) );
		    }
            }


            return v;
        }
    private:
        static std::pair<std::string, std::string> getExecAndArg(const std::string& command) {
            std::string executable;
            std::string argument;
            int locationOfFirstSpace = -1;

            //Look for first whitespace char in string
            for (unsigned i = 0; i < command.size(); i++) {
                if ( command.at(i) == ' ') {
                    locationOfFirstSpace = i;
                    break;
                }
            }
            //no whitespace char ==> no args
            if (locationOfFirstSpace == -1) {
                executable = command;
            }
            else {
            //break command into executable and argument
                executable = removeWhitespace( command.substr(0, locationOfFirstSpace) );
                argument = removeWhitespace( command.substr(locationOfFirstSpace + 1, command.size() - locationOfFirstSpace + 1) );
            }
            return std::pair<std::string, std::string>(executable, argument);
        }

        static std::string removeWhitespace(const std::string& s) {
            //Remove whitespaces ONLY in front
            std::string str;
            unsigned i = 0;
            unsigned k ;

            for (i = 0; i < s.size(); i++) {
                if (s.at(i) == ' ' ) {
                    continue;
                }
                else {
                    break;
                }
            }

            //Remove whitespaces ONLY in back
            for (k = s.size() - 1; k >= 0; k--) {
                if (s.at(k) == ' ') {
                    continue;
                }
                else {
                    break;
                }
            }

            return s.substr(i, k - i + 1);
        }

        static bool isAConnector(const std::string& connector) {
            if (connector == "&&" || connector == "||") {
                return true;
            }
            return false;
        }

};

#endif
