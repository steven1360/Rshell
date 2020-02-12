#include <iostream>
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/Executor.h"

//"ls -a; echo test && mkdir hi || echo hello; git status"
int main() {
    std::vector<Token*> t = Tokenizer::makeTokens("echo hey && echolol || echo test; echo yo"); 
    for (int i = 0; i < t.size(); i++) {
	      std::cout << "~~~TOKEN~~~:" << t.at(i)->val << ", id: " << t.at(i)->id  << std::endl;
    }
    Executor ex(t);
    ex.execute();
}
