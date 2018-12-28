#ifndef LAXER_HPP_CJWPORVV
#define LAXER_HPP_CJWPORVV

#include <iostream>
#include <map>
#include "Token.hpp"


class Lexer {

public:
	Lexer(){
		inputStream = &std::cin;
		line = 1;
  	peek = ' ';
	}
	Lexer(std::istream* is){ inputStream = is; }

	Word scan();

	void addWord(std::string s, Word w);

private:
	std::istream* inputStream;
	void readchar();
	bool readchar(char);
	char peek;
	int line;

	std::map<std::string, Word> words;
};

#endif /* end of include guard: LAXER_HPP_CJWPORVV */
