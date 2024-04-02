// File: add_node.h
// Purpose: Definition of the ast multiplication node.
#ifndef MUL_NODE_H
#define MUL_NODE_H
#include "binop_node.h"

class MulNode : public BinopNode {
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs) override;
};

#endif