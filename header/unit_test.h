#pragma once
#include "gtest/gtest.h"
#include "Tokenizer.h"

TEST(TokenizerTest, validString_1) {
    std::string input = "ls -a; echo test && mkdir hi || echo hello; git status; echo testing && echo watever";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(13, tokens.size());
    EXPECT_EQ("mkdir hi", tokens.at(4)->getString());
}

TEST(TokenizerTest, validString_2) {
    std::string input = "ls -a;    echo \"testing\" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("echo testing", tokens.at(2)->getString());
}

TEST(TokenizerTest, validString_3) {
    std::string input = "echo \"hello\" && ls;      echo        test;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(5, tokens.size());
    EXPECT_EQ("echo hello", tokens.at(0)->getString());
}


TEST(TokenizerTest, validString_4) {
    std::string input = "exit";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("exit ", tokens.at(0)->getString());
}

TEST(TokenizerTest, validString_5) {
    std::string input = "ls";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("ls ", tokens.at(0)->getString());
}

TEST(TokenizerTest, validString_6) {
    std::string input = "echo";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("echo ", tokens.at(0)->getString());
}

TEST(TokenizerTest, validString_7) {
    std::string input = "pwd";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("pwd ", tokens.at(0)->getString());
}

TEST(TokenizerTest, validString_8) {
    std::string input = "ls -a && ls";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("ls -a", tokens.at(0)->getString());
}

TEST(TokenizerTest, validString_9) {
    std::string input = "echo \"hello\" && echo no;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("&&", tokens.at(1)->getString());
}

TEST(TokenizerTest, validString_10) {
    std::string input = "mkdir newfolder;   echo heya";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("echo heya", tokens.at(2)->getString());
}

TEST(TokenizerTest, validString_11) {
    std::string input = "echo \"hello && goodbye\" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("echo hello && goodbye", tokens.at(0)->getString());
}

TEST(TokenizerTest, validString_12) {
    std::string input = "mkdir \"newfolder&&foldddddddddd\" && echo \"black# || blue \" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("echo black# || blue", tokens.at(2)->getString());
}

TEST(TokenizerTest, validString_13) {
    std::string input = "pwd && ls #-a";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("ls ", tokens.at(2)->getString());
}

TEST(TokenizerTest, validString_14) {
    std::string input = "  echo \" testing #123 \" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("echo testing #123", tokens.at(0)->getString());
}

TEST(TokenizerTest, validString_15) {
    std::string input = "ls; echo \"hi\" && mkdir \"folder\" # echo \"whatever\"      ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(5, tokens.size());
    EXPECT_EQ("mkdir folder", tokens.at(4)->getString());
}

TEST(TokenizerTest, validString_16) {
    std::string input = "ls; echo \"hi\" #&& mkdir \"folder\" # echo \"whatever\"      && pwd ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("echo hi", tokens.at(2)->getString());
}

TEST(TokenizerTest, validString_17) {
    std::string input = "ls -a; pwd;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("pwd ", tokens.at(2)->getString());
}

TEST(TokenizerTest, validString_18) {
    std::string input = "cat -n example.txt";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("cat -n example.txt", tokens.at(0)->getString());
}

TEST(TokenizerTest, validString_19) {
    std::string input = "exit; test";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ(";", tokens.at(1)->getString());
}

TEST(TokenizerTest, validString_20) {
    std::string input = "git status";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("git status", tokens.at(0)->getString());
}

TEST(TokenizerTest, validString_21) {
    std::string input = "#git status";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(0, tokens.size());
}


TEST(TokenizerTest, invalidString_1) {
    std::string input = "ls echo mkdir exit pwd ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("ls echo mkdir exit pwd", tokens.at(0)->getString());
}

TEST(TokenizerTest, invalidString_2) {
    std::string input = "||";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("||", tokens.at(0)->getString());
}

TEST(TokenizerTest, invalidString_3) {
    std::string input = "&&";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("&&", tokens.at(0)->getString());
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
    EXPECT_EQ("||", tokens.at(0)->getString());
    EXPECT_EQ(";", tokens.at(2)->getString());
}

