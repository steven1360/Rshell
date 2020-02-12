#include <iostream>
#include <sys/types.h>	
#include <sys/wait.h>	
#include <unistd.h>
#include "../header/Tokenizer.h"
#include <vector>

char* converter(Token word){
	char* convetedWord = word->val;
}
void executioner(std::string input){
	std::vector<Token*> listOfTokens = Tokenizer::makeTokens(input);					//parse user input
	pid _t pid;								
	int* status;
	char** filler;
	filler[0] = NULL;

	if(pid = fork() == 0){										//child process. run execvp()
		for(int i = 0; i < listOfTokens.size(); i++){
			if(listOfTokens.at(i)->id == ExecToken){					//if current token is an ExecToken
				if(i < listOfTokens.size() - 1){					
					if(listOfTokens.at(i + 1)->id == ArgToken){		//if next token is an ArgToken
						char* argument = converter(listOfTokens.at(i+1);
						execvp(listOfTokens.at(i), argument);			//execute command with argument
					}
					else{
						 execvp(listOfTokens.at(i), filler);                             //execute command itself
					}			
				}
				else{
					execvp(listOfTokens.at(i), filler);				//execute command itself
				}
				
			}
		}
	}
	
	else{									//parent process
		waitpid(0,status,0);						//wait for child process
	}
}
