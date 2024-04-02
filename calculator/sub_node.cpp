// File: sub_node.cpp
// Purpose: Implementation of the subtraction node.
#include <iostream>
#include "sub_node.h"
#include "calculator_lexer.h"

ASTResult SubNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  ASTResult result;

  // assume an integer type
  result.type = ASTResult::INT;

  /* Possible Evaluations
      INT, INT -> INT    .i - .i
      REAL, REAL -> REAL  .r - .r
      INT, REAL -> REAL   .i - .r
      REAL, INT -> REAL   .r - .i
   */
  if(lhs.type == ASTResult::INT && rhs.type == ASTResult::INT) {
    result.type = ASTResult::INT;
    result.value.i = lhs.value.i - rhs.value.i;
  } else if(lhs.type == ASTResult::REAL && rhs.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = lhs.value.r - rhs.value.r;
  } else if(lhs.type == ASTResult::INT && rhs.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = lhs.value.i - rhs.value.r;
  } else if(lhs.type == ASTResult::REAL && rhs.type == ASTResult::INT) {
    result.type = ASTResult::REAL;
    result.value.r = lhs.value.i - rhs.value.r;
  } else {
    std::cerr << "Error: Invalid types for subtraction." << std::endl;
  }

  return result;
}