#ifndef TOKENIZER_TEST_H
#define TOKENIZER_TEST_H
#include "gtest/gtest.h"
#include "Tokenizer.h"

TEST(TokenizerTest, validString_1) {
    std::string input = "ls -a; echo test && mkdir hi || echo hello; git status; echo testing && echo watever";
    std::string output;
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    for (Token* t : tokens) {
        output += t->val;
    }
    EXPECT_EQ(input, output);
}

#endif

