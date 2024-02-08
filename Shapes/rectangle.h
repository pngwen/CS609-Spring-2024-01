///////////////////////////////////////////////////////////////////////////
// File: rectangle.h
// Purpose: A drawable which draws a rectangle
// Author: Sainatha Reddy Siripireddy <ssiripireddy1s@semo.edu>
// Author: Viswa Gorripati <vgorripati2s@semo.edu>
//Author: Rakesh Vaddepally <rvaddepally2s@semo.edu>
// Author: Rohith Patel Kanchukatla <rkanchukatla1s@semo.edu>
// Author: Naveen Dondapati <ndondapati1s@semo.edu>
// Author: yashasri Boppana <yboppana1s@semo.edu>

///////////////////////////////////////////////////////////////////////////

#ifndef rectangle_h
#define rectangle_h
#include "drawable.h"
class Rectangle : public Drawable {
public:
  // Constructor
  // Parameters:
  //   x - x-coordinate of the upper left corner of the rectangle
  //   y - y-coordinate of the upper left corner of the rectangle
  //   w - width of the rectangle
  //   h - height of the rectangle
  Rectangle(int _x, int _y, int _w, int _h);

  // Draw the rectangle
  virtual void draw(Canvas *canvas);

private:
  int _x;
  int _y;
  int _w;
  int _h;
};

#endif