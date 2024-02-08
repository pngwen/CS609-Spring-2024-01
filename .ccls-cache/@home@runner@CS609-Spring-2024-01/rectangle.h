///////////////////////////////////////////////////////////////////////////
// File: hourglass.h
// Purpose: A drawable which draws an hour glass
// Author: Group 2
///////////////////////////////////////////////////////////////////////////
#include "drawable.h"

class Rectangle : public Drawable {
public:
  // Constructor
  // Parameters:
  //   x - x-coordinate of the upper left corner of the rectangle
  //   y - y-coordinate of the upper left corner of the rectangle
  //   w - width of the hour glass
  //   h - height of the hour glass
  Rectangle(int _x, int _y, int _w, int _h);

  // Draw the rectangle
  virtual void draw(Canvas* canvas);

private:
  int _x;
  int _y;
  int _w;
  int _h;
};