TEST(TokenizerTest, invalidString_6) {
    std::string input = "&& foijfoew eeeee dd   ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(2, tokens.size());
    EXPECT_EQ("&&", tokens.at(0)->getString());
    EXPECT_EQ("foijfoew eeeee dd", tokens.at(1)->getString());
}

TEST(TokenizerTest, invalidString_7) {
    std::string input = ";;;;;;;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(6, tokens.size());
    EXPECT_EQ(";", tokens.at(3)->getString());

}

TEST(TokenizerTest, invalidString_8) {
    std::string input = "mkdir echo";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("mkdir echo", tokens.at(0)->getString());
}

TEST(TokenizerTest, invalidString_9) {
    std::string input = "&&||;";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(2, tokens.size());
    EXPECT_EQ("&&", tokens.at(0)->getString());
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
    EXPECT_EQ("e ", tokens.at(0)->getString());
}

TEST(TokenizerTest, invalidString_14) {
    std::string input = "\n";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(0, tokens.size());
}


TEST(TokenizerTest, Parentheses1) {
    std::string input = "echo A && (echo B || echo C)";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(7, tokens.size());
    EXPECT_EQ("(", tokens.at(2)->getString());
    EXPECT_EQ("echo C", tokens.at(5)->getString());
}


TEST(TokenizerTest, Parentheses2) {
    std::string input = "((echo A || (echo D)) &&  (echo B || echo C))";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(15, tokens.size());
    EXPECT_EQ("(", tokens.at(0)->getString());
    EXPECT_EQ("(", tokens.at(1)->getString());
    EXPECT_EQ("echo D", tokens.at(5)->getString());

}

TEST(TokenizerTest, Parentheses3) {
    std::string input = "( echo test )";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("echo test", tokens.at(1)->getString());
    EXPECT_EQ("(", tokens.at(0)->getString());
}

TEST(TokenizerTest, Parentheses4) {
    std::string input = "( echo test ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(2, tokens.size());
    EXPECT_EQ("echo test", tokens.at(1)->getString());
    EXPECT_EQ("(", tokens.at(0)->getString());
}

TEST(TokenizerTest, Parentheses5) {
    std::string input = " echo test )";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(2, tokens.size());
    EXPECT_EQ("echo test", tokens.at(0)->getString());
    EXPECT_EQ(")", tokens.at(1)->getString());
}

TEST(TokenizerTest, Parentheses6) {
    std::string input = " ( ( (  echo test )";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(5, tokens.size());
    EXPECT_EQ("echo test", tokens.at(3)->getString());
    EXPECT_EQ("(", tokens.at(2)->getString());
}

TEST(TokenizerTest, Parentheses7) {
    std::string input = " ) echo one && ) echo two ( (";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(7, tokens.size());
    EXPECT_EQ("echo one", tokens.at(1)->getString());
    EXPECT_EQ("&&", tokens.at(2)->getString());
}

TEST(TokenizerTest, Parentheses8) {
    std::string input = "(";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("(", tokens.at(0)->getString());
}

TEST(TokenizerTest, Parentheses9) {
    std::string input = ")";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ(")", tokens.at(0)->getString());
}

TEST(TokenizerTest, Parentheses10) {
    std::string input = "     )  ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ(")", tokens.at(0)->getString());
}

TEST(TokenizerTest, Parentheses11) {
    std::string input = "()()()()";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(8, tokens.size());
    EXPECT_EQ(")", tokens.at(3)->getString());
}

TEST(TokenizerTest, Parentheses12) {
    std::string input = "()()#()()";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(4, tokens.size());
    EXPECT_EQ(")", tokens.at(3)->getString());
}

TEST(TokenizerTest, Parentheses13) {
    std::string input = "echo \"(hello world)\" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("echo (hello world)", tokens.at(0)->getString());
}

TEST(TokenizerTest, Parentheses14) {
    std::string input = "(echo \"testing #thi(s is a comment()\" && echo one) && echo echo";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(7, tokens.size());
    EXPECT_EQ("echo testing #thi(s is a comment()", tokens.at(1)->getString());
    EXPECT_EQ(")", tokens.at(4)->getString());
}



