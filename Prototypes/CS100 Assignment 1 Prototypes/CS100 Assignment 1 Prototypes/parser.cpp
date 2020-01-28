#include <vector>
#include <iostream>
#include <string>
int main(){
        std::vector<std::string> cmdv;
        std::vector<std::string> argv;
        std::vector<std::string> conv;
        std::string cmd;
        std::string arg;
        std::string con;
        //commands
        std::string ls = "ls";
        std::string echo = "echo";
        std::string mkdir = "mkdir";
        //connectors
        std::string semicolon = ";";
        std::string doubleand = "&&";
        std::string  doubleor = "||";

        std::string  input = "";
        std::cout << "PARSER TEST" << std::endl;
        while(input != "exit"){
                std::cin >> input;
                if(input.back() == ';'){
                        input.pop_back();
                        conv.push_back(semicolon);
                }
                if(input == ls || input == echo || input == mkdir){
                        cmdv.push_back(input);
                }
                if(input == semicolon || input == doubleand || input == doubleor){
                        conv.push_back(input);
                }

                if(input != " " && input != ls && input != echo && input != mkdir && input != semicolon && input != doubleand && input != doubleor){
                        argv.push_back(input);
                }
        }
        std::cout << "Commands:" << std::endl;
        for(int i = 0; i < cmdv.size(); i++){
        std::cout << cmdv.at(i) << std::endl;
        }

        std::cout << "Arguments:" << std::endl;
        for(int j = 0; j < argv.size(); j++){
        std::cout << argv.at(j) << std::endl;
        }

        std::cout << "Connectors:" << std::endl;
        for(int k = 0; k < conv.size(); k++){
        std::cout << conv.at(k) << std::endl;
        }
}

