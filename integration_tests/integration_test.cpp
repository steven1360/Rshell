#include <iostream>
#include "../header/Tokenizer.h"
#include "../header/Executor.h"
#include "../header/Token.h"
#include <vector>



int main(int argv, char** argc) {
    std::string input;
    for (int i = 1; i < argv; i++) {
	input = input + argc[i];
    }
    std::cout << "input: " << input << std::endl;
    std::cout << "-----------------------------------------------------" << std::endl;
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    Executor ex(tokens);
    ex.execute();
    std::cout << "-----------------------------------------------------" << std::endl;
}
