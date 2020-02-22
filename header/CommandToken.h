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

//TEST COMMAND==================================
	    char testS[] = "test";
	    if(strcmp(command[0], testS) == 0){
			
	      std::string exists = "-e";
		    std::string isFile = "-f";
		    std::string isDir = "-d";
		    std::string arg = "filler";		
		    std::string arg2 = "filler";

		if(arguments.empty() == false){//if arguments vector is not empty, fill with first argument
			arg = arguments.at(0);
			if(arguments.size() > 1){
				arg2 = arguments.at(1);
			}
		}
		if(arguments.empty() == true){//test -e will run
			//no arguments
			std::cout << "no arguments" << std::endl;
		}
		else if(arg != exists && arg != isFile && arg != isDir && arg != "filler"){
			//no -e but still runs exists
			//std::cout << "exists" << arg << " " << std:: endl;
			struct stat buf;
			stat(arg.c_str(), &buf);
                        if S_ISREG(buf.st_mode){
                                std::cout << "(True)" << std::endl;
                        }
                        else if S_ISDIR(buf.st_mode){
                                std::cout << "(True)" << std::endl;
                        }
                        else{
                                std::cout << "(False)" << std::endl;
                        }
		}
		else if(arg == exists){//test -e will run
			//run exists
			//std::cout << "exists" << arg << " " << arg2 << std::endl; 
			struct stat buf;
                        stat(arg2.c_str(), &buf);
                        if S_ISREG(buf.st_mode){
                                std::cout << "(True)" << std::endl;
                        }
			else if S_ISDIR(buf.st_mode){
                                std::cout << "(True)" << std::endl;
                        }
                        else{
                                std::cout << "(False)" << std::endl;
                        }
		}	
		else if(arg == isFile){//test -f will run
			//run isFile
			//std::cout << "isFile" << arg << " " << arg2 << std::endl;
			struct stat buf;
			stat(arg2.c_str(), &buf);
			if S_ISREG(buf.st_mode){
				std::cout << "(True)" << std::endl;
			}
			else{
				std::cout << "(False)" << std::endl;
			}
		}
		else if(arg == isDir){//test -d will run
			//run isDir
			//std::cout << "isDir" << arg << " " << arg2 << std::endl;
			struct stat buf;
                        stat(arg2.c_str(), &buf);
                        if S_ISDIR(buf.st_mode){
                                std::cout << "(True)" << std::endl;
                        }
                        else{
                                std::cout << "(False)" << std::endl;
                        }
		}
	
	    }
//==============================================

         


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
