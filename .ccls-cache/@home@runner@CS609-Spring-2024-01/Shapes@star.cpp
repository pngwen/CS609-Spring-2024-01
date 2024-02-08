// ///////////////////////////////////////////////////////////////////////////
// // File: star.cpp
// // Purpose: A drawable which draws an Octagon
// // Author: Avinash Abbina< aabbina1s@semo.edu >
// // Author: Harshith Sai Battula< habattula1s@semo.edu >
// // Author: Nagaraju Bommanaboina< nbommanaboina1s@semo.edu >
// // Author: Sravani Neerudu< sneerudu1s@semo.edu >
// // Author: Madhu Chandana< mmusipatla1s@semo.edu >
// // Author: Sreeja Yalla< syalla1@semo.edu >

////////////////////////////////////////////////////////////////////////////

#include "star.h"
#include "canvas.h"
#include "drawable.h"
#include <cmath>

Star::Star(int x, int y, int size) {
  this->_x = x;
  this->_y = y;
  this->_size = size;
}

void Star::draw(Canvas *canvas) {
  // Draw a 5-pointed star centered at (_x, _y) with size _size on the canvas
  const double pi = 3.14159265359;
  const double angleStep = pi / 5.0;
  const double outerRadius = _size / 2.0;
  const double innerRadius =
      outerRadius * 0.382; // Golden ratio for inner radius

  for (int i = 0; i < 5; ++i) {
    double outerX = _x + outerRadius * std::cos(i * 2 * angleStep - pi / 2.0);
    double outerY = _y + outerRadius * std::sin(i * 2 * angleStep - pi / 2.0);

    double innerX =
        _x + innerRadius * std::cos((i * 2 + 1) * angleStep - pi / 2.0);
    double innerY =
        _y + innerRadius * std::sin((i * 2 + 1) * angleStep - pi / 2.0);

    canvas->line(outerX, outerY, _x, _y);
    canvas->line(innerX, innerY, _x, _y);
  }
}
