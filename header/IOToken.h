#pragma once
#include "Token.h"
#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h>

class IOToken : public Token {
	private:
		std::string op;
	public:
		IOToken(const std::string& s) {
			op = s; 
		}
		virtual int execute() {

			std::string r = right->getString();
			r.pop_back(); // backslash '\' always gets printed at the end for some reason

			//left side command, right side file. Writes output of command to file
			if (op == ">") {

				int fd = open(const_cast<char*>(r.c_str()), O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG);
				if (fd < 0) {
					perror("open");
				}

				dup2(fd, 1);
				left->execute();
				close(fd);
			}
<<<<<<< HEAD
			else if (op == "<") {//accept input from a file
std::cout << r << std::endl;
				int fd = open(const_cast<char*>(r.c_str()), O_CREAT | O_RDONLY, S_IRWXU | S_IRWXG);
=======
			else if (op == "<") {

				int fd = open(const_cast<char*>(r.c_str()), O_CREAT | O_RDONLY, S_IRWXU | S_IRWXG);
>>>>>>> 427b6afdd32bd7db22e6ae2695b2f0af6c615109
				if (fd < 0) {
					perror("open");
				}
				dup2(fd, 0);
				left->execute();
				close(fd);
			}
			// same thing as '>' accept you append instead of write
			else if (op == ">>") {

				int fd = open(const_cast<char*>(r.c_str()), O_CREAT | O_WRONLY | O_APPEND, S_IRWXU | S_IRWXG);
				if (fd < 0) {
					perror("open");
				}

				dup2(fd, 1);
				left->execute();
				close(fd);
			}
			else if (op == "|") {

			}
		}

		virtual ID getIdentity() {
			return ID::CONNECTOR;
		}

		virtual std::string getString() {
			return op;
		}

};
