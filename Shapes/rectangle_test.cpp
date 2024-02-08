///////////////////////////////////////////////////////////////////////////
// File: rectangle_test.cpp
// Author: Sainatha Reddy Siripireddy <ssiripireddy1s@semo.edu>
// Author: Viswa Gorripati <vgorripati2s@semo.edu>
// Author: Rakesh Vaddepally <rvaddepally1s@semo.edu>
// Author: Rohith Patel Kanchukatla <rkanchukatla1s@semo.edu>
// Author: Naveen Dondapati <ndondapati1s@semo.edu>

///////////////////////////////////////////////////////////////////////////

#include "canvas.h"
#include "rectangle.h"

int main(int argc, char *argv[]) {
  Canvas canvas; // Create a default canvas
  Rectangle *rect;

 
  rect = new Rectangle(300, 40, 40, 40); 

  
  canvas.add(rect);
  canvas.render_loop();

  
  delete rect;

  return 0;
}