///////////////////////////////////////////////////////////////////////////
// File: pentagon.cpp
// Purpose: A drawable which draws a Pentagon 
// Author: Yeswanth Kumar Reddy Nalamalapu
// Auther: Pranathi Vadla
// Auther: Rishika Vonguru
// Auther: Adinarayana Reddy Madhire 
// Auther : Vishnuvardhan Reddy Muri
// Auther: Venkatreddy Kasireddy
// Auther: Sainath Reddy Mosali
/////////////////////////////////////////////////////////////////////////
// Pentagon implementation
#include "pentagon.h"
#include "canvas.h"
#include "drawable.h"

Pentagon::Pentagon(int _x, int _y, int _size) {
  this->_x = _x;
  this->_y = _y;
  this->_size = _size;
}

void Pentagon::draw(Canvas* canvas) {
  int x1 = _x;
  int y1 = _y;

  int x2 = _x + _size;
  int y2 = _y;

  int x3 = _x + _size;
  int y3 = _y + _size;

  int x4 = _x + (_size /2);
  int y4 = _y + (_size * 1.5);

  int x5 = _x - (_size /2);
  int y5 = _y + (_size * 1.5);

  
  canvas ->line(x1, y1, x2, y2);
  canvas ->line(x2, y2, x3, y3);
  canvas ->line(x3, y3, x4, y4);
  canvas ->line(x4, y4, x5, y5);
  canvas ->line(x5, y5, x1, y1);

}


