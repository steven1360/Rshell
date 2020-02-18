#include "Token.h"
#include "Executor.h"

class MergedToken : public Token {
	private:
		std::vector<Token*> tokens;
	public:
		MergedToken(std::vector<Token*>& v) {
            int firstParenthesis = -1;
            int lastParenthesis = -1;
            std::vector<Token*> subsetOfV;

            //Locate first parenthesis
            for (int i = 0; i < v.size(); i++) {
                if ( v.at(i)->getString() == "(") {
                    firstParenthesis = i;
                    break;
                }
                else {
                	tokens.push_back( v.at(i) );
                }
            }

            //Locate last parenthesis
            for (int i = v.size() - 1; i >= 0; i--) {
                if ( v.at(i)->getString() == ")") {
                    lastParenthesis = i;
                    break;
                }
            }

            //Fill subset with tokens from inside the parenthesis
            for (int i = firstParenthesis + 1; i < lastParenthesis; i++) {
                subsetOfV.push_back( v.at(i) );
            }

            if (firstParenthesis != -1 && lastParenthesis != -1) {
            	//Remove selected tokens inside parenthesis from original vector, including the parentheses themselves
            	v.erase( v.begin() + firstParenthesis, 	v.begin() + lastParenthesis + 1);


	            //Merge subset into a single Token
	            if (firstParenthesis != -1 && lastParenthesis != -1) {
		            Token* merged = new MergedToken(subsetOfV);
		            tokens.push_back(merged);
	            }
            }

            //push any tokens after the last parnthesis into tokens vector
            for (int i = lastParenthesis + 1; i < v.size(); i++) {
            	tokens.push_back( v.at(i) );
            }
		}

		virtual int execute() {
			Executor ex(tokens);
			ex.execute();
		}

		virtual std::string getString() {
			if (!tokens.empty()) {
				std::cout << tokens.at(0)->getString() << std::endl;
			}
			else {
				std::cout << "No String; tokens is empty" << std::endl;
			}
		}

		virtual ID getIdentity() {
			return ID::MERGED;
		}
};