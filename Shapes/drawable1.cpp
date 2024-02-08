//Author:KrishnaSai @saikavuri5566
// Drawable.cpp
#include "Drawable1.h"

Drawable1::Drawable1(int x, int y, int size) : _x(x), _y(y), _size(size) {}

void Drawable1::draw(SDL_Renderer* renderer) const {
    // Placeholder implementation for drawing an octagon
    // Customize this based on your needs
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);  // Set color to blue (you can customize this)

    // Example: Draw an octagon centered at (_x, _y)
    // This is just a simple example; you might want to use a more accurate algorithm for an octagon
    const double angleIncrement = 2 * 3.14159265359 / 8;
    double angle = 0.0;
    for (int i = 0; i < 8; ++i) {
        int x1 = _x + static_cast<int>(_size * cos(angle));
        int y1 = _y + static_cast<int>(_size * sin(angle));
        angle += angleIncrement;

        int x2 = _x + static_cast<int>(_size * cos(angle));
        int y2 = _y + static_cast<int>(_size * sin(angle));

        SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }

    // Reset color to default
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
