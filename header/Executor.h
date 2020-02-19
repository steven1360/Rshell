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
		postfix = shuntingYard();

		for (Token* t : postfix) {
			std::cout << "~~~:" << t->getString() << ":~~~" << std::endl;
		}

		Token* root = createTree();
		root->execute();


    }
	private:

		std::vector<Token*> shuntingYard() {
			std::queue<Token*> out;
			std::stack<Token*> ops;
			std::vector<Token*> postfix;

			for (Token* t : tokens) {
				if (t->getIdentity() == ID::COMMAND) {
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

				if (currToken->getIdentity() == ID::COMMAND ) {
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




};



#endif