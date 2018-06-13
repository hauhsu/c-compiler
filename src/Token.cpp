#include "Token.hpp"
#include <vector>

std::vector<TokenBase*> g_tokens;

std::array<std::string, 3> g_reservedKeywords {{
		"void", 
		"int",
		"return",
}};
