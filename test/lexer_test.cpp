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
  Token *token = lexer.scan();
  ASSERT_EQ(token, &Type::INT);

  Word *w = dynamic_cast<Word*>(lexer.scan());
  ASSERT_EQ(w->get_lexeme(), "main");

  Token *t2 = lexer.scan();
  ASSERT_EQ(t2->str(), "(");

  Token *t3 = lexer.scan();
  ASSERT_EQ(t3->str(), ")");

  Token *t4 = lexer.scan();
  ASSERT_EQ(t4->str(), "{");

  Word *w2 = dynamic_cast<Word*>(lexer.scan());
  ASSERT_EQ(w2->str(), "return");

  Integer* i1 = dynamic_cast<Integer*>(lexer.scan());
  ASSERT_EQ(i1->str(), "0");

  Token *t5 = lexer.scan();
  ASSERT_EQ(t5->str(), ";");

  Token *t6 = lexer.scan();
  ASSERT_EQ(t6->str(), "}");
}
 
