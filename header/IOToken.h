#pragma once
#include "Token.h"
#include<stdio.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <cassert>
#include <fcntl.h>
#include <vector>
#include <stdio.h>
#include <cstring>

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
				return execute(r, 1, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
			}
			//left side command, right side input from file
			else if (op == "<") {
				return execute(r, 0, O_CREAT | O_RDONLY, S_IRWXU | S_IRWXG);
			}
			// same thing as '>' accept you append instead of write
			else if (op == ">>") {
				return execute(r, 1, O_CREAT | O_APPEND | O_RDWR, S_IRWXU | S_IRWXG);
			}
		}

		virtual ID getIdentity() {
			return ID::CONNECTOR;
		}

		virtual std::string getString() {
			return op;

		}

	private:


		int execute(const std::string& file, int fdToReplace, int flags, mode_t mode) {

			int save = dup(fdToReplace);
			int fd = open(const_cast<char*>(file.c_str()), flags, mode);

			if (fd < 0) {
				perror(const_cast<char*>(file.c_str()));
				return 0;
			}

			dup2(fd, fdToReplace);
			left->execute();
			dup2(save, fdToReplace);

			close(fd);
			return 1;
		}

};
