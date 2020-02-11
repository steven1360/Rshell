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
            Token* executable = nullptr;
            Token* argument = nullptr;
            Token* connector = nullptr;

            //probably works only if tokens vector size >= 2
            for (unsigned i = 0; i + 1 < tokens.size(); i++) {
                if (tokens.at(i)->id == Identity::EXECTOKEN && tokens.at(i+1)->id == Identity::ARGTOKEN) {
                    executable = tokens.at(i);
                    argument = tokens.at(i+1);
                }
                else if (tokens.at(i)->id == Identity::EXECTOKEN && tokens.at(i+1)->id == Identity::CONNECTORTOKEN) {
                    executable = tokens.at(i);
                    connector = tokens.at(i+1);
                }
                else {
                    executable = tokens.at(i);
                }

                if (execute(executable, argument) == -1 ) {
                    std::cout << "ERROR executing" << std::endl;
                    return;
                } 
            }
        }
    private:
        int execute(Token* exec, Token* arg) {
	    std::string executable;
	    std::string argument;
	    if (exec) {
		executable = exec->val;
	    }
            if (arg) {
		argument = arg->val;
	    }

	    std::cout << executable << " " << argument << std::endl;

            int value; 	
            int* status;
            std::vector<std::string> parsedArgs = parseArguments(argument);
            const char* exec_cstr = executable.c_str();
            char* arg_cstr[parsedArgs.size()];

            for (int i = 0; i < parsedArgs.size(); i++) {
                arg_cstr[i] = const_cast<char*>( parsedArgs.at(i).c_str() );
            }

	    char* testArr[1];
	    testArr[0] = "-a";

            pid_t process = fork();
            waitpid(0, status,  0);
            if(process == 0){
               value =  execvp(exec_cstr, testArr);    
            }
            else if (process < 0) {
                std::cout << "fork() failed" << std::endl;
            }
	    else {
		return value;
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
