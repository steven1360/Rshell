#include "IOToken.h"

IOToken::IOToken(const std::string& s) {
	op = s; 
}

virtual bool IOToken::execute() {
		
	std::string r = right->getString();
	r.pop_back(); // backslash '\' always gets printed at the end for some reason

	//left side command, right side file. Writes output of command to file

	if (op == ">") {
		return execute(r, 1, O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	}
	//left side command, right side input from file
	else if (op == "<") {
		return execute(r, 0, O_CREAT | O_RDONLY, S_IRWXU | S_IRWXG);
	}
	// same thing as '>' accept you append instead of write
	else if (op == ">>") {
		return execute(r, 1, O_CREAT | O_APPEND | O_RDWR, S_IRWXU | S_IRWXG);
	}
}

bool IOToken::execute(const std::string& file, int fdToReplace, int flags, mode_t mode) {

	int save = dup(fdToReplace);
	int fd = open(const_cast<char*>(file.c_str()), flags, mode);

	if (fd < 0) {
		perror(const_cast<char*>(file.c_str()));
		return 0;
	}

	dup2(fd, fdToReplace);
	left->execute();
	dup2(save, fdToReplace);

	close(fd);
	return 1;
}

virtual std::string IOToken::toString() {
	return op;
}