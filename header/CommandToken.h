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


struct Command {
    public:
        std::string executable;
        std::string arguments;
        Command() {}
        Command(std::string executable, std::string arguments) : executable(executable), arguments(arguments) {}
};


class CommandToken : public Token {
    private:
        std::string executable;
        std::string arguments;
    public:
        CommandToken(const std::string& command);
        virtual std::string toString();
        virtual bool execute();
    private:
        Command parse_command(std::string command);
        std::string remove_extra_whitespace(const std::string& s);
        bool contains_only_whitespace(const std::string& s);
        std::vector<std::string> parse_arguments(const std::string& s);
        bool executeTest(const std::vector<std::string> arguments);
        bool cmpFlagAndPath(const std::string& flag, const std::string& path, struct stat* buf);
        bool flagIsValid(const std::string& s);
    };

#endif
