// Random generation of the calculator grammar using Non-Deterministic Push-Down Automata (NDPDA)
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

// NDPDA Functions
std::string start(int depth, int max_depth);
std::string expression(int depth, int max_depth);
std::string number(int depth, int max_depth);


int main(int argc, char **argv) {
  int max_depth = 10;

  if(argc > 1) {
    max_depth = std::stoi(argv[1]);
  }
  
  // generate our string
  srand(time(NULL));
  std::cout << start(0, max_depth) << std::endl;
}

// < Start >      ::= < Expression >
std::string start(int depth, int max_depth)
{
  return expression(depth+1, max_depth);
}

// < Expression > ::= < Expression > "+" < Expression >
//                   | < Expression > "-" < Expression >
//                   | < Expression > "*" < Expression >
//                   | < Expression > "/" < Expression >
//                   | < Number >
std::string expression(int depth, int max_depth)
{
  int rule = rand() % 5;

  if(depth >= max_depth) {
    rule = 4;
  }
  
  switch(rule) {
    case 0:
      return expression(depth+1, max_depth) + "+" + expression(depth+1, max_depth);
    
    case 1: 
      return expression(depth+1, max_depth) + "-" + expression(depth+1, max_depth);

    case 2:
      return expression(depth+1, max_depth) + "*" + expression(depth+1, max_depth);

    case 3:
      return expression(depth+1, max_depth) + "/" + expression(depth+1, max_depth);

    case 4:
      return number(depth+1, max_depth);
  }
  
  return "";
}

// [0..9]+
std::string number(int depth, int max_depth)
{
  std::string result = "";

  do {
    result += std::to_string(rand() %10);
  } while(rand() % 2 == 0);
  
  return result;
}