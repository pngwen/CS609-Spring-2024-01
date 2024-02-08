// ///////////////////////////////////////////////////////////////////////////
// // File: octagon.cpp
// // Purpose: A drawable which draws an Octagon
// // Author: Kapil < kcheemarla1s@semo.edu >
// Author: Venu Mamidi < vmamidi1s@semo.edu >
// // Author: Yash Barot < ybarot1s@semo.edu >
// // Author: Sai Kumar Reddy< sboreddy1s@semo.edu
// // Author: Lokeswara Ravindra Rao kolli <lkolli1s@semo.edu>
// // Author: KrishnaSai Kavuri < saikavuri5566@gmail.com >
// ///////////////////////////////////////////////////////////////////////////
#include "octagon.h"
#include "canvas.h"
#include <cmath>

Octagon::Octagon(int x, int y, int size) : _x(x), _y(y), _size(size) {}

void Octagon::draw(Canvas *canvas) {
  const double PI = 3.14159265358979323846;
  const int vertices = 8;

  int centerX = _x + _size / 2;
  int centerY = _y + _size / 2;
  int R = _size / 2;

  for (int i = 0; i < vertices; ++i) {
    int x1 = centerX + R * std::cos(2 * PI * i / vertices);
    int y1 = centerY + R * std::sin(2 * PI * i / vertices);

    int x2 = centerX + R * std::cos(2 * PI * (i + 1) / vertices);
    int y2 = centerY + R * std::sin(2 * PI * (i + 1) / vertices);

    canvas->line(x1, y1, x2, y2);
  }
}