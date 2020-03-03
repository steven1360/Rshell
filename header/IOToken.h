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

			if (op == ">") {

				int fd = open(const_cast<char*>(r.c_str()), O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG);
				if (fd < 0) {
					perror("open");
				}

				dup2(fd, 1);
				left->execute();
				close(fd);
			}
			else if (op == "<") {//accept input from a file
std::cout << r << std::endl;
				int fd = open(const_cast<char*>(r.c_str()), O_CREAT | O_WRONLY, S_IRWXU | S_IRWXG);
				if (fd < 0) {
					perror("open");
				}
				dup2(fd, 0);
				right->execute();
				close(fd);
			}
			else if (op == ">>") {
				
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
