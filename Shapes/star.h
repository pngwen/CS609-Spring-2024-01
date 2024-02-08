#ifndef STAR_H
#define STAR_H

#include "drawable.h"

class Star : public Drawable {
public:
    Star(int x, int y, int size);

    virtual void draw(Canvas* canvas) override;

private:
    int _x, _y; // Coordinates of the center of the star
    int _size;  // Size of the star
};

#endif // STAR_H
