#include <iostream>
#include <fstream>
#include "Lexer.hpp"
#include "Token.hpp"
#include "gtest/gtest.h"

class LexerTest: public ::testing::Test {
protected:
  void SetUp() override {

  }

  Lexer lexer;
};

TEST_F (LexerTest, readchar) { 
  std::ifstream tfile("test.c");
  lexer.set_input_stream(tfile);
  auto token = lexer.scan();
  ASSERT_EQ(token, &Type::INT) << "Read " << token->str() << "\n";

  Word *w = dynamic_cast<Word*>(lexer.scan());
  ASSERT_EQ(w->get_lexeme(), "main") << "Read " << w->str() << "\n";

  Token *t2 = lexer.scan();
  //ASSERT_EQ(t2->str(), "(") << "Read " << t2->str() << "\n";

  Token *t3 = lexer.scan();
  ASSERT_EQ(t3->str(), ")") << "Read " << t3->str() << "\n";
}
 
