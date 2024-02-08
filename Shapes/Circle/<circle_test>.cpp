#include "Circle.h"
#include <iostream>
using namespace std;

int main() {
  Circle c(0, 0, 10);

  cout << "Radius: " << c.getRadius() << endl;

  c.setCenter(10, 10);
  cout << "Center: (" << c.getXCenter() 
       << ", " << c.getYCenter() << ")" << endl;

  cout << "Area: " << c.calculateArea() << endl;

  return 0;
}