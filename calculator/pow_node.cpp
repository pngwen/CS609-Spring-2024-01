// File: pow_node.cpp
// Purpose: Implementation of the exponent node.
#include <iostream>
#include <cmath>
#include "pow_node.h"
#include "calculator_lexer.h"

ASTResult PowNode::apply(const ASTResult &lhs, const ASTResult &rhs) {
  ASTResult result;

  // assume an integer type
  result.type = ASTResult::INT;

  /* Possible Evaluations
      INT, INT -> INT    .i ^ .i
      REAL, REAL -> REAL  .r ^ .r
      INT, REAL -> REAL   .i ^ .r
      REAL, INT -> REAL   .r ^ .i
   */
  if(lhs.type == ASTResult::INT && rhs.type == ASTResult::INT) {
    result.type = ASTResult::INT;
    result.value.i = (int) pow(lhs.value.i, rhs.value.i);
  } else if(lhs.type == ASTResult::REAL && rhs.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = pow(lhs.value.r, rhs.value.r);
  } else if(lhs.type == ASTResult::INT && rhs.type == ASTResult::REAL) {
    result.type = ASTResult::REAL;
    result.value.r = pow(lhs.value.i, rhs.value.r);
  } else if(lhs.type == ASTResult::REAL && rhs.type == ASTResult::INT) {
    result.type = ASTResult::REAL;
    result.value.r = pow(lhs.value.i, rhs.value.r);
  } else {
    std::cerr << "Error: Invalid types for exponent" << std::endl;
  }

  return result;
}