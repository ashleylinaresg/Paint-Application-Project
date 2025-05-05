#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape {
    float x;      // center x
    float y;      // center y
    float width;  // full base width
    float height; // full height
    float r;      // red   component
    float g;      // green component
    float b;      // blue  component

public:
    // default: center at (0,0), width=0.4, height=0.4, color=black
    Triangle();

    // specify center, color; width/height stay at their default values
    Triangle(float x, float y, float r, float g, float b);

    // draw an isosceles triangle with its base horizontal
    void draw() override;
};

#endif // TRIANGLE_H
