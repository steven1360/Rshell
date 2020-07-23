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
#include <iostream>
#include <cstring>

class Executor {
    private:
        std::vector<Token*> tokens;
        std::vector<Token*> postfix;
    public:
        Executor(const std::vector<Token*>& v);
		void execute();
	private:
		int pipe(const std::string& leftStr, const std::string& rightStr);
		std::vector<Token*> shuntingYard();
		Token* createTree();
		bool hasValidParentheses();
		bool hasValidConnectors();
		int locatePipe();

};



#endif
