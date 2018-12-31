#include <cctype>
#include "Token.hpp"
#include "Lexer.hpp"



auto Lexer::readchar() -> void {
	peek = inputStream->get();
}

auto Lexer::readchar_expect(char expect) -> bool {
	readchar();
	if (peek == expect) {
    // since expect is the same as peek,
    // we can just reset peek here
		peek = ' ';
		return true;
	} else {
		return false;
	}
}

Token*
Lexer::scan() {
  for ( ; ; readchar()){
    // skeep spaces
		if (peek == ' ' || peek == '\t') continue;
		else if (peek == '\n') line++;
		else break;
	} 

	switch(peek) {
		case '&':
			if (readchar_expect('&')) return &Word::AND;
      else return new Token('&');
		case '|':
			if (readchar_expect('|')) return &Word::OR;
      else return new Token('|');
		case '=':
			if (readchar_expect('=')) return &Word::EQ;
      else return new Token('=');
		case '!':
			if (readchar_expect('=')) return &Word::NE;
      else return new Token('!');
		case '<':
			if (readchar_expect('=')) return &Word::LE;
      else return new Token('<');
		case '>':
			if (readchar_expect('=')) return &Word::GE;
      else return new Token('>');
	}

  if (isdigit(peek)) {
    std::string buffer;
    do {
      buffer += peek;
      readchar();
    } while(isdigit(peek));
    return new Integer(stoi(buffer));
  } 

	if (isalpha(peek)) {
	  std::string buffer;
		do {
			buffer.push_back(peek);
			readchar();
		} while (isalnum(peek));

		/* Check whether the read word already in words*/
		auto it = words.find(buffer);
		if (it == words.end()) {
			auto w = new Word(buffer, token_identifier);
			words.insert( std::pair<std::string, Word*>(buffer, w) );
			return w;
		} else {
			return it->second;
		}
	}

  Token *tok = new Token(peek);
  peek = ' ';
  return tok;
}
