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
        Executor(const std::vector<Token*>& v) {
		tokens = v;
 	}
	void execute() {
        Token* executable = nullptr;
        Token* next = nullptr;
	int size = tokens.size();
	int x;
	bool prevCommandFailed = false;

	std::cout << "size: " << tokens.size() << std::endl;
        for (unsigned i = 0; i < size; i++) {

            if ( tokens.at(i)->id == Identity::EXECTOKEN) {
                executable = tokens.at(i);
                next = ( i+1 < size ) ? tokens.at(i+1) : nullptr;

                if (next && next->id == Identity::ARGTOKEN) {
                    x = execute(executable, next);
		    i++;
                }
		//command either ends with a connector or an argument
		else if (next && next->id == Identity::CONNECTORTOKEN) {
		    x = execute(executable, nullptr);
		}
		else if (!next) {
		    x = execute(executable, nullptr);
		}
            }
            else if ( tokens.at(i)->id == Identity::CONNECTORTOKEN ) {
		if (prevCommandFailed) {
		    prevCommandFailed = false;
		    if (tokens.at(i)->val == "&&") {
			i++; //skip next token
			continue;
		    }
		    else if (tokens.at(i)->val == "||") {
			continue;
		    }
		    else if (tokens.at(i)->val == ";") {
			continue;
		    } 
		}
		else {
		    if (tokens.at(i)->val == "||") {
			i++; //skips next token.
			continue;
		    }	
		    else {
			continue;
		    }	
		}
            }
	    else if ( tokens.at(i)->id == Identity::ARGTOKEN ) {
		continue;
	    }
		
	    std::cout << "i:  " << i << std::endl;
	    if (x == -1) {
		std::cout << "execvp failed" << std::endl;
		prevCommandFailed = true;
	    }
	    else {
		std::cout << "execvp worked" << std::endl;
	    }
 
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
	
	    
		
            int* status;
            std::vector<std::string> parsedArgs = parseArguments(argument);
	
            char* command[parsedArgs.size()+1];
            int i = 0;

            command[i] =  const_cast<char*>( executable.c_str() ) ;
            for (int j = 0; j < parsedArgs.size(); j++) {
                command[++i] = const_cast<char*>( parsedArgs.at(j).c_str() );
            }
            command[i+1] = NULL;
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
