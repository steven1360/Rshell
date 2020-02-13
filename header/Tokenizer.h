#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <queue>
#include <iostream> 
#include "ConnectorToken.h"
#include "ExecToken.h"
#include "ArgToken.h"
#include "BadToken.h"

class Tokenizer {
    public:
        static std::vector<Token*> makeTokens(std::string s) {

            //Look for comment in inputs
            int hashLocation = findHashSymbol(s);
            if (hashLocation != -1) {
                s = s.substr(0, hashLocation);
            }

            std::vector<Token*> v;
            std::string command;

            //edge cases
            if (s.empty()) {
                return v;
            }
            if (s.size() >= 2) {
                if (s.at(0) == '|' && s.at(1) == '|') {
                    return std::vector<Token*> { new BadToken("||") };
                }
                else if (s.at(0) == '&' && s.at(1) == '&') {
                    return std::vector<Token*> { new BadToken("&&") };
                }
            }
            if (s.size() >= 1 && s.at(0) == ';') {
                return std::vector<Token*> { new BadToken(";") };
            } 
            if (isAllWhitespace(s)) {
                return std::vector<Token*> { new BadToken(" ") };
            }

            //Break up string by connectors
            for (unsigned i = 0; i < s.size(); i++) {
                      //  std::cout << "~~~curr char~~~:" << s.at(i) << ":~~~curr char~~~" << std::endl;

                if ( ( (i + 1) < s.size() ) && isAConnector( s.substr(i, 2) ) ) {
                    auto pair = getExecAndArg(removeWhitespace(command));
			
			
			//REMOVE ME LATER
		//	std::cout << "~~first pair~~~:" << pair.first << ":~~~first pair~~~" << std::endl;
                  //      std::cout << "~~second pair~~~:" << pair.second << ":~~~second pair~~~" << std::endl;
		//	std::cout << "Connector: " << s.substr(i, 2) << std::endl;

                        if (!pair.first.empty()  ) {
                            v.push_back( new ExecToken(pair.first) );
			}

                        if (!pair.second.empty() ) {
                            v.push_back( new ArgToken(pair.second) );
			}
                    v.push_back( new ConnectorToken( removeWhitespace( s.substr(i, 2) ) ) );
                    command.clear();
                    i++; //increment one more time bc connector 2 characters ==> read an extra char

                }
                else if ( s.at(i) == ';') {
                    auto pair = getExecAndArg(removeWhitespace(command));

                    if (!pair.first.empty()) 
                            v.push_back( new ExecToken(pair.first) );
                    if (!pair.second.empty()) 
                                v.push_back( new ArgToken(pair.second) );

                    v.push_back( new ConnectorToken(";") );
                    command.clear();

                }
                else {
                    command += s.at(i);
                }
            }

            //In case string doesn't end with ';'
            if (!command.empty() ) {

		 auto pair = getExecAndArg( removeWhitespace(command) );
		if ( !v.empty() ) {
			if (!pair.first.empty() && v.back()->id == Identity::CONNECTORTOKEN ) {
				v.push_back( new ExecToken(pair.first) ) ;
			}
			if (!pair.second.empty() && v.back()->id == Identity::EXECTOKEN ) {
				v.push_back( new ArgToken(pair.second) );
			}
		}
		else {
				
               		 if (!pair.first.empty()) 
                       		 v.push_back( new ExecToken(pair.first) );
               		 if (!pair.second.empty()) 
                       		 v.push_back( new ArgToken(pair.second) );
                }
       	    }
	   
	     combineTokensWithQuotes(v, s);
	     removeAllQuotes(v);    
             return v;

	}
    private:
	static void removeAllQuotes(std::vector<Token*>& v ) {
	    for (unsigned i = 0; i < v.size(); i++) {
		std::string& s = v.at(i)->val;
		for (unsigned j = 0; j < s.size(); j++) {
		    if ( s.at(j) == '"') {
			s.erase(j, 1);
		    }
		}
	    }

	}

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
	
	   if ( isAllWhitespace(s)  ) {
		return "";
	   }

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

        //Any tokens that has one quotation mark means not done combining
        static bool containsSingleQuote(const std::vector<Token*> & v) {
            for (auto token : v) {
                int count = 0;
                for (unsigned i = 0; i < token->val.size(); i++) {
                    if (token->val.at(i) == '"') count++;
                }
                if (count == 1) return true;
            }
            return false;
        }

        static bool containsSingleQuote(const std::string& s) {
            int count = 0;
            for (unsigned i = 0; i < s.size(); i++) {
                if (s.at(i) == '"') count++;
            }

            if (count == 1) return true;
            return false;
        }

        static std::queue<std::string> findArguments(const std::string& input) {
            //Assuming number of quotations in string is always even
            std::vector<int> quotationIndices;
            std::queue<std::string> q;

            for (unsigned i = 0; i < input.size(); i++) {
                if (input.at(i) == '"') quotationIndices.push_back(i);
            }   

            for (unsigned i = 0; i + 1 < quotationIndices.size(); i += 2) {
                q.push( input.substr(quotationIndices.at(i), quotationIndices.at(i+1) - quotationIndices.at(i) + 1) );
            }
            return q; //returns strings that contain quotes
        }
        
        static void combineTokensWithQuotes(std::vector<Token*> & v, const std::string& input) {
            std::queue<std::string> arguments = findArguments(input);

            while (containsSingleQuote(v)) {
                std::vector<std::vector<Token*>::iterator> temp;
                Token* combinedToken = nullptr;
                std::string argument;

                //get tokens that have quotation marks
                for (std::vector<Token*>::iterator it = v.begin(); it != v.end(); it++) {
                    if ( containsSingleQuote( (*it)->val ) ) {
                        temp.push_back(it);
                    }
                    //only two quotes at a time
                    if (temp.size() == 2) break;
                }

		
		
                combinedToken = new ArgToken(arguments.front());
                arguments.pop();

                //remove
                v.erase(temp.at(0), temp.at(1) + 1);

                //insert combined
                v.insert(temp.at(0), combinedToken);
            }
        }

	

        static int findHashSymbol(const std::string& s) {
            //numQuotationsSofar even -> is a comment
            //numQuotationsSofar odd -> is part of argument string
            int numQuotationsSoFar = 0;

            for (unsigned i = 0; i < s.size(); i++) {
                if (s.at(i) == '"') {
                    numQuotationsSoFar++;
                }
                else if (s.at(i) == '#' && numQuotationsSoFar % 2 == 0) {
                    return i;
                }
            }
            return -1;
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

};

#endif
