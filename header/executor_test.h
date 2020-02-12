#ifndef EXECUTOR_TEST_H
#define EXECUTOR_TEST_H
#include "gtest/gtest.h"
#include "Executor.h"

TEST(ExecutorTest,echo) {
	std::vector<Token*> tokens;
	std::string lsString = "echo hi";
	tokens.at(0) = Token(lsString);
	Executor(tokens);
	execute();
	EXPECT_EQ("hi");	
}

TEST(ExecutorTest,echoWithConnector) {
	 std::vector<Token*> tokens;
        std::string lsString = "echo hi && echo steven";
        tokens.at(0) = Token(lsString);
        Executor(tokens);
        execute();
        EXPECT_EQ("hi steven")
#endif
