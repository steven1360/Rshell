#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <queue>
#include <iostream> 
#include "CommandToken.h"
#include "ConnectorToken.h"
#include "MergedToken.h"

class Tokenizer {
    public:
        static std::vector<Token*> makeTokens(std::string s) {

            removeComment(s);
            std::vector<Token*> v;
            std::string command;
            bool quoteMarkFound = false;


            for (unsigned i = 0; i < s.size(); i++) {

                auto pair = getExecAndArg(command);
            
                //Found quotation mark
                if (!quoteMarkFound && s.at(i) == '"') {
                    quoteMarkFound = true;
                }
                //found connector (&& or ||)
                else if (  (i + 1 < s.size()) && isAConnector( s.substr(i, 2) ) && !quoteMarkFound ) {


                    if (!pair.first.empty() || !pair.second.empty()) {
                        v.push_back( new CommandToken( pair.first, pair.second) );
                    }

                    v.push_back( new ConnectorToken( s.substr(i, 2) ) );

                    command.clear(); //command already transformed into token, so clear the string
                    i++; //increment one more time bc connector 2 characters ==> read an extra char

                }
                //found semicolon
                else if ( s.at(i) == ';' && !quoteMarkFound) {


                    if (!pair.first.empty() || !pair.second.empty()) {

                        v.push_back( new CommandToken( pair.first, pair.second) );
                    }

                    v.push_back( new ConnectorToken( ";" ) );
                    command.clear();
                }
                  //Found the next quotation mark 
                else if (quoteMarkFound) {
                    if (s.at(i) == '"' && (!pair.first.empty() || !pair.second.empty()) ) {
                        quoteMarkFound = false;
                        v.push_back( new CommandToken( pair.first, pair.second) );
                        command.clear();
                    }
                    else {
                        command += s.at(i);
                    }
                }
                //Found parentheses
                else if ( s.at(i) == '(' || s.at(i) == ')') {
                    std::string str;
                    str.push_back(s.at(i));

                    if (!pair.first.empty() || !pair.second.empty()) {
                        v.push_back( new CommandToken( pair.first, pair.second) );
                        command.clear();
                    }
                    v.push_back( new ConnectorToken( str ) );
                }
                //store characters read so far
                else {
                    command += s.at(i);

                }
            }

            //In case string doesn't end with ';' 
            auto pair = getExecAndArg(command);
            if (!command.empty() && (!pair.first.empty() || !pair.second.empty()) ) {
            
                v.push_back( new CommandToken( removeWhitespace(pair.first), removeWhitespace(pair.second)  ) );
            }

            if (!v.empty() && v.back()->getString() == ";") {
                v.pop_back();
            }

            return v;
        }

    private:

        static std::pair<std::string, std::string> getExecAndArg(const std::string& command) {
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

        static std::string removeWhitespace(const std::string& s) {
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

        static bool isAConnector(const std::string& connector) {
            if (connector == "&&" || connector == "||") {
                return true;
            }
            return false;
        }



        static bool isAllWhitespace(const std::string& s) {
            int counter = 0;
            for (unsigned i = 0; i < s.size(); i++) {
                if (s.at(i) == ' ') {
                    counter++;
                }
            }
            if (counter == s.size()) return true;
            return false;
        }

        static void removeComment(std::string& s) {
            //numQuotationsSofar even -> is a comment
            //numQuotationsSofar odd -> is part of argument string
            int numQuotationsSoFar = 0;
            int hashLocation = -1;

            for (unsigned i = 0; i < s.size(); i++) {
                if (s.at(i) == '"') {
                    numQuotationsSoFar++;
                }
                else if (s.at(i) == '#' && numQuotationsSoFar % 2 == 0) {
                    hashLocation = i;
                    break;
                }
            }

            if (hashLocation != -1) {
                s = s.substr(0, hashLocation);
            }
        }

};

#endif
