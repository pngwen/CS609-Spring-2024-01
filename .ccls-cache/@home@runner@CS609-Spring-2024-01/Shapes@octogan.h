///////////////////////////////////////////////////////////////////////////
// File: hourglass.h
// Purpose: A drawable which draws an hour glass
// Author: Kapil < kcheemarla1s@semo.edu >
///////////////////////////////////////////////////////////////////////////
#include "drawable.h"

class Octagon: public Drawable {
public:
  Octagon(int _x, int _y, int l);
  virtual void draw(Canvas *canvas);

private:
  int _x;
  int _y;
  int _l;
};