///////////////////////////////////////////////////////////////////////////
// File: pentagon.h
// Purpose: A drawable which draws a pentagon
// Author: Yeswanth Kumar Reddy Nalamalapu
// Author: Pranathi Vadla
// Author: Rishika Vonguru
// Author: Adinarayana Reddy Madhire 
// Author : Vishnuvardhan Reddy Muri
// Author: Venkatreddy Kasireddy
// Author: Sainath Reddy Mosali
///////////////////////////////////////////////////////////////////////////
#define PENTAGON_H
#ifndef PENTAGON_H
#include "canvas.h"

class Pentagon : public Drawable {
public:
  Pentagon(int _x, int _y, int _size);

  void draw(Canvas* canvas);

private:
  int _x, _y, _size;
};

#endif // PENTAGON_H