// ///////////////////////////////////////////////////////////////////////////
// // File: octagon.cpp
// // Purpose: A drawable which draws an Octagon
// // Author: Kapil < kcheemarla1s@semo.edu >
// Author: Venu Mamidi < vmamidi1s@semo.edu >
///////////////////////////////////////////////////////////////////////////
//

#include "canvas.h"
#include "drawable.h"
#include "octagon.h"

int main(int argc, char *argv[]) {
  Canvas canvas; // Create a default canvas
  Octagon *octagon;
  octagon = new Octagon(300, 50, 100); // create an octagon
  canvas.add(octagon);
  canvas.render_loop();

  delete octagon;
  return 0;
}