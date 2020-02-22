#ifndef TESTCOMMAND_H
#define TESTCOMMAND_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

class Test(){

	public:
		Test(char* testType){
			char exists[] = "-e";
			char isFile[] = "-f";
			char isDir[] = "-d";
            		if(strcmp(testType, exists) == 0 || testType == NULL ){
				std::cout << "exists tests" << std::endl;
				//exists function
			}
			else if(strcmp(testType, isFile) == 0){
				 std::cout << "isFile tests" << std::endl;
			       //isFile function
			}
			else if(strcmp(testType, isDir) == 0){
                                 std::cout << "isDir tests" << std::endl;
			       //isDir function
                        }
		}
		
		bool exists(//some parameter){
			//if dir/file exists, returns true and prints "(True)", else prints "(False)"
		}
		bool isFile(){
		       //if file exists, returns true and prints "(True)", else prints "(False)"
		}
		bool isDir(){
		       //if directory exists, returns true and prints "(True)", else prints "(False)"
		}
};
