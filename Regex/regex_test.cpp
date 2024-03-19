#include "character_node.h"
#include "group_node.h"
#include "inverse_node.h"
#include "one_node.h"
#include "optional_node.h"
#include "or_node.h"
#include "range_node.h"
#include "zero_node.h"
#include <iostream>
#include <string>

// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input,
                 RegexNode *regex);

// Construct regular expression (ab)*ac
RegexNode *construct_regex1();

// Construct regular expression (ab)+ac
RegexNode *construct_regex2();

// Construct regular expression (a|(aa))b
RegexNode *construct_regex3();

// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode *construct_regex4();

// Construct the regular expression [a-zA-Z]+
RegexNode *construct_regex5();

// Construct the regular expression "[^"]*"
RegexNode *construct_regex6();

int main() {
  std::string input_str;
  RegexNode *regex1 = construct_regex1();
  RegexNode *regex2 = construct_regex2();
  RegexNode *regex3 = construct_regex3();
  RegexNode *regex4 = construct_regex4();
  RegexNode *regex5 = construct_regex5();
  RegexNode *regex6 = construct_regex6();

  while (std::cin) {
    // get the user input
    std::cout << "Input> ";
    getline(std::cin, input_str);
    if (!std::cin)
      continue;

    // print the result
    print_match("(ab)*ac", input_str, regex1);
    print_match("(ab)+ac", input_str, regex2);
    print_match("(a|(aa))b", input_str, regex3);
    print_match("[0-9]+(\\.[0-9]+)?", input_str, regex4);
    print_match("[a-zA-Z]+", input_str, regex5);
    print_match("\"[^\"]*\"", input_str, regex6);
  }

  // cleanup
  delete regex1;
  delete regex2;
  delete regex3;
  delete regex4;
  delete regex5;
  delete regex6;
}

// Print whether the whole string matches the regex
void print_match(const std::string &label, const std::string &input,
                 RegexNode *regex) {
  size_t pos = 0;

  std::cout << label << ": ";
  if (regex->match(input, pos) && pos == input.length()) {
    std::cout << "Match!" << std::endl;
  } else {
    std::cout << "No match." << std::endl;
  }
}

// Construct regular expression (ab)*ac
RegexNode *construct_regex1() {
  // create the result
  GroupNode *regex = new GroupNode();

  // create ab node
  GroupNode *ab = new GroupNode();
  ab->add_node(new CharacterNode('a'));
  ab->add_node(new CharacterNode('b'));

  // create the star quantifier
  ZeroNode *star = new ZeroNode(ab);
  regex->add_node(star);

  // set up the main expression
  regex->add_node(new CharacterNode('a'));
  regex->add_node(new CharacterNode('c'));
  return regex;
}

// Construct regular expression (ab)+ac
RegexNode *construct_regex2() {
  // author: Lokeswara Ravindra Rao Kolli<lkolli1s@semo.edu>
  // author: pavan
  //  create the result
  GroupNode *regex = new GroupNode();

  // YOUR CODE HERE
  GroupNode *ab = new GroupNode();
  ab->add_node(new CharacterNode('a'));
  ab->add_node(new CharacterNode('b'));
  OneNode *plus_ab = new OneNode(ab);

  regex->add_node(plus_ab);
  regex->add_node(new CharacterNode('a'));
  regex->add_node(new CharacterNode('c'));

  return regex;
}

// Construct regular expression (a|(aa))b
RegexNode *construct_regex3() {
  // create the result
  GroupNode *regex = new GroupNode();

  // Yashasri Boppana;Rakesh Vaddepally;Pallavi Mekala;Durgaprasad Tiyyagura; Jake Stinson

  // YOUR CODE HERE
  OrNode *inner_or = new OrNode();
  inner_or->add_node(new CharacterNode('a'));

  GroupNode *aa = new GroupNode();
  aa->add_node(new CharacterNode('a'));
  aa->add_node(new CharacterNode('a'));
  inner_or->add_node(aa);

  regex->add_node(inner_or);
  regex->add_node(new CharacterNode('b'));

  return regex;
}

// Construct the regular expression [0-9]+(\.[0-9]+)?
RegexNode *construct_regex4() {
  GroupNode *regex = new GroupNode();

  // YOUR CODE HERE
  // Author: sravani neerudu <sneerudu1s@semo.edu>
  // Author: madhu chandana musipatla <mmusipatla1s@semo.edu>
  // Author: sai sreeja yalla <syalla1s@semo.edu>

  // create nodes for [0-9]+
  GroupNode *digits = new GroupNode();
  digits->add_node(new RangeNode('0', '9')); // Matches a digit
  OneNode *one_or_more_digits =
      new OneNode(digits); // Matches one or more digits

  // create nodes for (\.[0-9]+)?
  GroupNode *decimal_part = new GroupNode();
  decimal_part->add_node(new CharacterNode('.')); // Matches a literal '.'
  GroupNode *decimal_digits = new GroupNode();
  decimal_digits->add_node(new RangeNode('0', '9')); // Matches a digit
  OneNode *one_or_more_decimal_digits = new OneNode(
      decimal_digits); // Matches one or more digits after the decimal point
  OptionalNode *optional_decimal_part =
      new OptionalNode(decimal_part); // Makes the decimal part optional

  // add nodes to regex
  regex->add_node(one_or_more_digits);
  regex->add_node(optional_decimal_part);

  return regex;
}

// Construct the regular expression [a-zA-Z]+
RegexNode *construct_regex5() {

  //Create the result regex node
  GroupNode *regex = new GroupNode();

  // YOUR CODE HERE
  // Author: Sainatha Reddy, Siripireddy
  // Author: Rohith Patel, Kanchukatla
  // Author: Naveen, Dondapati


  
  //Create the rangenode for the lowercase letters
  RangeNode *lowercase_range = new RangeNode('a', 'z');

  //Create the rangenode for the uppercase letters
  RangeNode *uppercase_range = new RangeNode('A', 'Z');

  //Create an OrNode to represent the alternation between the lowercase and uppercase letters
  OrNode *or_Node = new OrNode();
  or_Node->add_node(lowercase_range);
  or_Node->add_node(uppercase_range);

  //Create a OneNode to represent the one or more occurence of alternation
  OneNode *one_node = new OneNode(or_Node);

  //Add the one_node to the result regex node
  regex->add_node(one_node);
  
  return regex;
}

// Construct the regular expression "[^"]*"
//Author: Jake Stinson
RegexNode *construct_regex6() {
  GroupNode *regex = new GroupNode();

  // Match the opening quote
  regex->add_node(new CharacterNode('"'));

  // Match any character except the quote, zero or more times
  InverseNode *not_quote = new InverseNode(new CharacterNode('"'));
  ZeroNode *zero_or_more_not_quote = new ZeroNode(not_quote);
  regex->add_node(zero_or_more_not_quote);

  // Match the closing quote
  regex->add_node(new CharacterNode('"'));

  return regex;
}
