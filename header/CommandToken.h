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
        Command(std::string exec, std::string args) : executable(exec), arguments(args) {}
};


class CommandToken : public Token {
    private:
        Command command;
    public:
        CommandToken(const std::string& command);
        virtual std::string toString();
        virtual std::string token_name();
        virtual bool execute();
    private:
        Command parse_command(const std::string& command);
        std::vector<std::string> parse_arguments(const std::string& s);
        std::string remove_extra_whitespace(const std::string& s);
        bool contains_only_whitespace(const std::string& s);
        bool executeTest(const std::vector<std::string> arguments);
        bool cmpFlagAndPath(const std::string& flag, const std::string& path, struct stat* buf);
        bool flagIsValid(const std::string& s);
    };

#endif
