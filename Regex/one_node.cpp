// File: one_node.cpp
// Purpose: The one node matches the one or more quantifier.
// Author: Robert Lowe
#include "one_node.h"
#include <iostream>
#include <string>

// construct a zero node with the node to repeat
OneNode::OneNode(RegexNode *_node) { this->_node = _node; }

// destruct a zero node
OneNode::~OneNode() { delete _node; }

// Attempt to match the string beginning at the given position.
bool OneNode::match(const std::string &str, size_t &pos) {

  size_t count = pos;
  while (_node->match(str, pos) && pos < str.length()) {
    count++;
  }
  if (count >= 1)
    return true;
  else
    return false;
}