TEST(TokenizerTest, usingTestCommand1) {
    std::string input = "test -e file.cpp && echo one";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("test -e file.cpp", tokens.at(0)->getString());
}


TEST(TokenizerTest, usingTestCommand2) {
    std::string input = "[-f file.cpp] && echo one";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("test -f file.cpp", tokens.at(0)->getString());
    EXPECT_EQ("&&", tokens.at(1)->getString());
    EXPECT_EQ("echo one", tokens.at(2)->getString());
}


TEST(TokenizerTest, usingTestCommand3) {
    std::string input = "echo \"I am not a test command but just a comment [-e somefile.cpp]\" ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(1, tokens.size());
    EXPECT_EQ("echo I am not a test command but just a comment [-e somefile.cpp]", tokens.at(0)->getString());
}

TEST(TokenizerTest, usingTestCommand4) {
    std::string input = " [-e file.h] && [ file.cpp ] ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("test -e file.h", tokens.at(0)->getString());
    EXPECT_EQ("test file.cpp", tokens.at(2)->getString());
}

TEST(TokenizerTest, usingTestCommand5) {
    std::string input = " echo \" echo:) :) [-e file.h] \" && [ file.cpp ] ";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("echo echo:) :) [-e file.h]", tokens.at(0)->getString());
}

TEST(TokenizerTest, usingIOToken1) {
    std::string input = "ls -la > output.txt";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("ls -la", tokens.at(0)->getString());
    EXPECT_EQ(">", tokens.at(1)->getString());
    EXPECT_EQ("output.txt ", tokens.at(2)->getString());
}

TEST(TokenizerTest, usingIOToken2) {
    std::string input = "echo \"david phung\" > output.txt";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("echo david phung", tokens.at(0)->getString());
    EXPECT_EQ(">", tokens.at(1)->getString());
    EXPECT_EQ("output.txt ", tokens.at(2)->getString());
}

TEST(TokenizerTest, usingIOToken3) {
    std::string input = "echo \"ls > file.txt\" > output.txt";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("echo ls > file.txt", tokens.at(0)->getString());
    EXPECT_EQ(">", tokens.at(1)->getString());
    EXPECT_EQ("output.txt ", tokens.at(2)->getString());
}

TEST(TokenizerTest, usingIOToken4) {
    std::string input = "ls -la | output.txt";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("ls -la", tokens.at(0)->getString());
    EXPECT_EQ("|", tokens.at(1)->getString());
    EXPECT_EQ("output.txt ", tokens.at(2)->getString());
}

TEST(TokenizerTest, usingIOToken5) {
    std::string input = "ls -la >> output.txt";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(3, tokens.size());
    EXPECT_EQ("ls -la", tokens.at(0)->getString());
    EXPECT_EQ(">>", tokens.at(1)->getString());
    EXPECT_EQ("output.txt ", tokens.at(2)->getString());
}


TEST(TokenizerTest, usingIOToken6) {
    std::string input = "ls -a; ls; cat < file.txt && echo test; cat > >";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(13, tokens.size());
    EXPECT_EQ("<", tokens.at(5)->getString());
    EXPECT_EQ(">", tokens.back()->getString());
}

TEST(TokenizerTest, usingIOToken7) {
    std::string input = "(ls -la > file.txt && (eco message > file.txt || (echo sup && echo lol > file.txt) ) ) && echo hi";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ(21, tokens.size());
    EXPECT_EQ(">", tokens.at(2)->getString());
    EXPECT_EQ("echo sup", tokens.at(11)->getString());
}

TEST(TokenizerTest, usingIOToken8) {
    std::string input = "cat < existingInputFile | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2";
    std::vector<Token*> tokens = Tokenizer::makeTokens(input);
    EXPECT_EQ("|", tokens.at(3)->getString());
    EXPECT_EQ("tr A-Z a-z", tokens.at(4)->getString());
    EXPECT_EQ("tee newOutputFile1", tokens.at(6)->getString());
    EXPECT_EQ(11, tokens.size());
}

