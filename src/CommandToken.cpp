#include "../header/CommandToken.h"


CommandToken::CommandToken(const std::string& command_str) {
    command = parse_command(command_str);
}

Command CommandToken::parse_command(const std::string& command_str) {
    std::string executable;
    std::string arguments;
    std::string parsed_str;
    int location_of_whitespace_char = -1;


    if ( command_str.empty() || contains_only_whitespace(command_str) ) {
        return Command();
    }

    //Remove leading whitespace from front and back
    parsed_str = remove_extra_whitespace(command_str);


    //Look for first whitespace char in string
    for (unsigned i = 0; i < parsed_str.size(); i++) {
	    if ( parsed_str.at(i) == ' ') {
	        location_of_whitespace_char = i;
	        break;
	    }
    }
	//no whitespace char ==> no args
		if (location_of_whitespace_char == -1) {
			 executable = parsed_str;
		}
		else {
			//break command into executable and argument
			executable = remove_extra_whitespace( parsed_str.substr(0, location_of_whitespace_char) );
			arguments = remove_extra_whitespace( parsed_str.substr(location_of_whitespace_char + 1, parsed_str.size() - location_of_whitespace_char + 1) );
		}
	return Command(executable, arguments);
}


std::string CommandToken::remove_extra_whitespace(const std::string& s) {
    std::string str;
    unsigned current_index = 0;
    unsigned last_index = s.size() - 1;

    if (s.empty()) {
        return "";
    }

    //Remove whitespaces from the left
    for (current_index = 0; current_index < s.size(); current_index++) {
        if (s.at(current_index) != ' ' ) {
            break;
        }
    }
    //Remove whitespaces from the right
    for (last_index = s.size() - 1; last_index >= 0; last_index--) {
        if (s.at(last_index) != ' ' ) {
            break;
        }
    }

    return s.substr(current_index, last_index - current_index + 1);
}


bool CommandToken::contains_only_whitespace(const std::string& s) {

    int number_of_whitespace_chars = 0;

    for (unsigned i = 0; i < s.size(); i++) {
        if (s.at(i) == ' ') {
            number_of_whitespace_chars++;
        }
    }
    return (number_of_whitespace_chars == s.size()) ? true : false;
}

std::string CommandToken::toString() {
    return command.executable + " " + command.arguments;
}

bool CommandToken::execute() {
    std::vector<std::string> arguments_vec = parse_arguments(command.arguments);
    int c_string_size = arguments_vec.size() + 2;  // +1 for exec string, +1 for null terminated string
    int index = 0;
    char* command_str[c_string_size];

    command_str[index] = const_cast<char*>( command.executable.c_str() );
    for (const std::string& str : arguments_vec) {
        command_str[++index] = const_cast<char*>( str.c_str() );
    }
    command_str[index + 1] = NULL;
    
    char exitS[] = "exit";
    if(strcmp(command_str[0], exitS) == 0){
        exit(0);
    }

    char testS[] = "test";
    if (strcmp(command_str[0], testS) == 0) {
        return executeTest(arguments_vec);
    }


    int status;
    pid_t process = fork();

    if (process == 0) {
        if (execvp(command_str[0], command_str) < 0) {
            perror(command_str[0]);
            exit(3);
        }

    }
    else if (process < 0) {
        perror("fork() failed");
    }
    else {
        waitpid(0, &status, 0);

        if ( WIFEXITED(status) ) {
           int exitCode = WEXITSTATUS(status);
           if (exitCode == 3) {
              return 0;
           }
           else {
              return 1;
           }
        }


   }
}

std::vector<std::string> CommandToken::parse_arguments(const std::string& s) {
    std::vector<std::string> arguments_vec;
    std::string currentStr;

    for (unsigned i = 0; i < s.size(); i++) {
        if (s.at(i) != ' ') {
            currentStr += s.at(i);
        }
        else {
            arguments_vec.push_back(currentStr);
            currentStr.clear();
        }
    }

    if (!currentStr.empty()) {
        arguments_vec.push_back(currentStr);
    }

    return arguments_vec;
}

bool CommandToken::executeTest(const std::vector<std::string> arguments_vec) {
    struct stat buf;
    std::string flag;
    std::string path;

    if ( arguments_vec.size() == 2 ) {
        flag = arguments_vec.at(0);
        path = arguments_vec.at(1);
        stat(arguments_vec.at(1).c_str() , &buf);
    }
    else if ( arguments_vec.size() == 1 ) {
        path = arguments_vec.at(0);
        stat(arguments_vec.at(0).c_str(), &buf);
    }

    //Check if valid flag
    if ( arguments_vec.size() >= 2 && !flagIsValid(flag) ) {
        std::cout << "Invalid Arguments" << std::endl;
        return 0;
    }


    if (cmpFlagAndPath(flag, path, &buf) ) {
        std::cout << "(True)" << std::endl;
        return 1;
    }
    else {
        std::cout << "(False)" << std::endl;
        return 0;
    }
}

bool CommandToken::cmpFlagAndPath(const std::string& flag, const std::string& path, struct stat* buf) {
    bool isAFile = S_ISREG(buf->st_mode);
    bool isADir =  S_ISDIR(buf->st_mode);

    if ( flag == "-f" && isAFile ) {
        return true;
    }
    else if ( flag == "-d" && isADir ) {
        return true;
    }
    else if ( ( flag.empty() || flag == "-e") && (isADir || isAFile) ) {
        return true;
    }

    return false;
}

bool CommandToken::flagIsValid(const std::string& s) {

    if ( s == "-f" || s == "-d" || s== "-e" ) {
        return true;
    }
    return false;
}

std::string CommandToken::token_name() {
    return "CommandToken";
}