// Author: KrishnaSai @saikavuri5566
// Date:   25/08/2021
#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <SDL.h>  

class Drawable {
public:
    // Constructor
    Drawable(int x, int y, int size);

    // Draw the pentagon on the canvas
    virtual void draw(SDL_Renderer* renderer) const;

protected:
    // Position and size
    int _x;
    int _y;
    int _size;
};

#endif
