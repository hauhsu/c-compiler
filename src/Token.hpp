#ifndef TOKEN_HPP_IDA0LYU5
#define TOKEN_HPP_IDA0LYU5

#include <string>
#include <vector>
#include <array>

enum TokenType {
	t_Keyword,
	t_Identifier,
	t_Constant,
	t_StringLiteral,
	t_Punctuator,
};


class TokenBase {
public:
	TokenType getType() { return m_type; }
	virtual std::string str() = 0;

private:
	TokenType m_type;	
};

extern std::vector<TokenBase*> g_tokens;

class Keyword: public TokenBase
{
public:
	Keyword (std::string str) { m_val = str; }
	std::string str() { return m_val; }
	

private:
	std::string m_val;	
};

class Integer: public TokenBase
{
public:
	Integer (int num) { m_val = num; }
	std::string str() { return std::to_string(m_val); }
	

private:
	int m_val;	
};

class Identifier: public TokenBase
{
public:
	Identifier (std::string iden) { m_val = iden; }
	std::string str() { return m_val; }
	

private:
	std::string m_val;	

};

extern std::array<std::string, 2> g_reservedKeywords;


#endif /* end of include guard: TOKEN_HPP_IDA0LYU5 */

