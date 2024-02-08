///////////////////////////////////////////////////////////////////////////
// File: circle.h
// Purpose: Class definition for a simple canvas that operates on drawables
// Author: dinesh sheelam < dshe.edu >
///////////////////////////////////////////////////////////////////////////
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
  private:
    int radius;
    int xCenter;
    int yCenter;

  public:
    Circle();
    Circle(int x, int y, int r);

    void setRadius(int r);
    int getRadius();

    void setCenter(int x, int y);
    int getXCenter();
    int getYCenter();

    double calculateArea();
    double calculateCircumference();
};

#endif