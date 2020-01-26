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




## Development and Testing Roadmap
