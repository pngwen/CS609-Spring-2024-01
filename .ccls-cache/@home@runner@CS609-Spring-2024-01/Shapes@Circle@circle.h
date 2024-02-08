///////////////////////////////////////////////////////////////////////////
// File: circle.h
// Purpose: Class definition for a simple canvas that operates on drawables
// Author: dinesh sheelam < dsheelam1s.edu >
///////////////////////////////////////////////////////////////////////////
//In Canvas.h
#include <SDL.h>

class Canvas {
public:
    // Existing Canvas code

    // Draws a circle on the canvas 
    void circle(int cx, int cy, int r); 

private:
    // Existing Canvas private members
};

//In Canvas.cpp
#include "Canvas.h"

void Canvas::circle(int cx, int cy, int r) {

    //Set color to draw circle
    SDL_SetRenderDrawColor(_renderer, 255, 0, 0, 255);  

    //Draw circle
    int dx = r, dy = 0;
    int err = 0; 

    while (dx >= dy)
    {
        SDL_RenderDrawPoint(_renderer, cx + dx, cy + dy);
        SDL_RenderDrawPoint(_renderer, cx + dy, cy + dx);
        SDL_RenderDrawPoint(_renderer, cx - dy, cy + dx);
        SDL_RenderDrawPoint(_renderer, cx - dx, cy + dy);
        SDL_RenderDrawPoint(_renderer, cx - dx, cy - dy);
        SDL_RenderDrawPoint(_renderer, cx - dy, cy - dx);
        SDL_RenderDrawPoint(_renderer, cx + dy, cy - dx);
        SDL_RenderDrawPoint(_renderer, cx + dx, cy - dy);

        if (err <= 0)
        {
            dy += 1;
            err += 2*dy + 1;
        }
        if (err > 0) 
        {
            dx -= 1;   
            err -= 2*dx + 1;    
        }
    }
}