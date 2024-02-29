#include <iostream>
#include <string>
#include "regex_node.h"
#include "group_node.h"
#include "wildcard_node.h"
#include "character_node.h"
#include "lexer.h"

// construct . regex
RegexNode *construct_single() {
  return new WildcardNode();
}

// construct \\.
RegexNode *construct_escaped() {
  GroupNode *regex = new GroupNode();
  regex->add_node(new CharacterNode('\\'));
  regex->add_node(new WildcardNode());
  return regex;
}


// construct .-. regex
RegexNode *construct_range() {
  GroupNode *regex = new GroupNode();
  regex->add_node(new WildcardNode());
  regex->add_node(new CharacterNode('-'));
  regex->add_node(new WildcardNode());
  return regex;
}


int main() {
  enum Token {
    INVALID = Lexer::INVALID,
    END_OF_INPUT = Lexer::END_OF_INPUT,
    CHARACTER = 1,
    RANGE = 2
  };
  Lexer lexer;

  // put in the tokens from most specific to least specific
  lexer.add_token(RANGE, construct_range());
  lexer.add_token(CHARACTER, construct_single());
  lexer.add_token(CHARACTER, construct_escaped());

  // keep trying input strings
  std::string input;
  while(std::cin >> input) {
    Lexer::Token t; 
    lexer.input(input);
    do { 
      t = lexer.next();
      std::cout << t.tok << "\t" << t.lexeme << std::endl;
    } while(t.tok != END_OF_INPUT);
  }
}

