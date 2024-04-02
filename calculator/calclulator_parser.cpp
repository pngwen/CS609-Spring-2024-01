// File: calculator_parser.cpp
// Purpose: This file contains the implementation of the calculator parser.
#include "calculator_parser.h"
#include "add_node.h"
#include "sub_node.h"
#include "mul_node.h"
#include "div_node.h"
#include "pow_node.h"
#include <iostream>

static void error_message(const std::string &msg) {
  std::cerr << "Error: " << msg << std::endl;
}

ASTNode *CalculatorParser::parse(CalculatorLexer *_lexer) {
  // initialize the lexer
  this->_lexer = _lexer;
  next();

  return parse_expression();
}

void CalculatorParser::next() {
  _cur = _lexer->next();
}

//< Expression > ::= < Term > < Expression' >
ASTNode *CalculatorParser::parse_expression() {
  ASTNode *node = parse_term();
  return parse_expression2(node);
}

  //< Expression' >::= ADD < Term > < Expression' >
  //                   | SUB < Term > < Expression' >
  //                   | ""
  ASTNode *CalculatorParser::parse_expression2(ASTNode *left) {
    if(_cur.tok == CalculatorLexer::ADD) {
      next(); // succesful match
      AddNode *node = new AddNode();
      node->left(left);
      node->right(parse_term());
      return parse_expression2(node);
    } else if(_cur.tok == CalculatorLexer::SUB) {
      next(); // succesful match
      SubNode *node = new SubNode();
      node->left(left);
      node->right(parse_term2(node));
      return parse_expression2(node);
    }

    // empty string match
    return node;
  }
  
  
  //< Term >       ::= < Factor > < Term' > 
  ASTNode *CalculatorParser::parse_term() {
    return parse_term2(parse_factor());
  }

  //< Term' >      ::= MUL < Factor > < Term' >
  //                   | DIV < Factor > < Term' >
  //                   | ""
  ASTNode *CalculatorParser::parse_term2(ASTNode *left) {
    BinopNode *node = nullptr;

    if(_cur.tok == CalculatorLexer::MUL) {
      next(); // succesful match
      node = new MulNode();
    } else if(_cur.tok == CalculatorLexer::DIV) {
      next();
      node = new DivNode();
    }

    if(node) {
      node->left(left);
      node->right(parse_factor());
      return parse_factor2(node);
    } else {
      return left; 
    }
  }
  
  //< Factor >     ::= < Exponent > < Factor' >
  ASTNode *parse_factor();

  //< Factor' >    ::= POW < Exponent >
  //                   | ""
  ASTNode *parse_factor2(ASTNode *left);
  
  //< Exponent >   ::= INT 
  //                   | REAL
  //                   | LPAR < Expression > RPAR
  ASTNode *parse_exponent();