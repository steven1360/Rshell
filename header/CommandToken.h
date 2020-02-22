#ifndef COMMANDTOKEN_H
#define COMMANDTOKEN_H
#include "Token.h"
#include <string>
#include <vector>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <sys/stat.h>


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
        
        virtual int execute() {


            std::vector<std::string> arguments = parseArguments(argument);
            int cStringSize = arguments.size() + 2;  // +1 for exec string, +1 for null terminated string
            int index = 0;
            char* command[cStringSize];

            command[index] = const_cast<char*>( executable.c_str() );
            for (const std::string& str : arguments) {
                command[++index] = const_cast<char*>( str.c_str() );
            }
            command[index + 1] = NULL;
            
            char exitS[] = "exit";
            if(strcmp(command[0], exitS) == 0){
                exit(0);
            }

            char testS[] = "test";
            if (strcmp(command[0], testS) == 0) {
                return executeTest(arguments);
            }


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

        bool executeTest(const std::vector<std::string> arguments) {
            struct stat buf;
            std::string flag;
            std::string path;

            if ( arguments.size() == 2 ) {
                flag = arguments.at(0);
                path = arguments.at(1);
                stat(arguments.at(1).c_str() , &buf);
            }
            else if ( arguments.size() == 1 ) {
                path = arguments.at(0);
                stat(arguments.at(0).c_str(), &buf);
            }

            //Check if valid flag
            if ( !flagIsValid(flag) ) {
                std::cout << "Invalid Flag" << std::endl;
                return 0;
            }


            if (cmpFlagAndPath(flag, path, &buf) ) {
                std::cout << "(True)" << std::endl;
                return 1;
            }
            else {
                std::cout << "(False)" << std::endl;
                return 0;
            }
        }

        bool cmpFlagAndPath(const std::string& flag, const std::string& path, struct stat* buf) {
            bool isAFile = S_ISREG(buf->st_mode);
            bool isADir =  S_ISDIR(buf->st_mode);

            if ( flag == "-f" && isAFile ) {
                return true;
            }
            else if ( flag == "-d" && isADir ) {
                return true;
            }
            else if ( ( flag.empty() || flag == "-e") && (isADir || isAFile) ) {
                return true;
            }

            return false;
        }

        bool flagIsValid(const std::string& s) {

            if ( s == "-f" || s == "-d" || s== "-e" ) {
                return true;
            }
            return false;
        }
    };

#endif
