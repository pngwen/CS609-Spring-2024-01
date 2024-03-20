// File: zero_node.cpp
// Purpose: The zero node matches the zero or more quantifier.
// Author: Robert Lowe
//Kapil Kumar Reddy Cheemarla
//Yash Barot
//Mahesh Munna
#include "zero_node.h"
#include <string>

// construct a zero node with the node to repeat
ZeroNode::ZeroNode(RegexNode *_node) { this->_node = _node; }

// destruct a zero node
ZeroNode::~ZeroNode() { delete _node; }

// Attempt to match the string beginning at the given position.
bool ZeroNode::match(const std::string &str, size_t &pos) {

  // YOUR CODE HERE
  // Match node as many times as possible
  // return true if match is successful
  size_t initialPos = pos;
  while (_node->match(str, pos)) {
    if (pos == initialPos) {
      //to avoid infinite loop if the position doesn't change after a match.
  
      break;
    }
    //need to update initial position whenever a matched occur
    initialPos = pos; 
  }
  pos = initialPos; 
  return true; 
}