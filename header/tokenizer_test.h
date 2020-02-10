#ifndef TOKENIZER_TEST_H
#define TOKENIZER_TEST_H
#include "gtest/gtest.h"
#include "Tokenizer.h"

TEST(TokenizerTest, validString_1) {
    std::string input = "ls -a; echo test && mkdir hi || echo hello; git status; echo testing && echo watever";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(20, tokens.size());
}

TEST(TokenizerTest, validString_2) {
    std::string input = "ls -a;    echo \"testing\"";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(5, tokens.size());
}

TEST(TokenizerTest, validString_3) {
    std::string input = "echo \"hello\" && ls;      echo        test;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(7, tokens.size());
}


TEST(TokenizerTest, validString_4) {
    std::string input = "exit";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, validString_5) {
    std::string input = "ls";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, validString_6) {
    std::string input = "echo";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, validString_7) {
    std::string input = "pwd";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}


TEST(TokenizerTest, invalidString_1) {
    std::string input = "ls echo mkdir exit pwd ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(2, tokens.size());
}



#endif

