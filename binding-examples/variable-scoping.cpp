#include <iostream>

int x = 12;

void f() {
  int x;
  x = 5;
}

int main() {
  int x = 1;

  std::cout << x << std::endl;
  f();
  {
    int x = 2;
  }
  std::cout << x << std::endl;

  for(int y=4; y<10; y++) {
    
  }
  std::cout << y << std::endl;
}