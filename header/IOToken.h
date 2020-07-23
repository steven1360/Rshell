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
		std::string op; //short for operator
	public:
		IOToken(const std::string& s);
		virtual bool execute();
		virtual std::string toString();
		virtual std::string token_name();

	private:
		bool execute(const std::string& file, int fdToReplace, int flags, mode_t mode);

};
