#include "Token.hpp"

auto Word::AND = Word("&&", token_and);
auto Word::OR = Word("||", token_or);
auto Word::EQ = Word("==", token_eq);
auto Word::NE = Word("!=", token_ne);
auto Word::LE = Word("<=", token_le);
auto Word::GE = Word(">=", token_ge);
auto Word::MINUS = Word("minus", token_minus);
auto Word::TRUE = Word("true", token_true);
auto Word::FALSE = Word("false", token_false);
auto Word::TEMP = Word("t", token_temp);

auto Type::INT = Type("int", token_basic, 4);
auto Type::CHAR = Type("char", token_basic, 1);
auto Type::BOOL = Type("bool", token_basic, 1);
