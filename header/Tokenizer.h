#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <vector>
#include <queue>
#include <iostream> 
#include "../header/CommandToken.h"
#include "../header/ConnectorToken.h"
#include "../header/IOToken.h"

class Tokenizer {
    public:
        static std::vector<Token*> makeTokens(std::string s); 
    private:
        static bool isAllWhitespace(const std::string& s);
        static bool isAConnector(const std::string& connector);
        static void removeComment(std::string& s);
        static bool has_IO_operator(const std::string& s);
        static bool has_pipe(const std::string& s);

};

#endif
