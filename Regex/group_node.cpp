// File: group_node.cpp
// Purpose: Match a group of RegexNodes.
// Author: Robert Lowe
// Author: Jake Stinson
#include "group_node.h"
#include <string>
#include <vector>

// delete all the nodes in the group
GroupNode::~GroupNode() {
  for (auto node : _nodes) {
    delete node;
  }
}

// Attempt to match the string beginning at the given position.
bool GroupNode::match(const std::string &str, size_t &pos) {
  size_t saved_pos = pos;
  for (auto node : _nodes) {
    if (node->match(str, pos)) {
      continue;
    } else {
      pos = saved_pos;
      return false;
    }
  }
  return true;
}

// Add a node to the group
void GroupNode::add_node(RegexNode *node) { this->_nodes.push_back(node); }