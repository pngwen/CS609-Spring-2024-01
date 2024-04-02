// File: add_node.h
// Purpose: Definition of the ast addition node.
#ifndef ADD_NODE_H
#define ADD_NODE_H
#include "binop_node.h"

class AddNode : public BinopNode {
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs) override;
};

#endif