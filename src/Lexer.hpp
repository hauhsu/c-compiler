#ifndef LAXER_HPP_CJWPORVV
#define LAXER_HPP_CJWPORVV

#include <iostream>


class Lexer {

public:
	Lexer(){;}
	Lexer(std::istream* is){ setInputStream(is); }
	bool Lex();
	void setInputStream(std::istream*);

private:
	std::istream* inputStream;
	char getNext();

};

#endif /* end of include guard: LAXER_HPP_CJWPORVV */
