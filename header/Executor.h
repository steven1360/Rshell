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
                if (tokens.at(i).identity == Identity::ExecToken && tokens.at(i+1).identity == Identity::ArgToken) {
                    executable = tokens.at(i);
                    argument = tokens.at(i+1);
                }
                else if (tokens.at(i).identity == Identity::ExecToken && tokens.at(i+1).identity == Identity::ConnectorToken) {
                    executable = tokens.at(i);
                    connector = tokens.at(i+1);
                }
                else {
                    executable = tokens.at(i);
                }

                if (execute(executable->val, argument->val) == -1 ) {
                    std::cout << "ERROR executing" << std::endl;
                    return;
                } 
            }
        }
    private:
        int execute(const std::string& executable, const std::string& argument) {
            pid_t pid;
            int* status;
            std::vector<std::string> parsedArgs = parseArguments(argument);
            const char* exec = executable.c_str();
            const char* arg[parsedArgs.size()];

            for (int i = 0; i < parsedArgs.size(); i++) {
                arg[i] = parsedArgs.at(i).c_str();
            }

            pid_t process = fork();
            waitpid(0, status, 0);
            if(process == 0){
                return execvp(exec, arg);
            }
            else if (process < 0) {
                std::cout << "fork() failed" << std::endl;
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