#include <iostream>

int main() {
  int x=0;
count:
  std::cout << x << std::endl; 
  x++;
  if(x <= 10) goto count;
}