///////////////////////////////////////////////////////////////////////////
// File: pentagon_test.cpp
// Purpose: A drawable which draws a pentagon
// Author: Yeswanth Kumar Reddy Nalamalapu
// Author: Pranathi Vadla
// Author: Rishika Vonguru
// Author: Adinarayana Reddy Madhire 
// Author : Vishnuvardhan Reddy Muri
// Author: Venkatreddy Kasireddy
// Author: Sainath Reddy Mosali
///////////////////////////////////////////////////////////////////////////

#include "canvas.h"
#include "drawable.h"
#include "pentagon.h"

int main(int argc, char *argv[]) {
  Canvas canvas; // Create a default canvas
  Pentagon *pentagon;
  pentagon = new Pentagon(300, 50, 100); // create a pentagon
  canvas.add(pentagon);
  canvas.render_loop();

  delete pentagon;
  return 0;
}
