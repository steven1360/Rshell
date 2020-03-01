#pragma once
#include "Token.h"

class IOToken : public Token {
	private:
		std::string op;
	public:
		IOToken(const std::string& s) {
			op = s;

		}
		virtual int execute() {
			
		}

		virtual ID getIdentity() {
			return ID::CONNECTOR;
		}

		virtual std::string getString() {
			return op;
		}

};