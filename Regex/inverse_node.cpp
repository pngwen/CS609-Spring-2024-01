// File: inverse_node.cpp
// Purpose: The optional node quantifier
// Author: Robert Lowe
#include "inverse_node.h"

InverseNode::InverseNode(RegexNode* _node)
{
  this->_node = _node;  
}

// attempt to match the string at position pos
bool InverseNode::match(const std::string& str, size_t &pos)
{
  // Check if the position is within the bounds of the string
  if (pos >= str.length()) {
    return false; // Cannot match if position is out of bounds
  }

  // Try to match the inner node
  size_t original_pos = pos; // Store the original position
  if (_node->match(str, pos)) {
    // If the inner node matches, return false
    pos = original_pos; // Reset the position
    return false;
  } else {
    // If the inner node does not match, return true
    return true;
  }
}
