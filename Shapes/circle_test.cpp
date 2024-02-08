///////////////////////////////////////////////////////////////////////////
// Author:Jake Stinson
// Author: Saqlain Abbas Ali Khan
// Author: Govindaiah Chowdary Pentela <gpentela1s@semo.edu>
///////////////////////////////////////////////////////////////////////////

#include "canvas.h"
#include "circle.h"
#include <iostream>

int main() {
  // Create a canvas to draw on
  Canvas canvas("Test Canvas", 800, 600);

  // Create a circle
  Circle circle(400, 300, 100); // Center at (400, 300) with radius 100

  // Add the circle to the canvas
  canvas.add(&circle);

  // Assume Canvas class has a method to display or render
  canvas.render_loop();

  std::cout << "Circle test completed." << std::endl;

  return 0;
}
