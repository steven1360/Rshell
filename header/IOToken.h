#pragma once
#include "Token.h"

class IOToken : public Token {
	private:
		std::string op;
		std::string leftOperand;
		std::string rightOperand;
	public:
		IOToken(const std::string& s) {
			//parse the string into op, leftOp, rightOp
			int operatorLocation = -1;

			//Locate operator
			for (unsigned i = 0; i < s.size(); i++) {
				if (s.at(i) == '<' || s.at(i) == '>') {
					operatorLocation = i;
				}
			}

			op = s.at(operatorLocation);
			leftOperand = s.substr(0, operatorLocation);
			rightOperand = s.substr(operatorLocation + 1, s.size());

		}

		virtual int execute() {
			
		}

		virtual ID getIdentity() {
			return ID::IO;
		}

		virtual std::string getString() {
			return leftOperand + " " + op + " " + rightOperand;
		}

};