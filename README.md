# CS 100 Programming Project

## Project Information
* Winter 2020
* Steven Truong, SID: 862115368
* Terry Jung   , SID: 862073628

## Introduction
This program is a command line interface that is able to take in commands in the the following format:
`$ executable [argumentList] [connector] [executable] ...`. Inputs that are fed to the command line interface are first broken down into  tokens which inherit from a `Token` base class: `ExecToken`, `ArgToken`, `BadToken` and `ConnectorToken`. This is done by a single public method in the `Tokenizer` class, and it returns these tokens inside a vector. Then the `Executor` class' public method takes in a vector of these tokens and uses syscalls to execute the commands.


## Diagram
![GitHub Logo](/images/omt.png)

## Classes
* `Token`, `CommandToken`, `ConnectorToken`, `Tokenizer`
> The `Token` class contains several public virtual functions that report information about the type of a token and its value as a string. In addition, it has a pure virtual function that will be implemented by child tokens to execute commands. In order to use the composite pattern, this class also contains public functions to set the left child and right child of a token. These tokens are created inside the `Tokenizer` class, and then it is passed to the `Executor`. The `CommandToken` consists of a string for holding the executable name and another string for its arguments. The `ConnectorToken` has one string to hold the value for the connector. 

* `Executor`
> The `Executor` class will be responsible for executing the commands given by the user. The class takes in a vector of tokens created by `Tokenizer` and transforms it into postfix notation. Next, the postfixed vector is used to create an expression tree. From the root of the tree, the execute() function is called and the commands are executed in the correct order.


## Prototypes/Research
After watching the suggested youtube videos for forking and reading up on implementation for fork(), waitpid(), and execvp(), a prototype function was created to test how these functions work with together. This prototype implemented fork(), then used waitpid() to allow the child to go first. The child then performed execvp(). Once the child was finished, the parent concluded the program with an ending message. The findings of this prototype function resulted in proper implementation and understanding of the functions. This prototype for testing the functions will be the basis of the actual assignment with fork and wait carrying out order of tasks and execvp executing the commands. A parser prototype was also created to divide user input into different vectors of command, argument, and connector. This parser prototype will be the general structure of the actual parser which will be bug free and complete. 
## Development and Testing Roadmap
* Create main shell file
* Implement Token classes
* Implement Executor and Tokenizer classes
* Create helper functions for fork, wait, execvp
* Refine parser prototype
* Create and perform unit tests
* Create and carry out integration tests
