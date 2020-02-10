#include <iostream>
#include "../header/Tokenizer.h"
#include "../header/Token.h"

//"ls -a; echo test && mkdir hi || echo hello; git status"
int main() {
    std::vector<Token*> t = Tokenizer::makeTokens("ls -a; echo test && mkdir hi || echo hello; git status; echo testing && echo watever"); 
    std::cout << t.size() << std::endl;
    for (unsigned i = 0; i < t.size(); i++) {
        std::cout << t.at(i)->val << ' ';
    }
}
