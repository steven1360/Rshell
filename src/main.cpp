#include <iostream>
#include "../header/Tokenizer.h"
#include "../header/Token.h"
#include "../header/Executor.h"

//"ls -a; echo test && mkdir hi || echo hello; git status"
int main() {
    std::vector<Token*> t = Tokenizer::makeTokens("ls -a;"); 
    Executor ex(t);
    ex.execute();

}
