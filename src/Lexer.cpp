#include <cctype>
#include "Token.hpp"
#include "Lexer.hpp"

void
Lexer::setInputStream(std::istream* is) {
	inputStream = is;
}

char
Lexer::getNext() {
	return inputStream->get();
}

bool
Lexer::Lex() {
	std::string buffer;
  auto currentChar = getNext();
	if ( isalpha(currentChar) ) {
		do {
			buffer.push_back(currentChar);
			currentChar = getNext();
		}
		while  (not isspace(currentChar)
				 && not ispunct(currentChar)
				 && not iscntrl(currentChar));

		/* Check whether the words in buffer is keyword*/
		for (auto keyword : g_reservedKeywords) {
			if (buffer == keyword) {
				g_tokens.push_back( new Keyword(buffer) );
				return true;
			}
		}

		/* If we reach here, it is an identifier. */
		g_tokens.push_back( new Identifier(buffer) );
		return true;
	}

	else if (currentChar == '(') {

	}
	return false;
}
