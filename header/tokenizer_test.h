#ifndef TOKENIZER_TEST_H
#define TOKENIZER_TEST_H
#include "gtest/gtest.h"
#include "Tokenizer.h"

TEST(TokenizerTest, validString_1) {
    std::string input = "ls -a; echo test && mkdir hi || echo hello; git status; echo testing && echo watever";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(13, tokens.size());
}

TEST(TokenizerTest, validString_2) {
    std::string input = "ls -a;    echo \"testing\" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
}

TEST(TokenizerTest, validString_3) {
    std::string input = "echo \"hello\" && ls;      echo        test;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(5, tokens.size());
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

TEST(TokenizerTest, validString_8) {
    std::string input = "ls -a && ls";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
}

TEST(TokenizerTest, validString_9) {
    std::string input = "echo \"hello\" && echo no;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
}

TEST(TokenizerTest, validString_10) {
    std::string input = "mkdir newfolder;   echo heya";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
}

TEST(TokenizerTest, validString_11) {
    std::string input = "echo \"hello && goodbye\" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, validString_12) {
    std::string input = "mkdir \"newfolder&&foldddddddddd\" && echo \"black# || blue \" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
}

TEST(TokenizerTest, validString_13) {
    std::string input = "pwd && ls #-a";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
}

TEST(TokenizerTest, validString_14) {
    std::string input = "  echo \" testing #123 \" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, validString_15) {
    std::string input = "ls; echo \"hi\" && mkdir \"folder\" # echo \"whatever\"      ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(5, tokens.size());
}

TEST(TokenizerTest, validString_16) {
    std::string input = "ls; echo \"hi\" #&& mkdir \"folder\" # echo \"whatever\"      && pwd ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
}

TEST(TokenizerTest, validString_17) {
    std::string input = "ls -a; pwd;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
}

TEST(TokenizerTest, validString_18) {
    std::string input = "cat -n example.txt";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, validString_19) {
    std::string input = "exit; test";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
}

TEST(TokenizerTest, validString_20) {
    std::string input = "git status";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}



TEST(TokenizerTest, invalidString_1) {
    std::string input = "ls echo mkdir exit pwd ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, invalidString_2) {
    std::string input = "||";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, invalidString_3) {
    std::string input = "&&";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, invalidString_4) {
    std::string input = ";";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(0, tokens.size());
}

TEST(TokenizerTest, invalidString_5) {
    std::string input = "|| ls; echo hi";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(4, tokens.size());
}

TEST(TokenizerTest, invalidString_6) {
    std::string input = "&& foijfoew eeeee dd   ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(2, tokens.size());
}

TEST(TokenizerTest, invalidString_7) {
    std::string input = ";;;;;;;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(6, tokens.size());
}

TEST(TokenizerTest, invalidString_8) {
    std::string input = "mkdir echo";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}

TEST(TokenizerTest, invalidString_9) {
    std::string input = "&&||;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(2, tokens.size());
}

TEST(TokenizerTest, invalidString_10) {
    std::string input = "";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(0, tokens.size());
}

TEST(TokenizerTest, invalidString_11) {
    std::string input = "     ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(0, tokens.size());
}

TEST(TokenizerTest, invalidString_12) {
    std::string input = " ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(0, tokens.size());
}

TEST(TokenizerTest, invalidString_13) {
    std::string input = "                               e ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
}


#endif

