////////////////////////////////////////////////////////////////////////
// FILE: circle.h
// Purpose: Draw a circle (does this look right?)
// Authors: Jake Stinson
// Author: Durgaprasad Reddy Tiyyagura
// Author: Mekala Pallavi
// Author: Govindaiah Chowdary Pentela <gpentela1s@semo.edu>
// Author: Saqlain Abbas Ali Khan
//////////////////////////////////////////////////////////////////////////

#ifndef CIRCLE_H
#define CIRCLE_H

#include "drawable.h" // Include the Drawable base class

class Circle : public Drawable {
public:
  // Constructor
  Circle(int x, int y, int radius);

  // Draw the circle on the canvas
  virtual void
  draw(Canvas *canvas) override; // Use Canvas as per Drawable interface

protected:
  // Position and size
  int _x;
  int _y;
  int _radius;
};

#endif // CIRCLE_H
