// File: div_node.h
// Purpose: Definition of the ast division node.
#ifndef DIV_NODE_H
#define DIV_NODE_H
#include "binop_node.h"

class DivNode : public BinopNode {
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs) override;
};

#endif