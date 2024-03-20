// File: inverse_node.cpp
// Purpose: The optional node quantifier
// Author: Robert Lowe
#include "inverse_node.h"

InverseNode::InverseNode(RegexNode* _node)
{
  this->_node = _node;  
}


// attempt to match the string at position pos
bool InverseNode::match(const std::string& str, size_t &pos) {
    size_t originalPos = pos;

    bool matchResult = _node->match(str, pos);

    
    if(matchResult) {
        pos = originalPos; // revert the position
        return false; // inverse logic
    }

    return true;
}
