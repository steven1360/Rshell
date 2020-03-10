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

		int pipeLocation = locatePipe();
		std::string leftStr;
		std::string rightStr;

		if (pipeLocation != -1) {
			for (unsigned i = 0; i < pipeLocation; i++) {
				leftStr = leftStr + tokens.at(i)->getString() + " ";
			}

			for (unsigned j = pipeLocation + 1; j < tokens.size(); j++) {
				rightStr = rightStr + tokens.at(j)->getString() + " ";
			}

			pipe(leftStr, rightStr);
			return;
		}

		postfix = shuntingYard();
		Token* root = createTree();
		root->execute();


    }
	private:

		int pipe(const std::string& leftStr, const std::string& rightStr) {
			const int PATH_MAX = 420;
			char buffer[PATH_MAX];
			char buffer2[PATH_MAX];
				
			memset(buffer, '\0', PATH_MAX);
			memset(buffer2, '\0', PATH_MAX);

			FILE* in_pipe = popen(leftStr.c_str() , "r");
			FILE* out_pipe = popen(rightStr.c_str(), "w");

			if (!in_pipe || !out_pipe) {
				return 0;
			}

			while(fgets(buffer, PATH_MAX, in_pipe) != nullptr){
				fputs(buffer, out_pipe);
			}

			pclose(in_pipe);
			pclose(out_pipe);

			return 1;
		}

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

		int locatePipe() {
			for (unsigned i = 0; i < tokens.size(); i++) {
				if (tokens.at(i)->getString() == "|") {
					return i;
				}
			}
			return -1;
		}




};



#endif