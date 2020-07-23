#include <iostream>
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/IOToken.h"
#include "../header/CommandToken.h"
#include "../header/ConnectorToken.h"
#include "../header/Executor.h"

int main() {

    std::cout << "$ ";
    std::string input;

    while (std::getline(std::cin, input) ) {
		std::vector<Token*> tokens = Tokenizer::makeTokens(input);
		Executor ex(tokens);
		ex.execute();
		std::cout << "$ ";
    }
}
