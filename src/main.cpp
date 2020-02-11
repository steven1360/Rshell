#include <iostream>
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "executioner.cpp"
//"ls -a; echo test && mkdir hi || echo hello; git status"
int main() {
    std::string a = "ls -a; echo test && mkdir hi || echo hello; git status";
    executioner(a); 
	std::cout << "Test";
}
