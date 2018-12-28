#include <cctype>
#include "Token.hpp"
#include "Lexer.hpp"



void
Lexer::readchar() {
	peek = inputStream->get();
}

bool
Lexer::readchar(char expected) {
	readchar();
	if (peek == expected) {
		peek = ' ';
		return true;
	} else {
		return false;
	}
}

void Lexer::addWord(std::string s, Word w) {
	words.insert(std::pair<std::string, Word>(s, w));
}


Word
Lexer::scan() {
	std::string buffer;
	do {
		if (peek == ' ' || peek == '\t') continue;
		else if (peek == '\n') line++;
		else break;
	} while (1);

	switch(peek) {
		case '&':
			if (readchar('&')) return;

	}
	if (isalpha(peek)) {
		do {
			buffer.push_back(peek);
			readchar();
		} while (isalnum(peek));

		/* Check whether the read word already in words*/
		auto it = words.find(buffer);
		if (it == words.end()) {
			auto w = Word(buffer, token_identifier);
			words.insert( std::pair<std::string, Word>(buffer, w) );
			return w;
		} else {
			return it->second;
		}
	}

}
