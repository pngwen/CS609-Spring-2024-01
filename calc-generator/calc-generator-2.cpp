// Random generation of the calculator grammar using Non-Deterministic Push-Down Automata (NDPDA)
#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

// NDPDA Functions
std::string start();
std::string expression();
std::string number();
std::string digit();


int main() {
  // generate our string
  srand(time(NULL));
  while(true) {
  std::cout << number() << std::endl;
  }
}

// < Start >      ::= < Expression >
std::string start()
{
  return expression();
}

// < Expression > ::= < Expression > "+" < Expression >
//                   | < Expression > "-" < Expression >
//                   | < Expression > "*" < Expression >
//                   | < Expression > "/" < Expression >
//                   | < Number >
std::string expression()
{
  int rule = rand() % 5;
  switch(rule) {
    case 0:
      return expression() + "+" + expression();
    
    case 1: 
      return expression() + "-" + expression();

    case 2:
      return expression() + "*" + expression();

    case 3:
      return expression() + "/" + expression();

    case 4:
      return number();
  }
  
  return "";
}

//< Number >     ::= < Number > < Digit >
//                   | < Digit >
std::string number()
{
  int rule = rand() % 2;

  switch(rule) {
    case 0:
      return number() + digit();
    case 1:
      return digit();
  }
  
  return "";
}
                     
               
//< Digit >      ::= "0" | "1" | "2" | "3" | ... | "9"
std::string digit()
{
  int rule = rand() % 10;
  return std::to_string(rule);
}