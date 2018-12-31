#ifndef LAXER_HPP_CJWPORVV
#define LAXER_HPP_CJWPORVV

#include <iostream>
#include <map>
#include "Token.hpp"


class Lexer {

public:
	Lexer() {
		inputStream = &std::cin;
		line = 1;
  	peek = ' ';

    reserve(new Word("if", token_if));
    reserve(new Word("else", token_else));
    reserve(new Word("while", token_while));
    reserve(new Word("do", token_do));
    reserve(new Word("break", token_break));
    reserve(&Word::TRUE);
    reserve(&Word::FALSE);

    reserve(&Type::INT);
    reserve(&Type::CHAR);
    reserve(&Type::BOOL);
	}

  auto set_input_stream(std::istream& inputStream) -> void {
    this->inputStream = &inputStream;
  }

	auto scan() -> Token*;

  auto add_word (std::string s, Word *w) -> void {
    words.insert(std::pair<std::string, Word*>(s, w));
  }

  auto reserve(Word* w) -> void {
      add_word(w->get_lexeme(), w);
  }

private:
	std::istream* inputStream;
	auto readchar() -> void;
	auto readchar_expect(char) -> bool;

	char peek;
	int line;

	std::map<std::string, Word*> words;
};

#endif /* end of include guard: LAXER_HPP_CJWPORVV */
