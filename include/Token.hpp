#ifndef TOKEN_HPP_IDA0LYU5
#define TOKEN_HPP_IDA0LYU5

#include <string>
#include <vector>
#include <array>

enum Tag {
	// Start from 256 because we might return read char directly
	token_identifier = 256,
	token_integer,
	token_string,
	token_and, token_or,
	token_eq, token_ne, token_le, token_ge,
	token_minus,
	token_true, token_false,
	token_temp,

  token_if,
  token_else,
  token_while,
  token_do,
  token_break,

  token_basic,

	token_eof,
};


class Token {
public:
	Token(int tag) { this->tag = tag; }
	virtual std::string str() {
    auto c = static_cast<char>(tag);
    std::string s(1, c);
    return s;
  } 

private:
	 int tag;	
};


class Integer: public Token
{
public:
	Integer (int num): Token(token_integer) {
		val = num;
	}
	Integer (int tag, std::string num): Token(tag) {
		val = std::stoi(num);
	}

	auto str() -> std::string {
		return std::to_string(val);
	}
	

private:
	int val;	
};

class Word: public Token
{
public:
	Word (std::string iden, int tag): Token(tag) {
		lexeme = iden;
	}
	auto str() -> std::string { return lexeme; }
  auto get_lexeme() -> std::string { return lexeme; }

  static Word // special symbols
    AND, OR,
    EQ, NE, LE, GE,
    MINUS,
    TRUE, FALSE,
    TEMP; 
	
private:
	std::string lexeme;	
};


class Type: public Word
{

public:
  Type(std::string s, int tag, int width): Word(s, tag), width(width) {}
  auto get_width() -> int { return width; }

public:
  static Type INT, CHAR, BOOL, FLOAT;

private:
  int width;
};


#endif /* end of include guard: TOKEN_HPP_IDA0LYU5 */

