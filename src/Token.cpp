#include "Token.hpp"
#include <vector>

std::vector<TokenBase*> g_tokens;

std::array<std::string, 2> g_reservedKeywords {{
	"void", 
	"return",
}};
