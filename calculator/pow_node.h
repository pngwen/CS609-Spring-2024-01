// File: pow_node.h
// Purpose: Definition of the ast power node.
#ifndef POW_NODE_H
#define POW_NODE_H
#include "binop_node.h"

class PowNode : public BinopNode {
  virtual ASTResult apply(const ASTResult &lhs, const ASTResult &rhs) override;
};

#endif