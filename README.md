# CS 100 Programming Project

## Project Information
* Winter 2020
* Steven Truong, SID: 862115368
* Terry Jung   , SID: 862073628

## Introduction
This program is a command line interface that is able to take in commands in the the following format:
`$ executable [argumentList] [connector] [executable] ...`. There are only two executables that will be recognized by the program: `mkdir` and `ls`. Moreover, `&&`, `||`, and `;` are the only valid connectors that will be recognized. Inputs that are fed to the command line interface are first parsed into two separate categories. The first category includes the parts that make up a command (the executable and its arguments). It will be represented by a class called `CommandToken`.  The other category describes the connectors, and it will be defined by a class called `ConnectorToken`. These tokens will be grouped together by a `Tokenizer` class and then executed by an `Executor` class that takes in a vector of tokens.

## Diagram
![GitHub Logo](/images/OMT.png)

## Classes
* `Token`, `CommandToken`, `ConnectorToken`, `Tokenizer`
> The Token classes will be responsible for parsing input commands from the user. `Token` is a base class that is a parent of `CommandToken` and `ConnectorToken`. It allows for the grouping of ConnectorTokens and CommandTokens pointers under a single vector. The `CommandToken` class holds two strings for the executable and arguments of a command, and `ConnectorToken` holds a single string that represents the connector. Instantiating and joining these tokens together through `Tokenizer` facilitates the execution of the input commands.
* `Executor`
> The `Executor` class will be responsible for executing the commands given by the user. The class takes in a vector of tokens created by `Tokenizer` and performs different functions depending on what type of token is currently being scrutinized. For instance, when a `CommandToken` is being read, the executable and arguments will first be checked for any syntax errors. If there is no error, then the command will be executed and return a value to signal a successful execution. On the other hand, if there was a problem then an appropriate value is returned that signals a failure. After the `Executor` class has performed all the tasks needed on the current token, it will move to the next token on the list and will decide what to do based on the given connector and return value from the previous token.

## Prototypes/Research
After watching the suggested youtube videos for forking and reading up on implementation for fork(), waitpid(), and execvp(), a prototype function was created to test how these functions work with together. This prototype implemented fork(), then used waitpid() to allow the child to go first. The child then performed execvp(). Once the child was finished, the parent concluded the program with an ending message. The findings of this prototype function resulted in proper implementation and understanding of the functions. This prototype for testing the functions will be the basis of the actual assignment with fork and wait carrying out order of tasks and execvp executing the commands. A parser prototype was also created to divide user input into different vectors of command, argument, and connector. This parser prototype will be the general structure of the actual parser which will be bug free and complete. 
## Development and Testing Roadmap
* Create main shell file
* Create classes
* Create helper functions for fork, wait, and execvp
* Implement helper functions onto main shell file
* Make test cases for the shell file
* Create parser(tokenizer)
* Make test cases for tokenizer
* Implement parser to the shell
* Debug
