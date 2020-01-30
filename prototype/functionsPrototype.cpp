#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
        std::cout << "Prototype function test for fork(), waitpid(), and execvp." << std::endl;
        int* status;
        char* command = "ls";
        char* argv[2];
        argv[0] = "ls";
        argv[1] = NULL;

        pid_t process = fork();
        waitpid(0, status, 0);
        if(process == 0){
                std::cout << "Child" << std::endl;
                execvp(command, argv);
        }
        else {
                std::cout << "Parent. End of program." << std::endl;
        }
}
