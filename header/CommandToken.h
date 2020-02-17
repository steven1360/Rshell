#ifndef COMMANDTOKEN_H
#define COMMANDTOKEN_H
#include "Token.h"
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


class CommandToken : public Token {
    private:
        std::string executable;
        std::string argument;
    public:
        CommandToken(const std::string& exec, const std::string& arg) {
            executable = exec;
            argument = arg;

        }
        virtual std::string getString() {
            return executable + " " + argument;
        }

        virtual ID getIdentity() {
            return ID::COMMAND;
        }
        
        virtual int execute(bool skipNextCommand) {
            if (skipNextCommand) return 1;

            std::vector<std::string> arguments = parseArguments(argument);
            int cStringSize = arguments.size() + 2;  // +1 for exec string, +1 for null terminated string
            int index = 0;
            char* command[cStringSize];

            command[index] = const_cast<char*>( executable.c_str() );
            for (const std::string& str : arguments) {
                command[++index] = const_cast<char*>( str.c_str() );
            }
            command[index + 1] = NULL;


            int status;
            pid_t process = fork();

            if (process == 0) {
                if (execvp(command[0], command) < 0) {
                    perror(command[0]);
                    exit(3);
                }

            }
            else if (process < 0) {
                perror("fork() failed");
            }
            else {
                waitpid(0, &status, 0);

                if ( WIFEXITED(status) ) {
                   int exitCode = WEXITSTATUS(status);
                   if (exitCode == 3) {
                      return 0;
                   }
                   else {
                      return 1;
                   }
                }


           }
        }

    private:
        std::vector<std::string> parseArguments(const std::string& s) {
            std::vector<std::string> arguments;
            std::string currentStr;

            for (unsigned i = 0; i < s.size(); i++) {
                if (s.at(i) != ' ') {
                    currentStr += s.at(i);
                }
                else {
                    arguments.push_back(currentStr);
                    currentStr.clear();
                }
            }

            if (!currentStr.empty()) {
                arguments.push_back(currentStr);
            }

            return arguments;
        }
};

#endif
