#include "canvas.h"
#include "drawable.h"
#include "star.h"


int main(int argc, char *argv[]) {
  Canvas canvas; // Create a default canvas

  Star *star = new Star(300, 200, 100);

  canvas.add(star);
  canvas.render_loop();

  return 0;
}
