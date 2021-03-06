#include "../header/Tokenizer.h"

std::vector<Token*> Tokenizer::makeTokens(std::string s) {
    std::vector<Token*> v;
    std::string command;
    removeComment(s);
    bool commentFlag;

    if (s == "\n") {    
        return v;
    }

    for (unsigned i = 0; i < s.size(); i++) {

        if ( s.at(i) == '"' ) {
            commentFlag = true;
            i++;
            while (s.at(i) != '"') {
                command += s.at(i++);
            }
            continue;
        }
        else if (s.at(i) == '[') {
            std::string arg;
            i++;
            while (s.at(i) != ']') {
                arg += s.at(i++);
            }
            command = command + "test" + " " + arg;
            continue;
        }
        //found connector (&& or ||) 
        else if (  (i + 1 < s.size()) && isAConnector( s.substr(i, 2) ) ) {

            if ( !command.empty() && !isAllWhitespace(command) )  {
                v.push_back( new CommandToken(command) );
            }

            v.push_back( new ConnectorToken( s.substr(i, 2) ) );

            command.clear(); //command already transformed into token, so clear the string
            i++; //increment one more time bc connector 2 characters ==> read an extra char
            commentFlag = false;

        }
        //Found IO >>
        else if ( i + 1 < s.size() && s.substr(i, 2) == ">>" ) {
            
            if ( !command.empty() && !isAllWhitespace(command) )  {
                v.push_back( new CommandToken(command) );
            }

            v.push_back( new IOToken( s.substr(i, 2) ) );

            command.clear(); //command already transformed into token, so clear the string
            i++; //increment one more time bc connector 2 characters ==> read an extra char
            commentFlag = false;
        }
        //Found IO '>'  '<' '|' 
        else if ( s.at(i) == '>' || s.at(i) == '<' || s.at(i) == '|') {

            if ( !command.empty() && !isAllWhitespace(command) )  {
                v.push_back( new CommandToken(command) );
            }
            v.push_back( new IOToken( std::string(1, s.at(i)) ) );

            command.clear();
            commentFlag = false;
        }

        //found semicolon or parentheses 
        else if ( s.at(i) == ';' || s.at(i) == ')' || s.at(i) == '(') {
            if ( !command.empty() && !isAllWhitespace(command) )  {
                v.push_back( new CommandToken(command) );
            }

            v.push_back( new ConnectorToken( std::string(1, s.at(i)) ) );

            command.clear();
            commentFlag = false;
        }
        //store characters read so far
        else {
            command += s.at(i);

        }
    }

    //In case string doesn't end with ';' 

    if (!command.empty() && !isAllWhitespace(command) ) {
        v.push_back( new CommandToken(command) );
    }
    if (!v.empty() && v.back()->toString() == ";") {
        v.pop_back();
    }

    return v;
}

bool Tokenizer::isAllWhitespace(const std::string& s) {
    int counter = 0;
    for (unsigned i = 0; i < s.size(); i++) {
        if (s.at(i) == ' ') {
            counter++;
        }
    }
    if (counter == s.size()) return true;
    return false;
}

bool Tokenizer::isAConnector(const std::string& connector) {
    if (connector == "&&" || connector == "||") {
        return true;
    }
    return false;
}


void Tokenizer::removeComment(std::string& s) {
    //numQuotationsSofar even -> is a comment
    //numQuotationsSofar odd -> is part of argument string
    int numQuotationsSoFar = 0;
    int hashLocation = -1;

    for (unsigned i = 0; i < s.size(); i++) {
        if (s.at(i) == '"') {
            numQuotationsSoFar++;
        }
        else if (s.at(i) == '#' && numQuotationsSoFar % 2 == 0) {
            hashLocation = i;
            break;
        }
    }

    if (hashLocation != -1) {
        s = s.substr(0, hashLocation);
    }
}

bool Tokenizer::has_IO_operator(const std::string& s) {
    for (unsigned i = 0; i < s.size(); i++) {
        if (s.at(i) == '<' || s.at(i) == '>') {
            return true;
        }
    }
    return false;
}

bool Tokenizer::has_pipe(const std::string& s) {
    for (unsigned i = 0; i < s.size(); i++) {
        if (s.at(i) == '|') {
            return true;
        }
    }
    return false;
}