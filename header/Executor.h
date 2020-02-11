#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "Token.h"
#include <vector>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

class Executor {
    private:
        std::vector<Token*> tokens;
    public:
        Executor(const std::vector<Token*> v) {
		tokens = v;
 	}
	void execute() {
            std::vector<Token*> currTokens;
            bool previousExecuteFailed = false;
            int j = 0;
            Token* executable = nullptr;
            Token* argument = nullptr;
            int x;

            while ( j < tokens.size() ) {

                if ( tokens.at(j)->id != Identity::CONNECTORTOKEN ) {

                    currTokens.push_back( tokens.at(j) );
                    j++;


                }
                else {
                    if ( !previousExecuteFailed ) {
                        if ( tokens.at(j)->val == "||" ) {
                            return;
                        }
                        executable = currTokens.empty() ? nullptr : currTokens.at(0);
                        argument = currTokens.size() >= 2 ? currTokens.at(1) : nullptr;
                        x = execute( executable, argument );
                        currTokens[0] = nullptr;
                        currTokens[1] = nullptr;
                        executable = nullptr;
                        argument = nullptr;
                        j++;
                    }
                    else {
                        if ( tokens.at(j)->val == "&&" ) {
                            return;
                        }
                        executable = currTokens.empty() ? nullptr : currTokens.at(0);
                        argument = currTokens.size() >= 2 ? currTokens.at(1) : nullptr;

                        x = execute( executable, argument);
                        executable = nullptr;
                        argument = nullptr;
                        currTokens[0] = nullptr;
                        currTokens[1] = nullptr;

                        j++;
                        previousExecuteFailed = false;
                    }
                }
                           if (executable) std::cout << executable->val << std::endl;
                          if (argument) std::cout << argument->val << std::endl;

            }

            if ( !currTokens.empty() ) {
                  executable = currTokens.empty() ? nullptr : currTokens.at(0);
                  argument = currTokens.size() >= 2 ? currTokens.at(1) : nullptr;
                if (executable) std::cout << executable->val << std::endl;
                if (argument) std::cout << argument->val << std::endl;
                 x = execute( executable, argument);
                  if (x == -1) {
                    std::cout << "execvp failed" << std::endl;
                  }
                  else {
                 std::cout << "execvp success" << std::endl;
                                                                                                                                      }
	}
    private:
        int execute(Token* ex, Token* arg) {
	    std::string executable;
	    std::string argument;
	
	   if (ex) {
		executable = ex->val;
	   }
	   if (arg) {
		argument = arg->val;
	   }
	    

            int value; 	
            int* status;
            std::vector<std::string> parsedArgs = parseArguments(argument);
	    char* command[500];
	    int i = 0;
	    command[i] =  const_cast<char*>( executable.c_str() ) ;
            for (int j = 0; j < parsedArgs.size(); j++) {
                command[++i] = const_cast<char*>( parsedArgs.at(j).c_str() );
            }
	   // command[i+1] = NULL;
       
            pid_t process = fork();
            waitpid(0, status,  0);
            if(process == 0){
               return execvp(command[0], command); 
            }
            else if (process < 0) {
                std::cout << "fork() failed" << std::endl;
            }
	    else {
		
	    }
        }

        std::vector<std::string> parseArguments(const std::string& s) {
            std::vector<std::string> strs;
            std::string currStr;
            
            for (unsigned i = 0; i < s.size(); i++) {
                if (s.at(i) != ' ') {
                    currStr += s.at(i);
                }
                else {
                    strs.push_back(currStr);
                    currStr.clear();
                }
            }
            
            if (!currStr.empty()) {
                strs.push_back(currStr);
            }
            
            return strs;
        }

};


#endif
