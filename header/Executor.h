#ifndef EXECUTOR_H
#define EXECUTOR_H

#include "Token.h"
#include <vector>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stack>
#include <queue>

class Executor {
    private:
        std::vector<Token*> tokens;
        std::vector<Token*> postfix;
    public:
        Executor(const std::vector<Token*>& v) {
		tokens = v;
 	}
	void execute() {
		if (!hasValidParentheses()) {
			std::cout << "Error: Invalid Parentheses" << std::endl;
			return;
		}

		if (tokens.empty()) {
			return;
		}

		postfix = shuntingYard();
		Token* root = createTree();
		root->execute();


    }
	private:

		std::vector<Token*> shuntingYard() {
			std::queue<Token*> out;
			std::stack<Token*> ops;
			std::vector<Token*> postfix;

			for (Token* t : tokens) {
				if (t->getIdentity() == ID::COMMAND || t->getIdentity() == ID::IO) {
					out.push(t);
				}

				if ( t->getIdentity() == ID::CONNECTOR && t->getString() != ")" && t->getString() != "(" ) {
					if (ops.empty()) {
						ops.push(t);
					}
					else if (ops.top()->getString() != "(") {
						out.push( ops.top() );
						ops.pop();
						ops.push(t);
					}
					else if (ops.top()->getString() == "(") {
						ops.push(t);
					}
				}

				if (t->getString() == "(") {
					ops.push(t);
				}
				if (t->getString() == ")") {
					while (ops.top()->getString() != "(") {

						out.push( ops.top() );
						ops.pop();
					}
					if ( ops.top()->getString() == "(") {
						ops.pop();
					}
				}

			}



			while (!ops.empty()) {
				out.push( ops.top() );
				ops.pop();
			}

			while (!out.empty()) {
				postfix.push_back( out.front() );
				out.pop();
			}


			return postfix;
		}

		Token* createTree() {
			std::stack<Token*> s;
			Token* currToken = nullptr;


			for (unsigned i = 0; i < postfix.size(); i++) {

				currToken = postfix.at(i);

				if (currToken->getIdentity() == ID::COMMAND || currToken->getIdentity() == ID::IO ) {
					s.push(currToken);
				}
				else if (currToken->getIdentity() == ID::CONNECTOR) {
					Token* right =  s.top();
					s.pop();
					Token* left = s.top();
					s.pop();

					currToken->setLeft(left);
					currToken->setRight(right);

					s.push(currToken);
				}

			}

			return s.top();

		}

		void inOrder(Token* t) {
			if (t) {
				inOrder(t->left);
				std::cout << t->getString() << " ";
				inOrder(t->right);
			}
		}

		bool hasValidParentheses() {
			//Stores locations of parantheses
			std::vector<int> leftParentheses;
			std::vector<int> rightParentheses;

			for (unsigned i = 0; i < tokens.size(); i++) {
				if (tokens.at(i)->getString() == "(") {
					leftParentheses.push_back(i);
				}
				else if (tokens.at(i)->getString() == ")") {
					rightParentheses.push_back(i);
				}
			}

			if (leftParentheses.size() != rightParentheses.size()) {
				return false;
			}

			for (unsigned i = 0; i < leftParentheses.size(); i++) {
				//left parenthesis position should always be less than right parenthesis
				if (leftParentheses.at(i) > rightParentheses.at(i)) {
					return false;
				}
			}

			return true;
		}




};



#endif