#include "Circle.h"
#include <cmath>

Circle::Circle() {
  radius = 10;
  xCenter = 0;
  yCenter = 0;
}

Circle::Circle(int x, int y, int r) {
  xCenter = x;
  yCenter = y;
  radius = r;
}

void Circle::setRadius(int r) {
  radius = r;
}

int Circle::getRadius() {
  return radius; 
}

void Circle::setCenter(int x, int y) {
  xCenter = x;
  yCenter = y;
}

int Circle::getXCenter() { 
  return xCenter;
}

int Circle::getYCenter() {
  return yCenter;  
}

double Circle::calculateArea() {
  return M_PI * radius * radius;
}

double Circle::calculateCircumference() {
  return 2 * M_PI * radius; 
}