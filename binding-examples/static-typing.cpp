#include <iostream>

int main() {
  int x;
  double y;

  // try to do integer to double coercion (Type widening)
  x = 1;
  y = x;
  std::cout << y << std::endl;

  // try to do double to integer coercion (Type narrowing)
  //   - we can do this coercion
  //   - truncates the value
  y = 4.999999;
  x = y;
  std::cout << x << std::endl;
}