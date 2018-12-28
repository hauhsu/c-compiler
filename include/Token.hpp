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
	token_eof,
};


class Token {
public:
	Token(int tag) { this->tag = tag; }
	virtual std::string str() = 0;

private:
	 int tag;	
};

class Integer: public Token
{
public:
	Integer (int num): Token(token_integer) {
		m_val = num;
	}
	Integer (int tag, std::string num): Token(tag) {
		m_val = std::stoi(num);
	}

	std::string str() {
		return std::to_string(m_val);
	}
	

private:
	int m_val;	
};

class Word: public Token
{
public:
	Word (std::string iden, int tag): Token(tag) {
		m_val = iden;
	}
	std::string str() { return m_val; }
	
private:
	std::string m_val;	
};



#endif /* end of include guard: TOKEN_HPP_IDA0LYU5 */

