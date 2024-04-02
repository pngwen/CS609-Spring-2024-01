// File: sub_node.h
// Purpose: Definition of the ast subtraction node.
#ifndef SUB_NODE_H
#define SUB_NODE_H
#include "binop_node.h"

class SubNode : public BinopNode {
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs) override;
};

#endif