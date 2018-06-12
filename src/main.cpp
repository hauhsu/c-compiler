#include "Lexer.hpp"
#include "Token.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
	std::ifstream inputFile("test.c");
	if (!inputFile) {
		std::cout << "Cannot open test.c" << std::endl;
		return 1;
	}
	auto lexer = Lexer(&inputFile);
	while (lexer.Lex()){
	}
	for (auto i : g_tokens) {
		std::cout << i->str() << std::endl;	
	}

	return 0;
}
