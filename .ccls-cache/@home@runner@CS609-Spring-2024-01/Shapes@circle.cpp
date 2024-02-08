////////////////////////////////////////////////////////////////////////
// FILE: circle.h
// Purpose: Draw a Circle
// Authors: Jake Stinson
// Author: Durgaprasad Reddy Tiyyagura
// Author: Govindaiah Chowdary Pentela <gpentela1s@semo.edu>
// Author: Saqlain Abbas Ali Khan

//////////////////////////////////////////////////////////////////////////
#include "circle.h"
#include "canvas.h"
#include <cmath>

Circle::Circle(int x, int y, int radius) {
  this->_x = x;
  this->_y = y;
  this->_radius = radius;
}

void Circle::draw(Canvas *canvas) {
  const double pi = 3.14159265359;
  const int segments = 360;
  const double angleStep = 2 * pi / segments;

  for (int i = 0; i < segments; ++i) {
    int startX = static_cast<int>(_x + _radius * std::cos(i * angleStep));
    int startY = static_cast<int>(_y + _radius * std::sin(i * angleStep));
    int endX = static_cast<int>(_x + _radius * std::cos((i + 1) * angleStep));
    int endY = static_cast<int>(_y + _radius * std::sin((i + 1) * angleStep));

    canvas->line(startX, startY, endX, endY);
  }
}