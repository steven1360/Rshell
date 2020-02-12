#include <iostream>
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/Executor.h"

//"ls -a; echo test && mkdir hi || echo hello; git status"
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
