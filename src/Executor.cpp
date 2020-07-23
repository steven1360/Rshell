#include "../header/Executor.h"

Executor::Executor(const std::vector<Token*>& v) {
	tokens = v;
}

void Executor::execute() {

	if (!hasValidParentheses()) {
		std::cout << "Error: Invalid Parentheses" << std::endl;
		return;
	}

	if (tokens.empty()) {
		return;
	}

	if ( !hasValidConnectors()) {
		std::cout << "Error: invalid syntax" << std::endl;
		return;
	}

	int pipeLocation = locatePipe();
	std::string leftStr; //strings to the left of pipe operator
	std::string rightStr; //strings to the right of pipe operator

	if (pipeLocation != -1) {
		for (unsigned i = 0; i < pipeLocation; i++) {
			leftStr = leftStr + tokens.at(i)->toString() + " ";
		}

		for (unsigned j = pipeLocation + 1; j < tokens.size(); j++) {
			rightStr = rightStr + tokens.at(j)->toString() + " ";
		}

		pipe(leftStr, rightStr);
		return;
	}

	postfix = shuntingYard();
	Token* root = createTree();
	root->execute();
}

int Executor::pipe(const std::string& leftStr, const std::string& rightStr) {
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


std::vector<Token*> Executor::shuntingYard() {
	std::queue<Token*> out;
	std::stack<Token*> ops;
	std::vector<Token*> postfix;

	for (Token* t : tokens) {
		if (t->token_name() == "CommandToken" || t->token_name() == "IOToken") {
			out.push(t);
		}

		if ( t->token_name() == "ConnectorToken" && t->toString() != ")" && t->toString() != "(" ) {
			if (ops.empty()) {
				ops.push(t);
			}
			else if (ops.top()->toString() != "(") {
				out.push( ops.top() );
				ops.pop();
				ops.push(t);
			}
			else if (ops.top()->toString() == "(") {
				ops.push(t);
			}
		}

		if (t->toString() == "(") {
			ops.push(t);
		}
		if (t->toString() == ")") {
			while (ops.top()->toString() != "(") {

				out.push( ops.top() );
				ops.pop();
			}
			if ( ops.top()->toString() == "(") {
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


Token* Executor::createTree() {
	std::stack<Token*> s;
	Token* currToken = nullptr;


	for (unsigned i = 0; i < postfix.size(); i++) {

		currToken = postfix.at(i);

		if (currToken->token_name() == "CommandToken" || currToken->token_name() == "IOToken" ) {
			s.push(currToken);
		}
		else if (currToken->token_name() == "ConnectorToken") {
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


bool Executor::hasValidParentheses() {
	//Stores locations of parantheses
	std::vector<int> leftParentheses;
	std::vector<int> rightParentheses;

	for (unsigned i = 0; i < tokens.size(); i++) {
		if (tokens.at(i)->toString() == "(") {
			leftParentheses.push_back(i);
		}
		else if (tokens.at(i)->toString() == ")") {
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

bool Executor::hasValidConnectors() {
	if (tokens.at(0)->token_name() == "ConnectorToken") {
		return false;
	}
	if (tokens.back()->token_name() == "ConnectorToken") {
		return false;
	}

	for (unsigned i = 0; i + 1 < tokens.size(); i++) {
		if (tokens.at(i)->token_name() == "ConnectorToken" &&  tokens.at(i+1)->token_name() == "ConnectorToken") {
			return false;
		}
	}

	return true;
}

int Executor::locatePipe() {
	for (unsigned i = 0; i < tokens.size(); i++) {
		if (tokens.at(i)->toString() == "|") {
			return i;
		}
	}
	return -1;
}