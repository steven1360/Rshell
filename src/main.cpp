#include <iostream>
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/Executor.h"
#include "executioner.cpp"

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
<<<<<<< HEAD
    std::string a = "ls -a; echo test && mkdir hi || echo hello; git status";
	executioner(a);
=======
>>>>>>> 5a7c8987b24331bd13721cc676356c22b3575119
}
